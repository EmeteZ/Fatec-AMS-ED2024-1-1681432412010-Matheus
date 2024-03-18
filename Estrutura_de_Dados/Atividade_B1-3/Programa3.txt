#include <stdio.h>

void imprimir(const int *array, int tamanho) {
    printf("Elementos do array: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", *(array + i)); 

    }
    printf("\n");
}

int main() {
  int numeroInteiros[5];
  int i, j, k;

  printf("Digite 5 números: \n");
  for (i = 0; i < 5; i++) {
    scanf("%d", &numeroInteiros[i]);
  }

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
  imprimir(numeroInteiros, 5);
  return 0;
}
