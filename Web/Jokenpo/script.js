var pontuacaoPlayer = 0, pontuacaoIA = 0, winner, selecaoPlayer, selecaoIA;
function selecao(q) {
    selecaoPlayer = q;
}
function jogarIA() {
    selecaoIA = Math.floor(Math.random() * 3);
    return selecaoIA;
}
function jogar() {
    jogarIA();
    verificarWinner();
}
function verificarWinner() {
    // Pedra = 0
    // Papel = 1
    // Tesoura = 2
    if(selecaoPlayer == 0 && selecaoIA == 2) {
        pontuacaoPlayer++;
        winner = "Player";
        alert("Você jogou pedra e a IA tesoura, você ganhou");
    }
    else if(selecaoPlayer == 1 && selecaoIA == 0) {
        pontuacaoPlayer++;
        winner = "Player";
        alert("Você jogou papel e a IA pedra, você ganhou");
    }
    else if(selecaoPlayer == 2 && selecaoIA == 1) {
        pontuacaoPlayer++;
        winner = "Player";
        alert("Você jogou tesoura e a IA papel, você ganhou");
    }
    else if(selecaoPlayer == 2 && selecaoIA == 0) {
        pontuacaoIA++;
        winner = "IA";
        alert("Você jogou tesoura e a IA pedra, você perdeu");
    }
    else if(selecaoPlayer == 0 && selecaoIA == 1) {
        pontuacaoIA++;
        winner = "IA";
        alert("Você jogou pedra e a IA papel, você perdeu");
    }
    else if(selecaoPlayer == 1 && selecaoIA == 2) {
        pontuacaoIA++;
        winner = "IA";
        alert("Você jogou papel e a IA tesoura, você perdeu");
    }
    else {
        alert("Empate");
    }
    document.getElementById("lastWinner").innerHTML = winner;
    document.getElementById("placarPlayer").innerHTML = pontuacaoPlayer;
    document.getElementById("placarIA").innerHTML = pontuacaoIA;
}