let finalValue=0;


function adicionar() {
  let item = document.getElementById("produto").value;
  let name = item.split("-")[0];
  let qtt = document.getElementById("quantidade").value;
  let totalValue = (item.split("R$")[1]) * qtt;

  if(!alerts(qtt)) return;

  finalValue += totalValue;
  
  addCart(qtt, totalValue, name);

  let fv = document.getElementById('valor-total');
  fv.innerHTML = `R$${finalValue}`;
  
}

function alerts(qtt){
    if(!qtt || isNaN(qtt) || qtt <=0){
        alert('need to add a quantity');
        return false;
    }
    return true;
}

function addCart(qtt, value, name) {
  let cart = document.getElementById("lista-produtos");
  cart.innerHTML += `<section class="carrinho__produtos__produto">
      <span class="texto-azul">${qtt}</span> ${name}
      <span class="texto-azul">R$${value}</span>
    </section>`;
}

function limpar() {
  let value = document.getElementById("valor-total");
  value.textContent = "R$ 0";
  let valu = document.getElementById("lista-produtos");
  valu.textContent = "";
  finalValue =0;
}
