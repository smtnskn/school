var fingerPrint = require('FingerPrint');

function authenticate() {
	console.log("Authenticating...");

	fingerPrint.auth("Use your fingerprint for authentication",
		function (success, reason) {
			if (success) {
				console.log("Authentication successful!");
				goToHomePage();
			}
			console.log("s: " + success + "("+ reason +")");
		});

	goToHomePage();
}

function goToHomePage() {
	// ".goto" instead of ".push" to prevent going back to the splash screen
	router.goto("home");
}

module.exports = {
	authenticate:	authenticate,
	goToHomePage:	goToHomePage
}