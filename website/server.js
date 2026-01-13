const express = require('express');
const mongoose = require('mongoose');
const session = require('express-session');
const passport = require('passport');
const LocalStrategy = require('passport-local').Strategy;
const bcrypt = require('bcryptjs');
const flash = require('connect-flash');
const methodOverride = require('method-override');
const path = require('path');
const dotenv = require('dotenv');
const MongoStore = require('connect-mongo');
const helmet = require('helmet');
const compression = require('compression');

dotenv.config();

const User = require('./models/User');
const Note = require('./models/Note');
const Setting = require('./models/Setting');

const app = express();

// DB Config
const db = process.env.MONGO_URI || 'mongodb://127.0.0.1:27017/codingNotesDB';
mongoose.connect(db)
  .then(() => console.log('MongoDB Connected...'))
  .catch(err => console.log(err));

// Passport Config
passport.use(new LocalStrategy(async (username, password, done) => {
  try {
    const user = await User.findOne({ username: username });
    if (!user) {
      return done(null, false, { message: 'That username is not registered' });
    }
    const isMatch = await bcrypt.compare(password, user.password);
    if (isMatch) {
      return done(null, user);
    } else {
      return done(null, false, { message: 'Password incorrect' });
    }
  } catch (err) {
    return done(err);
  }
}));

passport.serializeUser((user, done) => {
  done(null, user.id);
});

passport.deserializeUser(async (id, done) => {
  try {
    const user = await User.findById(id);
    done(null, user);
  } catch (err) {
    done(err, null);
  }
});

// Middleware
app.use(helmet({
  contentSecurityPolicy: false, // Disabling CSP for simplicity with inline scripts/styles if any
}));
app.use(compression());
app.use(express.urlencoded({ extended: false }));
app.use(express.json());
app.use(express.static(path.join(__dirname, 'public')));
app.use(methodOverride('_method'));
app.use(session({
  secret: process.env.SESSION_SECRET || 'secret',
  resave: false,
  saveUninitialized: false,
  store: MongoStore.create({ 
    mongoUrl: process.env.MONGO_URI || 'mongodb://127.0.0.1:27017/codingNotesDB',
    collectionName: 'sessions'
  }),
  cookie: {
    maxAge: 1000 * 60 * 60 * 24 // 1 day
  }
}));
app.use(passport.initialize());
app.use(passport.session());
app.use(flash());

// Global Variables
app.use(async (req, res, next) => {
  res.locals.success_msg = req.flash('success_msg');
  res.locals.error_msg = req.flash('error_msg');
  res.locals.error = req.flash('error');
  res.locals.user = req.user || null;
  
  // Get Registration Status
  let setting = await Setting.findOne();
  if (!setting) {
    setting = new Setting({ registrationEnabled: true });
    await setting.save();
  }
  res.locals.registrationEnabled = setting.registrationEnabled;
  next();
});

// View Engine
app.set('view engine', 'ejs');

// --- ROUTES ---

// API: Get all notes (for sidebar)
app.get('/api/notes', async (req, res) => {
  try {
    const notes = await Note.find().select('title category _id');
    res.json(notes);
  } catch (err) {
    res.status(500).json({ error: 'Failed to fetch notes' });
  }
});

// API: Get single note content
app.get('/api/notes/:id', async (req, res) => {
  try {
    const note = await Note.findById(req.params.id);
    res.json(note);
  } catch (err) {
    res.status(500).json({ error: 'Failed to fetch note' });
  }
});

// Helper: Ensure Authenticated
function ensureAuthenticated(req, res, next) {
  if (req.isAuthenticated()) {
    return next();
  }
  req.flash('error_msg', 'Please log in to view that resource');
  res.redirect('/login');
}

// Helper: Ensure Super Admin
function ensureSuperAdmin(req, res, next) {
  if (req.isAuthenticated() && req.user.role === 'superadmin') {
    return next();
  }
  req.flash('error_msg', 'Not Authorized');
  res.redirect('/dashboard');
}

// Home Page (Public - Documentary Style)
app.get('/', async (req, res) => {
  try {
    const allNotes = await Note.find().sort({ category: 1, createdAt: 1 });
    
    // Get all unique categories for the sidebar (sorted)
    const allCategories = [...new Set(allNotes.map(note => note.category))].sort();

    // Determine which notes to show based on query
    let notesToShow = allNotes;
    const selectedCategory = req.query.category;

    if (selectedCategory) {
      notesToShow = allNotes.filter(note => note.category === selectedCategory);
    }

    // Group filtered notes for display
    const groupedNotes = notesToShow.reduce((acc, note) => {
      (acc[note.category] = acc[note.category] || []).push(note);
      return acc;
    }, {});
    
    res.render('index', { 
        groupedNotes, 
        allCategories, 
        selectedCategory 
    });
  } catch (err) {
    console.error(err);
    res.render('index', { 
        groupedNotes: {}, 
        allCategories: [], 
        selectedCategory: null 
    });
  }
});

// View Single Note (Public)
app.get('/note/:id', async (req, res) => {
  try {
    const note = await Note.findById(req.params.id);
    res.render('view-note', { note });
  } catch (err) {
    res.redirect('/');
  }
});

// Login Page
app.get('/login', (req, res) => res.render('login'));

// Login Handle
app.post('/login', (req, res, next) => {
  passport.authenticate('local', {
    successRedirect: '/dashboard',
    failureRedirect: '/login',
    failureFlash: true
  })(req, res, next);
});

// Logout Handle
app.get('/logout', (req, res, next) => {
  req.logout((err) => {
    if (err) { return next(err); }
    req.flash('success_msg', 'You are logged out');
    res.redirect('/login');
  });
});

// Register Page
app.get('/register', async (req, res) => {
  const usersCount = await User.countDocuments();
  if (usersCount > 0 && !res.locals.registrationEnabled) {
    req.flash('error_msg', 'Registration is currently disabled by the administrator.');
    return res.redirect('/login');
  }
  res.render('register');
});

// Register Handle
app.post('/register', async (req, res) => {
  const { username, password } = req.body;
  let errors = [];

  if (!username || !password) {
    errors.push({ msg: 'Please enter all fields' });
  }

  if (errors.length > 0) {
    res.render('register', { errors, username, password });
  } else {
    try {
      const userExists = await User.findOne({ username: username });
      if (userExists) {
        errors.push({ msg: 'Username is already registered' });
        return res.render('register', { errors, username, password });
      }

      // Logic for Super Admin
      const usersCount = await User.countDocuments();
      let role = 'admin';
      
      if (usersCount === 0) {
        role = 'superadmin';
      } else {
        // If not first user, check if registration is allowed
        const setting = await Setting.findOne();
        if (!setting || !setting.registrationEnabled) {
             req.flash('error_msg', 'Registration is closed.');
             return res.redirect('/login');
        }
      }

      const newUser = new User({ username, password, role });

      // Hash Password
      bcrypt.genSalt(10, (err, salt) => {
        bcrypt.hash(newUser.password, salt, async (err, hash) => {
          if (err) throw err;
          newUser.password = hash;
          await newUser.save();
          req.flash('success_msg', 'You are now registered and can log in');
          res.redirect('/login');
        });
      });
    } catch (err) {
      console.log(err);
    }
  }
});

// Dashboard (Admin Only)
app.get('/dashboard', ensureAuthenticated, async (req, res) => {
  const notes = await Note.find().sort({ createdAt: -1 });
  const users = await User.find(); // For superadmin to see
  res.render('dashboard', { notes, users, user: req.user });
});

// Add Note Page
app.get('/add-note', ensureAuthenticated, (req, res) => res.render('add-note'));

// Add Note Handle
app.post('/add-note', ensureAuthenticated, async (req, res) => {
  const { title, category, description, content } = req.body;
  const newNote = new Note({ title, category, description, content });
  await newNote.save();
  req.flash('success_msg', 'Note Added Successfully');
  res.redirect('/dashboard');
});

// Delete Note
app.delete('/note/:id', ensureAuthenticated, async (req, res) => {
  await Note.findByIdAndDelete(req.params.id);
  req.flash('success_msg', 'Note Deleted');
  res.redirect('/dashboard');
});

// Toggle Registration (Super Admin Only)
app.post('/toggle-registration', ensureSuperAdmin, async (req, res) => {
  let setting = await Setting.findOne();
  if (!setting) {
    setting = new Setting({ registrationEnabled: true });
  }
  setting.registrationEnabled = !setting.registrationEnabled;
  await setting.save();
  req.flash('success_msg', `Registration is now ${setting.registrationEnabled ? 'Enabled' : 'Disabled'}`);
  res.redirect('/dashboard');
});

const PORT = process.env.PORT || 5000;
app.listen(PORT, () => console.log(`Server started on port ${PORT}`));
