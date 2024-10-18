

/*-------------------------------------------------------*/
/*      FATEC- São Caetano do Sul (Estrutura de Dados)    */
/*                  Atividade BubbleSort                  */
/*      Objetivo: Ordenar Array e melhorar o código       */
/*                                                        */
/*                 Autor: Matheus Macedo                  */
/*                   Data: 14/10/2024                     */
/*-------------------------------------------------------*/




#include <stdio.h>
#include <time.h>

void imprimirArray(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void trocar(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int houveTroca = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                trocar(&arr[j], &arr[j + 1]);
                houveTroca = 1;
            }
        }
        if (!houveTroca) {
            break;
        }
    }
}

int main() {
    int n;

    printf("Digite o tamanho da array:");
    scanf("%d", &n);

    if (n <= 0) {
        printf("O número da array deve ser maior que 0.\n");
        return 1;
    }

    int arr[n];

    printf("Digite os elementos da array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Array fornecida: \n");
    imprimirArray(arr, n);

    clock_t inicio = clock();

    bubbleSort(arr, n);

    clock_t fim = clock();

    double tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC * 1000;

    printf("Array ordenada: \n");
    imprimirArray(arr, n);

    printf("Tempo gasto para ordenar: %.4f ms\n", tempo_gasto);

    return 0;
}
