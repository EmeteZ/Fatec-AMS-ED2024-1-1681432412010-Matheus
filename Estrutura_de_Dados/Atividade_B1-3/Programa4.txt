#include <stdio.h>

void multiplicar(int *array, int tamanho, int multiplicador) {
    for (int i = 0; i < tamanho; i++) {
        array[i] *= multiplicador;
    }
}

int main() {
    int numeroInteiros[5];
    int i, j, k, multiplicador;

    printf("Digite 5 números: \n");
    for (i = 0; i < 5; i++) {
        scanf("%d", &numeroInteiros[i]);
    }

    printf("Digite um valor para fazermos a multiplicação: \n");
    scanf("%d", &multiplicador);

    printf("Organizado: \n");
    for (i = 0; i < 5; i++) {
        for (j = i + 1; j < 5; j++) {
            if (numeroInteiros[i] > numeroInteiros[j]) {
                k = numeroInteiros[i];
                numeroInteiros[i] = numeroInteiros[j];
                numeroInteiros[j] = k;
            }
        }

        printf("%d\n", numeroInteiros[i]);
    }

    multiplicar(numeroInteiros, 5, multiplicador);

    printf("Numeros Multiplicados: \n");
    for (i = 0; i < 5; i++) {
        printf("%d\n", numeroInteiros[i]);
    }

    return 0;
}
