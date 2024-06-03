let names =[];

function adicionar(){
    let name = document.getElementById("nome-amigo").value;
    names.push(name);

    let list = document.getElementById("lista-amigos");
    list.innerHTML = names;

    console.log(names);
    
    document.getElementById("nome-amigo").value = '';
}

function sortear(){
    let print = document.getElementById('lista-sorteio');
    print.innerHTML = '';

    let limit = names.length;
    let sorter = [limit];

    while(sorter.length < names.length){
        let repeat = Math.floor(Math.random() * limit + 1);
        if(!sorter.includes(repeat) && (repeat != sorter.length+1)){ 
            console.log('len = ' + sorter.length + 'repeat = ' + repeat);
            sorter.push(repeat);
        }
    }


    for(let i=0;i<names.length;i++){
    print.innerHTML += names[i] + ' --> ' + names[sorter[i]-1] + '<br>';

    }
}

function reiniciar(){
    names =[];
    let print = document.getElementById('lista-sorteio');
    print.innerHTML = '';
    let list = document.getElementById("lista-amigos");
    list.innerHTML = '';

}