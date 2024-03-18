#include <stdio.h>

int somarElementos(const int *array, int tamanho) {
    int soma = 0;

    for (int i = 0; i < tamanho; i++) {
        soma += *(array + i); 
    }

    return soma;
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
  printf("A soma de todos os numeros são: \n");
   printf("%d\n", somarElementos(numeroInteiros, 5));
  
  return 0;
}
