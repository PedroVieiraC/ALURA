let low, range, quantity, sort;
let numbers = [];

function showText(tag, text) {
  let campo = document.querySelector(tag);
  campo.innerHTML = text;
}

function sortear() {
  low = parseInt(document.querySelector("#de").value);
  range = parseInt(document.querySelector("#ate").value);
  quantity = parseInt(document.querySelector("#quantidade").value);

  if (!alerts(quantity, low, range)) {
    return;
  }

  let sort = sortNum(quantity, low, range);
  console.log(sort);
  console.log(numbers);

  showText(
    "#resultado .texto__paragrafo",
    `Números sorteados: ${numbers.join(", ")}`
  );
  changeBtn();
}

function sortNum(quantity, low, range) {
  while (numbers.length < quantity) {
    sort = Math.floor(Math.random() * (range - low + 1)) + low;
    if (!numbers.includes(sort)) {
      numbers.push(sort);
    }
  }
}

function changeBtn() {
  let btn = document.getElementById('btn-reiniciar');
  if (btn.classList.contains('container__botao-desabilitado')) {
    btn.classList.remove('container__botao-desabilitado');
    btn.classList.add('container__botao');
} else{
    btn.classList.remove('container__botao');
    btn.classList.add('container__botao-desabilitado');
}
}

function reiniciar() {
  cleaner();
  numbers = [];
}

function cleaner() {
  document.querySelector("#quantidade").value = "";
  document.querySelector("#de").value = "";
  document.querySelector("#ate").value = "";
}

function alerts(quantity, low, range) {
  if (isNaN(quantity) || isNaN(low) || isNaN(range)) {
    alert("Por favor, insira valores válidos.");
    return false;
  }

  if (low > range) {
    alert("range should be bigger than low");
    return false;
  }
  if (quantity < 0 || quantity > range - low + 1) {
    alert(`The numbers quantity should be lower than the ${range - low + 1}`);
    return false;
  }

  return true;
}
