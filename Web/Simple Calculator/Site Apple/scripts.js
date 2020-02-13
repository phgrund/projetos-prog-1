var iMacs = 3999, iPhones = 1199, iPad2 = 1649, iPod = 229, compra = 0, cont, cont2;
function simularCompra(){
	compra = 0;
	cont = 0;
	if(document.getElementById("check1").checked){
		if(document.getElementById("select1").value == "dummy"){
			compra += iMacs * 0.95;
		}
		else if(document.getElementById("select1").value == "normal"){
			compra += iMacs * 0.9;
		}
		else if(document.getElementById("select1").value == "power"){
			compra += iMacs * 0.8;
		}
		cont++;
	}
	if(document.getElementById("check2").checked){
		if(document.getElementById("select2").value == "dummy"){
			compra += iPhones * 0.95;
		}
		else if(document.getElementById("select2").value == "normal"){
			compra += iPhones * 0.9;
		}
		else if(document.getElementById("select2").value == "power"){
			compra += iPhones * 0.8;
		}
		cont++;
	}
	if(document.getElementById("check3").checked){
		if(document.getElementById("select3").value == "dummy"){
			compra += iPad2 * 0.95;
		}
		else if(document.getElementById("select3").value == "normal"){
			compra += iPad2 * 0.9;
		}
		else if(document.getElementById("select3").value == "power"){
			compra += iPad2 * 0.8;
		}
		cont++;
	}
	if(document.getElementById("check4").checked){
		if(document.getElementById("select4").value == "dummy"){
			compra += iPod * 0.95;
		}
		else if(document.getElementById("select4").value == "normal"){
			compra += iPod * 0.9;
		}
		else if(document.getElementById("select4").value == "power"){
			compra += iPod * 0.8;
		}
		cont++;
	}
	if(cont > 0)
		alert("Valor simulado da compra: R$" + compra.toFixed(2));
	else
		alert("Nenhuma opção 'Comprar' marcada, tente novamente.");
}
function comprar(){
	compra = 0;
	cont = 0;
	cont2 = 0
	if(document.getElementById("check1").checked){
		if(document.getElementById("select1").value == "dummy"){
			compra += iMacs * 0.95;
		}
		else if(document.getElementById("select1").value == "normal"){
			compra += iMacs * 0.9;
		}
		else if(document.getElementById("select1").value == "power"){
			compra += iMacs * 0.8;
		}
		cont++;
	}
	if(document.getElementById("check2").checked){
		if(document.getElementById("select2").value == "dummy"){
			compra += iPhones * 0.95;
		}
		else if(document.getElementById("select2").value == "normal"){
			compra += iPhones * 0.9;
		}
		else if(document.getElementById("select2").value == "power"){
			compra += iPhones * 0.8;
		}
		cont++;
	}
	if(document.getElementById("check3").checked){
		if(document.getElementById("select3").value == "dummy"){
			compra += iPad2 * 0.95;
		}
		else if(document.getElementById("select3").value == "normal"){
			compra += iPad2 * 0.9;
		}
		else if(document.getElementById("select3").value == "power"){
			compra += iPad2 * 0.8;
		}
		cont++;
	}
	if(document.getElementById("check4").checked){
		if(document.getElementById("select4").value == "dummy"){
			compra += iPod * 0.95;
		}
		else if(document.getElementById("select4").value == "normal"){
			compra += iPod * 0.9;
		}
		else if(document.getElementById("select4").value == "power"){
			compra += iPod * 0.8;
		}
		cont++;
	}
	var nome = document.getElementById("nome").value;
	var cc = document.getElementById("cc").value;
	var parcelas = parseInt(document.getElementById("parcelas").value, 10);
	if(nome == '' || cc == '' || cont == 0)
		alert("Preencha todos os campos, tente novamente");
	else{
		alert("Prezado " + nome + ", seguem os dados da sua compra:\nTotal da Compra: R$" + compra.toFixed(2) + "\nNº de parcelas: " + parcelas + "\nValor de cada parcela: R$" + (compra / parcelas).toFixed(2));
		document.getElementById("finalcompra").innerHTML = 'Parabéns pela sua compra!';
	}
}	