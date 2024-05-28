#include <stdio.h>
#include <time.h>

void inserirNoArray(int array[], int tamanhoAtual, int valorInserir,
                    int posicao) {
  for (int i = tamanhoAtual; i > posicao; i--) {
    array[i] = array[i - 1];
  }
  array[posicao] = valorInserir;
}

int main() {
  int array[9] = {1, 2, 3, 4, 6, 7, 8, 9};
  int tamanhoAtual = 8;
  int valorInserir = 5;
  int posicao = tamanhoAtual / 2;

  clock_t tempoComeco, tempoFinal;
  double tempoGasto;

  tempoComeco = clock();
  inserirNoArray(array, tamanhoAtual, valorInserir, posicao);
  tempoFinal = clock();

  tempoGasto = ((double)(tempoFinal - tempoComeco)) / CLOCKS_PER_SEC;

  printf("Array após entrada: ");
  for (int i = 0; i <= tamanhoAtual; i++) {
    printf("%d ", array[i]);
  }
  printf("\nTempo de processamento: %f segundos\n", tempoGasto);

  return 0;
}