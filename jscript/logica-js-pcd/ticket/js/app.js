function comprar() {
  let ticket = document.getElementById("tipo-ingresso").value;
  let qtt = document.getElementById("qtd").value;
  buy(qtt,ticket);
}

function buy(qtt, zone){
    let text = document.getElementById(`qtd-${zone}`);  
    let tickets = document.getElementById(`qtd-${zone}`).textContent;
    if(!alerts(qtt, tickets)) return;
    tickets -= qtt;
    text.innerHTML = `${tickets}`;    
}

function alerts(qtt, tickets){
    if(tickets-qtt <0){
        alert('insuficient tickets');
        return false;
    }
    return true;
}
