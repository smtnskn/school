// var entries = [
// 	{
// 		id: 0,
// 		date: getDate(),
// 		time: getTime(),
// 		note: "Note 1..."
// 	}, {
// 		id: 1,
// 		date: "12.12.2012",
// 		time: "03:45",
// 		note: "Note 2."
// 	}, {
// 		id: 2,
// 		date: "13.12.2012",
// 		time: "04:45",
// 		note: "Note 3!"
// 	}, {
// 		id: 3,
// 		date: "14.12.2012",
// 		time: "05:45",
// 		note: "Note 4!!"
// 	}
// ]

var entries = [];

var ROOT_URL = "http://127.0.0.1:8080/";

function getEntries() {
	return new Promise(function(resolve, reject) {
		fetch(ROOT_URL + "selectNotes.php")
			.then(function(result) {
				entries = result.json();
				resolve(entries);
			})
			.catch(function(error) {
				reject(error);
			})
	});
}

function deleteEntry(id) {
	fetch(ROOT_URL + "deleteNote.php?id=" + id);
}

function insertEntry(date, time, note) {
	return new Promise(function(resolve, reject) {
		fetch(ROOT_URL + "insertNote.php?date=" + date + "&time=" + time + "&note=" + note)
			.then(function(result) {
				id = result.text();
				resolve(id);
			})
			.catch(function(error) {
				reject(error);
			})
	});
}

module.exports = {
	getEntries:		getEntries,
	deleteEntry:	deleteEntry,
	insertEntry:	insertEntry
};