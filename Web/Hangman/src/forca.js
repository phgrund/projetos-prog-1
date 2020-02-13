var palavras = new Array(quantidadeClasses);
var i;
var quantidadeClasses = 3;
for(i = 0; i < quantidadeClasses; i++) {
	palavras[i] = new Array ();
}
/*
	palavras[0] = Veículos
	palavras[1] = Animais
	palavras[2] = Cor
*/

//Palavras Veículos
	palavras[0][0] = "CARRO";
	palavras[0][1] = "BARCO";
	palavras[0][2] = "MOTO";
	palavras[0][3] = "ONIBUS"
	palavras[0][4] = "AVIAO";
	palavras[0][5] = "TREM";

//Palavras Animais
	palavras[1][0] = "CACHORRO";
	palavras[1][1] = "GATO";
	palavras[1][2] = "CAVALO";
	palavras[1][3] = "CAMELO";
	palavras[1][4] = "GIRAFA";
	palavras[1][5] = "GOLFINHO";
	palavras[1][6] = "MACACO";
	palavras[1][7] = "LOBO";
	palavras[1][8] = "JAGUAR";
	palavras[1][9] = "CORVO";
	palavras[1][10] = "CASTOR";
	palavras[1][11] = "TEXUGO";
	palavras[1][12] = "FUINHA";

//Palavras Cor

	palavras[2][0] = "BRANCO";
	palavras[2][1] = "PRETO";
	palavras[2][2] = "AMARELO";
	palavras[2][3] = "VERMELHO";
	palavras[2][4] = "VERDE";
	palavras[2][5] = "AZUL";
	palavras[2][6] = "CINZA";
	palavras[2][7] = "ROSA";

var lastResult;
var erros;
var jogada = 0;
var tentativas = 6;
var tentativasRestantes = 6;
var letra;
var checar;
var fimJogo;
var maxClasse;
var randomClasse;
var maxPalavras;
var randomPalavra;
var palavra;
var acertos;
var palavraLength;
var letrasJogadas = "";

window.onload = function carregamento() {
	inicioPartida();
}

function inicioPartida() {
	erros = 0;
	jogada = 0;
	acertos = 0;
	fimJogo = false;
	maxClasse = (palavras.length) - 1;
	randomClasse = Math.floor(Math.random() * (maxClasse + 1));
	maxPalavras = (palavras[randomClasse].length) - 1;
	randomPalavra = Math.floor(Math.random() * (maxPalavras + 1));
	palavra = palavras[randomClasse][randomPalavra];
	palavraLength = palavra.length;
	document.getElementById("teclado").style.display = ""
	document.getElementById("jogarNovamente").style.display = "none";
	for(i = 0; i < palavraLength; i++) {
		document.getElementById("casinha" + i).style.display = "";
	}
	var acharLetra;
	tentativasRestantes = tentativas - erros;
}
function forca(letra) {
	document.getElementById(letra).disabled = true;
	document.getElementById(letra).style.color = "#FFF";
	document.getElementById(letra).style.borderColor = "#000";
	document.getElementById("placar").style.display = "";
	if(jogada == 0)
		document.getElementById("avisoTeclado").style.display = "none";
	if(palavra.indexOf(letra) > -1){
		document.getElementById(letra).style.backgroundColor = "#0F0";
		var lastResult = "acertou";
		document.getElementById("placar").style.color = "#0F0";
		document.getElementById("lastLetra").innerHTML = letra;
		document.getElementById("lastResult").innerHTML = "acertou";
		if(jogada > 0)
				letrasJogadas += ", ";
			letrasJogadas += letra;
		document.getElementById("letrasJogadas").innerHTML = letrasJogadas;
		tentativasRestantes = tentativas - erros;
		document.getElementById("tentativasRestantes").innerHTML = tentativasRestantes;
		acertos++;
		for(i = 0; i < palavraLength; i++) {
			acharLetra = palavra.indexOf(letra);
			if(acharLetra > -1) {
				document.getElementById("casinha" + acharLetra).innerHTML = letra;
				palavra = palavra.replace(letra, '0');
			}
		}
		checar = /^0+$/.test(palavra);
		if(checar == true) {
			document.getElementById("placar").innerHTML = "Você venceu a partida.<br>Caso queira jogar novamente, clique no botão acima para jogar novamente.";
			fimJogo = true;
		}
	}
	else{
		erros++;
		tentativasRestantes = tentativas - erros;
		document.getElementById(letra).style.backgroundColor = "#F00";
		document.getElementById("placar").style.color = "#F00";
		document.getElementById("lastLetra").innerHTML = letra;
		document.getElementById("lastResult").innerHTML = "errou";
		if(erros == tentativas) {
			document.getElementById("img").src = "src/boneco/6.png";
			document.getElementById("placar").innerHTML = "Você perdeu o jogo. A palavra correta era " + palavras[randomClasse][randomPalavra] + ".";
			fimJogo = true;
			letrasJogadas += ", " + letra + ".";
			document.getElementById("letrasJogadas").innerHTML = letrasJogadas;
		}
		else {
			document.getElementById("img").src = "src/boneco/" + erros + ".png";
			if(jogada > 0)
				letrasJogadas += ", ";
			letrasJogadas += letra;
			document.getElementById("letrasJogadas").innerHTML = letrasJogadas;
			document.getElementById("tentativasRestantes").innerHTML = tentativasRestantes;
		}
	}
	if(fimJogo == true) {
		finalizarPartida();
	}
	jogada++;
}