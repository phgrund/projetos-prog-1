function mostrarJogar() {
	document.getElementById("tutorial").style.display = "none";
	document.getElementById("jogar").style.display = "";;
	document.getElementById("liTutorial").style.backgroundColor = "#EEE";
	document.getElementById("liJogar").style.backgroundColor = "#DDD";
}
function mostrarTutorial() {
	document.getElementById("tutorial").style.display = "";
	document.getElementById("jogar").style.display = "none";
	document.getElementById("liTutorial").style.backgroundColor = "#DDD";
	document.getElementById("liJogar").style.backgroundColor = "#EEE";
	fecharAviso();
}
var dica;
function gerarDica(dica) {
	if(dica == 1) {
		var classe;
		switch (randomClasse) {
			case 0:
			classe = "é um veículo";
			break;
			case 1:
			classe = "é um animal";
			break;
			case 2:
			classe = "é uma cor";
			break;
		}
		document.getElementById("mostrarDica1").innerHTML = classe;
	}
	else if(dica == 2) {
		var primeiraLetra = palavras[randomClasse][randomPalavra].charAt(0);
		document.getElementById("mostrarDica2").innerHTML = "Primeira letra: '" + primeiraLetra + "'";
	}
}
function finalizarPartida() {
	document.getElementById("teclado").style.display = "none"
	document.getElementById("jogarNovamente").style.display = "";
	document.getElementById("dicaDiv").style.display = "none";
}