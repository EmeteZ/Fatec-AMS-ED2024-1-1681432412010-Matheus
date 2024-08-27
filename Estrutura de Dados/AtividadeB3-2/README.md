Nomes: Matheus Macedo e Gustavo Sanches

![Fluxograma](https://github.com/user-attachments/assets/4f673fcc-fed3-4b31-bc57-baa7796f8112)

1. Busca Linear

function buscaLinear(A, x) {
    for (let i = 0; i < A.length; i++) {
        if (A[i] === x) {
            return i;  
        }
    }
    return -1;  
}


2. Busca Linear em Ordem

   function buscaLinearEmOrdem(A, x) {
    for (let i = 0; i < A.length; i++) {
        if (A[i] === x) {
            return i;  
        } else if (A[i] > x) {
            break;  
        }
    }
    return -1;  
}


3. Busca Binaria 

function buscaBinaria(A, x) {
    let esq = 0;
    let dir = A.length - 1; 
    while (esq <= dir) {
        let meio = Math.floor((esq + dir) / 2);
        if (A[meio] === x) {
            return meio;  
        } else if (A[meio] < x) {
            esq = meio + 1; 
        } else {
            dir = meio - 1;  
        }
    }  
    return -1;  
}
