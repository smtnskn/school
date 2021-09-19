var Context = require("Modules/Context");

var entry = this.Parameter;

var date = entry.map(function(x) { return x.date; });
var time = entry.map(function(x) { return x.time; });
var note = entry.map(function(x) { return x.note; });

function cancel() {
	// Refresh entry value to reset dependent Observables' values
	entry.value = entry.value;

	router.goBack();
}

function updateEntry() {
	Context.updateEntry(entry.value.note_id, note.value);

	router.goBack();
}

function deleteEntry() {
	Context.deleteEntry(entry.value.note_id);

	router.goBack();
}

module.exports = {
	date: date,
	time: time,
	note: note,

	cancel:	cancel,
	update:	updateEntry,
	delete: deleteEntry
};

