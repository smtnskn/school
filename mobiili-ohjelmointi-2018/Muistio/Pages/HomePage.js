var Context = require("Modules/Context");

function goToEntry(arg) {
	var entry = arg.data;
	router.push("editEntry", entry);
}

function goToAddNote() {
	router.push("addEntry");
}

module.exports = {
	entries: Context.entries,

	goToEntry:		goToEntry,
	goToAddNote:	goToAddNote
};

