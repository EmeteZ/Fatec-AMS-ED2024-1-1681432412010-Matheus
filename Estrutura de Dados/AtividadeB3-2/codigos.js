// ----------- Busca Linear -----------
function buscaLinear(A, x) {
    for (let i = 0; i < A.length; i++) {
        if (A[i] === x) {
            return i;  // Retorna o índice onde x foi encontrado
        }
    }
    return -1;  // Se não encontrar, retorna -1
}

// ----------- Busca Linear em Ordem -----------
function buscaLinearEmOrdem(A, x) {
    for (let i = 0; i < A.length; i++) {
        if (A[i] === x) {
            return i;  // Retorna o índice onde x foi encontrado
        } else if (A[i] > x) {
            break;  // Como o array está ordenado, pode parar
        }
    }
    return -1;  // Se não encontrar, retorna -1
}

// ----------- Busca Binária -----------
function buscaBinaria(A, x) {
    let esq = 0;
    let dir = A.length - 1;
    
    while (esq <= dir) {
        let meio = Math.floor((esq + dir) / 2);
        if (A[meio] === x) {
            return meio;  // Retorna o índice onde x foi encontrado
        } else if (A[meio] < x) {
            esq = meio + 1;  // Procura na metade direita
        } else {
            dir = meio - 1;  // Procura na metade esquerda
        }
    }
    
    return -1;  // Se não encontrar, retorna -1
}
