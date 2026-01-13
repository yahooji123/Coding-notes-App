const mongoose = require('mongoose');

const NoteSchema = new mongoose.Schema({
  title: {
    type: String,
    required: true
  },
  description: { // Short description or documentary text
    type: String,
    required: true
  },
  category: {
    type: String,
    required: true,
    default: 'General'
  },
  content: { // Full content/code snippet if needed
    type: String,
    required: false
  },
  createdAt: {
    type: Date,
    default: Date.now
  }
});

module.exports = mongoose.model('Note', NoteSchema);
