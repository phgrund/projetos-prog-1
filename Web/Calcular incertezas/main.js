document.getElementById('calcular').addEventListener('click', verificar)
let selecionarPI = document.getElementById('selecionarPI')
let storeValue = new Array(2)
const PI = 3.141592654
selecionarPI.addEventListener('change', () => {
    if(selecionarPI.checked) {
        storeValue[0] = document.getElementById('valor2').value
        storeValue[1] = document.getElementById('incerteza2').value
        document.getElementById('valor2').disabled = true
        document.getElementById('valor2').value = PI
        document.getElementById('incerteza2').disabled = true
        document.getElementById('incerteza2').value = 0.0
    }
    else {
        document.getElementById('valor2').disabled = false
        document.getElementById('incerteza2').disabled = false
        document.getElementById('valor2').value = storeValue[0]
        document.getElementById('incerteza2').value = storeValue[1]
    }
})
function verificar() {
    let valor1 = parseFloat(document.getElementById('valor1').value)
    let valor2 = parseFloat(document.getElementById('valor2').value)
    let incerteza1 = parseFloat(document.getElementById('incerteza1').value)
    let incerteza2 = parseFloat(document.getElementById('incerteza2').value)
    let operacao = document.getElementById('operacao').value
    if (isNaN(valor1) || isNaN(valor2) || isNaN(incerteza1) || isNaN(incerteza2))
        alert('Algum valor incorreto, tente novamente')
    else {
        if(selecionarPI.checked)
            calcularPI(valor1, incerteza1, operacao)
        else
            calcular(valor1, valor2, incerteza1, incerteza2, operacao)
    }
}
function calcular(valor1, valor2, incerteza1, incerteza2, operacao) {
    let valor, incerteza
    if (operacao === 'soma') {
        valor = valor1 + valor2
        incerteza = incerteza1 + incerteza2
    }
    else if(operacao === 'subtracao') {
        valor = valor1 - valor2
        incerteza = incerteza1 + incerteza2
    }
    else if(operacao === 'multiplicacao') {
        valor = valor1 * valor2
        let d = (incerteza1 / valor1) + (incerteza2 / valor2)
        incerteza = valor.toPrecision(10) * d.toPrecision(10)
    }
    else if(operacao === 'divisao') {
        valor = valor1 / valor2
        let d = incerteza1 / valor1 + incerteza2 / valor2
        incerteza = valor.toPrecision(10) * d.toFixed(9)
    }
    valor = valor.toPrecision(10)
    incerteza = incerteza.toPrecision(10)
    printResult(valor, incerteza)
}
function calcularPI(valor1, incerteza1, operacao) {
    if(operacao === 'soma') {
        valor = valor1 + PI
        incerteza = incerteza1
    }
    else if(operacao === 'subtracao'){
        valor = valor1 - PI
        incerteza = incerteza1
    }
    else if(operacao === 'multiplicacao') {
        valor = valor1 * PI
        incerteza = incerteza1
    }
    else if(operacao === 'divisao') {
        valor = valor1 / PI
        incerteza = incerteza1
    }
    valor = valor.toPrecision(10)
    incerteza = incerteza.toPrecision(10)
    printResult(valor, incerteza)
}
function printResult(valor, incerteza) {
    const result = document.getElementById('resultadoText')
    const text = `Resultado: ${valor} &#177; ${incerteza}`
    result.innerHTML = text
}