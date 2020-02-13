function calcularFibonacci() {
    var i = 2;
    var n = parseInt(document.getElementById("numFibonacci").value, 10);
    var fib = new Array();
    fib[0] = 0;
    fib[1] = 1;
    if(fib < 1)
        alert("Valores menores que 1 não são permitidos.");
    else{
        for(i = 2; i <= n ; i++){
            fib[i] = fib[i - 2] + fib[i - 1];
        }
        alert("Posição = " + (i - 1) + ".\nValor = " + fib[i - 1]);
    }
    var lastPosicao = (i - 1);
    var lastValor = fib[i - 1];
    document.getElementById("lastPosicao").innerHTML = lastPosicao;
    document.getElementById("lastValor").innerHTML = lastValor;
}