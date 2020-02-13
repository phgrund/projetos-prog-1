var i;
function calcularVetor() {
    var n = new Array(10);
    for(i = 0; i < 10; i++) {
        var input = "input";
        var inputNumero = "" + i.toString();
        var inputId = input.concat(inputNumero);
        n[i] = document.getElementById(inputId).value;
    }
    return n;
}
function calcularMaior() {
    var n = calcularVetor();
    var max = Math.max(...n);
    alert("Maior valor: " + max);
    document.getElementById("lastMax").innerHTML = max;
}
function calcularMenor() {
    var n = calcularVetor();
    var min = Math.min(...n);
    alert("Menor valor: " + min);
    document.getElementById("lastMin").innerHTML = min;
}