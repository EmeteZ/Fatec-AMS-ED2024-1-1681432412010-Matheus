#include <stdio.h>

int maiorNumero(const int *array, int tamanho) {
    int maior = *array; 
    const int *ponteiro = array; 
    for (int i = 1; i < tamanho; i++) {
        if (*(array + i) > maior) { 
            maior = *(array + i); 
        }
    }

    return maior;
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
  printf("Maior Numero: \n");
  printf("%d\n", maiorNumero(numeroInteiros, 5));
  return 0;
}
