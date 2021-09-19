var Observable = require("FuseJS/Observable");
var Backend = require("./Backend");

var entries = Observable();

function formatTime(timeString) {
	return (timeString.length == 1 ? "0" + timeString : timeString);
}

function getDate(date) {
	var day 	= formatTime( date.getDate().toString() );
	var month 	= formatTime( (date.getMonth() + 1).toString() );
	var year 	= date.getFullYear().toString();

	return (day + "." + month + "." + year);
}

function getTime(date) {
	var hour 	= formatTime( date.getHours().toString() );
	var minute 	= formatTime( date.getMinutes().toString() );

	return (hour + ":" + minute);
}

function isEmpty(obj) {
    for (var key in obj) {
        if (obj.hasOwnProperty(key)) {
            return false;
        }
    }

    return true;
}

Backend.getEntries()
	.then(function(newEntries) {
		// console.log(JSON.stringify(newEntries));

		entries.replaceAll(newEntries);
	})
	.catch(function(error) {
		console.log("Couldn't get entries: " + error);
	});

function insertEntry(note) {
	var d = new Date();
	var date = getDate(d);
	var time = getTime(d);

	Backend.insertEntry(date, time, note)
		.then(function(id) {
			console.log(id);
			var note_id = parseInt(id);
			entries.insertAt(0, { note_id, date, time, note });
		})
		.catch(function(error) {
			console.log("Couldn't insert entry: " + error)
		});
}

function deleteEntry(id) {
	Backend.deleteEntry(id);

	for (var i = 0; i < entries.length; i++) {
		if (entries.getAt(i).note_id == id) {
			entries.removeAt(i);

			break;
		}
	}
}

function updateEntry(id, note) {
	deleteEntry(id);
	insertEntry(note);
}

module.exports = {
	entries: entries,

	insertEntry: insertEntry,
	deleteEntry: deleteEntry,
	updateEntry: updateEntry
}