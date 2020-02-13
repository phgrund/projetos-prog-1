function mostrarJogar() {
	document.getElementById("tutorial").style.display = "none";
	document.getElementById("jogar").style.display = "";
	document.getElementById("liTutorial").style.backgroundColor = "#EEE";
	document.getElementById("liJogar").style.backgroundColor = "#DDD";
}
function mostrarTutorial() {
	document.getElementById("tutorial").style.display = "";
	document.getElementById("jogar").style.display = "none";
	document.getElementById("liTutorial").style.backgroundColor = "#DDD";
	document.getElementById("liJogar").style.backgroundColor = "#EEE";
}
