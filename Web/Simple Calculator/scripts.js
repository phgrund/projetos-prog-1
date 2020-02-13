function op1(){
	var cont, soma = 0, num;
	num = parseInt(document.getElementById("numSoma").value, 10);
	if(document.getElementById("checkSoma").checked){
		for(cont = 1; cont <= num; cont++){
			soma += cont * cont;
		}
		if(soma == '')
			alert("O valor não pode ficar vazio.");
		else if(soma <= 0)
			alert("O valor não pode ser zero ou negativo.")
		else
			alert("Limite: " + soma);
	}
	else
		alert("Você precisa selecionar a caixa 'Calcular Soma'.");
}
function op2(){
    var fat = 1, num, cont;
    num = parseInt(document.getElementById("numFat").value, 10);
    if(document.getElementById("checkFatorial").checked){
        for(cont = 0; cont < num; cont++){
            fat *= (num - cont);
        }
        if(num <= 0)
            alert("O valor não pode ser zero ou negativo");
        else
            alert("Fatorial: " + fat);
    }
    else
        alert("Você precisa selecionar a caixa 'Calcular Fatorial'.");
}
function op3(){
	var numA, numB, numC, cont, fatA = 1, fatB = 1, resultado;
	numA = parseInt(document.getElementById("numA").value, 10);
	numB = parseInt(document.getElementById("numB").value, 10);
	numC = numA - numB;
	if(document.getElementById("checkCombinacao").checked){
		for(cont = 0; cont < numA; cont++){
            fatA *= (numA - cont);
        }
        for(cont = 0; cont < numC; cont++){
            fatB *= (numC - cont);
        }
        resultado = fatA / fatB;
        alert("Combinação: " + resultado);
	}
	else
		alert("Você precisa selecionar a caixa 'Calcular Combinação'.");
}