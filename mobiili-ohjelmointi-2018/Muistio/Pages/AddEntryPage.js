var Context = require("Modules/Context");
var Observable = require ('FuseJS/Observable');

var note = Observable("");

function cancel() {
	note.value = "";

	router.goBack();
}

function insertEntry() {
	if (note.value.length != 0) {
		Context.insertEntry(note.value);
		note.value = "";
	}

	router.goBack();
}

module.exports = {
	note: 	note,

	cancel:	cancel,
	save: 	insertEntry,
};

