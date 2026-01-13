document.addEventListener('DOMContentLoaded', () => {
    // State
    let allNotes = [];
    let currentTheme = localStorage.getItem('theme') || 'light';
    let currentFontSize = parseInt(localStorage.getItem('fontSize')) || 14;

    // Elements
    const sidebarContent = document.getElementById('sidebarContent');
    const searchInput = document.getElementById('searchInput');
    const contentView = document.getElementById('contentView');
    const welcomeScreen = document.getElementById('welcomeScreen');
    const pageTitle = document.getElementById('pageTitle');
    const codeBlock = document.getElementById('codeBlock');
    const breadcrumbs = document.getElementById('breadcrumbs');
    const themeToggle = document.getElementById('themeToggle');
    const sidebar = document.getElementById('sidebar');
    const toggleSidebarBtn = document.getElementById('toggleSidebar');

    // Init
    initTheme();
    initFontSize();
    fetchNotes();

    // Event Listeners
    if(themeToggle) themeToggle.addEventListener('click', toggleTheme);
    if(searchInput) searchInput.addEventListener('input', handleSearch);
    if(toggleSidebarBtn) toggleSidebarBtn.addEventListener('click', () => {
        sidebar.classList.toggle('open');
    });

    document.getElementById('fontIncrease').addEventListener('click', () => changeFontSize(2));
    document.getElementById('fontDecrease').addEventListener('click', () => changeFontSize(-2));
    
    document.getElementById('copyBtn').addEventListener('click', () => {
        const code = codeBlock.innerText;
        navigator.clipboard.writeText(code).then(() => {
            const btn = document.getElementById('copyBtn');
            const originalText = btn.innerText;
            btn.innerText = 'Copied!';
            setTimeout(() => btn.innerText = originalText, 2000);
        });
    });

    // API Functions
    async function fetchNotes() {
        try {
            const response = await fetch('/api/notes');
            if(!response.ok) throw new Error('Network error');
            allNotes = await response.json();
            renderSidebar(allNotes);
        } catch (error) {
            console.error('Error fetching notes:', error);
            sidebarContent.innerHTML = '<p style="padding: 20px; color: red;">Failed to load content.</p>';
        }
    }

    async function fetchNoteContent(id) {
        try {
            // Show loading or simplified state
            pageTitle.innerText = "Loading...";
            
            const response = await fetch(`/api/notes/${id}`);
            const note = await response.json();
            
            renderContent(note);
            
            // On mobile, close sidebar after selection
            if(window.innerWidth <= 768) {
                sidebar.classList.remove('open');
            }
        } catch (error) {
            console.error('Error fetching note details:', error);
        }
    }

    // Render Functions
    function renderSidebar(notes) {
        sidebarContent.innerHTML = '';
        
        // Group by category
        const grouped = notes.reduce((acc, note) => {
            const cat = note.category || 'General';
            if(!acc[cat]) acc[cat] = [];
            acc[cat].push(note);
            return acc;
        }, {});

        // Sort categories
        const categories = Object.keys(grouped).sort();

        categories.forEach((cat, index) => {
            const chapterItem = document.createElement('div');
            chapterItem.className = 'chapter-item';
            
            // Chapter Title
            const titleDiv = document.createElement('div');
            titleDiv.className = 'chapter-title';
            titleDiv.innerHTML = `${cat} <span>${grouped[cat].length}</span>`;
            titleDiv.onclick = () => chapterItem.classList.toggle('active');
            
            // File List
            const fileList = document.createElement('div');
            fileList.className = 'file-list';
            
            grouped[cat].forEach(note => {
                const fileItem = document.createElement('div');
                fileItem.className = 'file-item';
                fileItem.innerText = note.title;
                fileItem.onclick = (e) => {
                    e.stopPropagation();
                    // Remove selected class from all
                    document.querySelectorAll('.file-item').forEach(el => el.classList.remove('selected'));
                    fileItem.classList.add('selected');
                    fetchNoteContent(note._id);
                };
                fileList.appendChild(fileItem);
            });

            chapterItem.appendChild(titleDiv);
            chapterItem.appendChild(fileList);
            sidebarContent.appendChild(chapterItem);
        });
    }

    function renderContent(note) {
        welcomeScreen.style.display = 'none';
        contentView.style.display = 'block';
        
        pageTitle.innerText = note.title;
        breadcrumbs.innerText = `Home > ${note.category || 'General'} > ${note.title}`;
        
        // Populate code
        codeBlock.textContent = note.content || '// No content available';
        codeBlock.className = 'language-javascript'; // Default, or detect if possible
        
        // Using Highlight.js
        hljs.highlightElement(codeBlock);
        
        // If description exists, create/update a description element
        let descEl = document.getElementById('noteDescription');
        if(!descEl) {
            descEl = document.createElement('div');
            descEl.id = 'noteDescription';
            descEl.style.marginBottom = '20px';
            descEl.style.lineHeight = '1.6';
            descEl.style.color = 'var(--text-secondary)';
            contentView.insertBefore(descEl, document.querySelector('.code-section'));
        }
        descEl.innerText = note.description || '';
    }

    function handleSearch(e) {
        const term = e.target.value.toLowerCase();
        const filtered = allNotes.filter(note => 
            note.title.toLowerCase().includes(term) || 
            (note.category && note.category.toLowerCase().includes(term))
        );
        renderSidebar(filtered);
        // Automatically expand all if searching
        if(term.length > 0) {
            document.querySelectorAll('.chapter-item').forEach(el => el.classList.add('active'));
        }
    }

    // Theme & Font Logic
    function toggleTheme() {
        const newTheme = document.documentElement.getAttribute('data-theme') === 'dark' ? 'light' : 'dark';
        document.documentElement.setAttribute('data-theme', newTheme);
        localStorage.setItem('theme', newTheme);
        updateThemeIcon(newTheme);
    }

    function initTheme() {
        document.documentElement.setAttribute('data-theme', currentTheme);
        updateThemeIcon(currentTheme);
    }

    function updateThemeIcon(theme) {
        themeToggle.innerText = theme === 'dark' ? '☀️' : '🌙';
    }

    function changeFontSize(delta) {
        const code = document.querySelector('code');
        if(!code) return;
        
        let current = parseInt(getComputedStyle(code).fontSize);
        let valid = current + delta;
        if(valid < 10) valid = 10;
        if(valid > 24) valid = 24;
        
        document.documentElement.style.setProperty('--code-font-size', valid + 'px');
        localStorage.setItem('fontSize', valid);
    }

    function initFontSize() {
        document.documentElement.style.setProperty('--code-font-size', currentFontSize + 'px');
    }
});
