const mongoose = require('mongoose');

const SettingSchema = new mongoose.Schema({
  registrationEnabled: {
    type: Boolean,
    default: true // Initially true, or false, logic will handle this
  }
});

module.exports = mongoose.model('Setting', SettingSchema);
