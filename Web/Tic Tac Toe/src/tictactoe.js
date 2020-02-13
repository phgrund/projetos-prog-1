var i;
var opcaoJogar;
var jogador1;
var jogador2;
var pontosPlayer1 = 0;
var pontosPlayer2 = 0;
var flag = 0;
var q;
var posicaoOcupada;
var v = new Array(9);
var vez = Math.floor(Math.random() * (2 - 1 + 1) + 1);
var jogadas = 0;
var fimJogo = false;
var vencedor;
var empates = 0;
var mostrarAlert;
var randomIA;

function escolhaModo() {
    opcaoJogar = document.getElementById("escolhaModo").value;
    document.getElementById("selecaoModo").style.display = "none";
    if(opcaoJogar == 1) {           // Player x IA
        document.getElementById("escolhaSingle").style.display = "";
    }
    else if(opcaoJogar == 2) {      // Player x Player
        document.getElementById("escolhaDuo").style.display = "";
    }
    if(document.getElementById("mostrarAlert").checked)
        mostrarAlert = true;
    else
        mostrarAlert = false;
}
function escolhaNome() {
    if(opcaoJogar == 1) {
        jogador1 = document.getElementById("nomePlayer").value;
        jogador2 = "IA";
        if(jogador1 === '')
            alert("Nome inválido, tente novamente.");
        else {
            document.getElementById("escolhaSingle").style.display = "none";
            flag = 1;
        }
    }
    else if(opcaoJogar == 2) {
        jogador1 = document.getElementById("nomePlayer1").value;
        jogador2 = document.getElementById("nomePlayer2").value;
        if(jogador1 === '' || jogador2 === '')
            alert("Nome(s) inválido(s), tente novamente.");
        else {
            document.getElementById("escolhaDuo").style.display = "none";
            flag = 1;
        }
    }
    if(flag == 1) {
        document.getElementById("jogo").style.display = "";
        document.getElementById("jogador1").innerHTML = jogador1;
        document.getElementById("jogador2").innerHTML = jogador2;
        mostrarVez();
        if(opcaoJogar == 1 && vez == 2) {
            jogarIA();
            vez = 1;
            mostrarVez();
        }
    }
}
function mostrarVez() {
    if(vez == 1) {
        document.getElementById("vezJogada").innerHTML = jogador1;
        document.getElementById("vezJogadaXO").innerHTML = "X";
    }
    else if(vez == 2) {
        document.getElementById("vezJogada").innerHTML = jogador2;
        document.getElementById("vezJogadaXO").innerHTML = "O";
    }
}
function jogar(q) {
    if(fimJogo == false) {
        if(opcaoJogar == 1) {
            jogar1(q);
        }
        else if(opcaoJogar == 2) {
            jogar2(q);
        }
    }
    else
        alert("Para continuar jogando, comece um novo jogo!");
    return q;
}
function jogarIA() {
    randomIA = Math.floor(Math.random () * 9);
    flag = 0;
    while(flag == 0) {
        if(v[randomIA] != 1 && v[randomIA] != 2) {
            flag = 1;
        }
        else {
            randomIA = Math.floor(Math.random () * 9);
            flag = 0;
        }
    }
    v[randomIA] = 2;
    document.getElementById("q" + randomIA).innerHTML = "O";
    jogadas++;
    verificarVitoria();
}
function jogar1(q) {
    posicaoOcupada = false;
    if(v[q] != 1 && v[q] != 2)
        v[q] = 1;
    else
        posicaoOcupada = true;
    if(posicaoOcupada == true)
        document.getElementById("alerta").style.display = "";
    else {
        document.getElementById("alerta").style.display = "none";
        document.getElementById("q" + q).innerHTML = "X";
        jogadas++;
        verificarVitoria();
        if(jogadas < 9 && fimJogo == false)
            jogarIA();
    }
}
function jogar2(q) {
    posicaoOcupada = false;
    if(v[q] != 1 && v[q] != 2)
        v[q] = vez;
    else
        posicaoOcupada = true;
    if(posicaoOcupada == true)
        document.getElementById("alerta").style.display = "";
    else {
        document.getElementById("alerta").style.display = "none";
        if(vez == 1) {
            document.getElementById("q" + q).innerHTML = "X";
            vez = 2;
        }
        else if(vez == 2) {
            document.getElementById("q" + q).innerHTML = "O";
            vez = 1;
        }
        jogadas++;
    }
    verificarVitoria();
    mostrarVez();
}
function verificarVitoria() {
    // Verificando se Player 1 ganhou
    // Horizontal
    if(v[0] == 1 && v[1] == 1 && v[2] == 1) {
        vencedor = 1;
        fimJogo = true;
    }
    else if(v[3] == 1 && v[4] == 1 && v[5] == 1) {
        vencedor = 1;
        fimJogo = true;
    }
    else if(v[6] == 1 && v[7] == 1 && v[8] == 1) {
        vencedor = 1;
        fimJogo = true;
    }
    // Vertical
    else if(v[0] == 1 && v[3] == 1 && v[6] == 1) {
        vencedor = 1;
        fimJogo = true;
    }
    else if(v[1] == 1 && v[4] == 1 && v[7] == 1) {
        vencedor = 1;
        fimJogo = true;
    }
    else if(v[2] == 1 && v[5] == 1 && v[8] == 1) {
        vencedor = 1;
        fimJogo = true;
    }
    // Diagonal
    else if(v[0] == 1 && v[4] == 1 && v[8] == 1) {
        vencedor = 1;
        fimJogo = true;
    }
    else if(v[2] == 1 && v[4] == 1 && v[6] == 1) {
        vencedor = 1;
        fimJogo = true;
    }
    // Verificando se Player 2 / IA ganhou
    // Horizontal
    if(v[0] == 2 && v[1] == 2 && v[2] == 2) {
        vencedor = 2;
        fimJogo = true;
    }
    else if(v[3] == 2 && v[4] == 2 && v[5] == 2) {
        vencedor = 2;
        fimJogo = true;
    }
    else if(v[6] == 2 && v[7] == 2 && v[8] == 2) {
        vencedor = 2;
        fimJogo = true;
    }
    // Vertical
    else if(v[0] == 2 && v[3] == 2 && v[6] == 2) {
        vencedor = 2;
        fimJogo = true;
    }
    else if(v[1] == 2 && v[4] == 2 && v[7] == 2) {
        vencedor = 2;
        fimJogo = true;
    }
    else if(v[2] == 2 && v[5] == 2 && v[8] == 2) {
        vencedor = 2;
        fimJogo = true;
    }
    // Diagonal
    else if(v[0] == 2 && v[4] == 2 && v[8] == 2) {
        vencedor = 2;
        fimJogo = true;
    }
    else if(v[2] == 2 && v[4] == 2 && v[6] == 2) {
        vencedor = 2;
        fimJogo = true;
    }
    else if(jogadas == 9 && fimJogo == false) {
        vencedor = 3;
        fimJogo = true;
    }
    if(fimJogo == true) {
        if(vencedor == 1) {
            pontosPlayer1++;
            document.getElementById("placarJogador1").innerHTML = pontosPlayer1;
            if(mostrarAlert == true)
                setTimeout(function(){ alert(jogador1 + " venceu!"); }, 1);
        }
        else if(vencedor == 2) {
            pontosPlayer2++;
            document.getElementById("placarJogador2").innerHTML = pontosPlayer2;
            if(mostrarAlert == true)
                setTimeout(function(){ alert(jogador2 + " venceu!"); }, 1);
        }
        else if(vencedor == 3) {
            empates++;
            document.getElementById("placarEmpates").innerHTML = empates;
            if(mostrarAlert == true)
                setTimeout(function(){ alert("Empate."); }, 1);
        }
        document.getElementById("jogarNovamente").style.display = "";
    }
    return fimJogo;
}
function novoJogo() {
    for(i = 0; i < 9; i++) {
        document.getElementById("q" + i).innerHTML = "";
        v[i] = 0;
    }
    fimJogo = 0;
    vencedor = 0;
    jogadas = 0;
    document.getElementById("jogarNovamente").style.display = "none";
}