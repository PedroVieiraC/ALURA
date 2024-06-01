function alterarStatus(id) {
  let onclickGame = document.getElementById(`game-${id}`);
  let img = onclickGame.querySelector(".dashboard__item__img");
  let button = onclickGame.querySelector(".dashboard__item__button");

  if (img.classList.contains("dashboard__item__img--rented")) {
    img.classList.remove("dashboard__item__img--rented");
    button.classList.remove("dashboard__item__button--return");
    button.textContent = 'Alugar';
  } else {
    img.classList.add("dashboard__item__img--rented");
    button.classList.add("dashboard__item__button--return");
    button.textContent = 'Devolver';
}
}

function changeBtn() {
  let btn = document.getElementById("game-1");
  if (btn.classList.contains("container__botao-desabilitado")) {
    btn.classList.remove("container__botao-desabilitado");
    btn.classList.add("container__botao");
  } else {
    btn.classList.remove("container__botao");
    btn.classList.add("container__botao-desabilitado");
  }
}
