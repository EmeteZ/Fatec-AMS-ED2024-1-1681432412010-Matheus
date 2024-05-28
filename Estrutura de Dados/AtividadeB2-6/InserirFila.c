#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct No {
  int dado;
  struct No *proximo;
};

void inserirNaListaLigada(struct No **cabecaRef, int valorInserir,
                          int posicao) {
  struct No *novoNo = (struct No *)malloc(sizeof(struct No));
  novoNo->dado = valorInserir;

  if (posicao == 0) {
    novoNo->proximo = *cabecaRef;
    *cabecaRef = novoNo;
    return;
  }

  struct No *noAtual = *cabecaRef;
  for (int i = 0; noAtual != NULL && i < posicao - 1; i++) {
    noAtual = noAtual->proximo;
  }

  if (noAtual == NULL || noAtual->proximo == NULL) {
    novoNo->proximo = NULL;
    noAtual->proximo = novoNo;
    return;
  }

  novoNo->proximo = noAtual->proximo;
  noAtual->proximo = novoNo;
}

void imprimirLista(struct No *no) {
  while (no != NULL) {
    printf("%d ", no->dado);
    no = no->proximo;
  }
  printf("\n");
}

int main() {
  struct No *cabeca = NULL;
  struct No *segundo = NULL;
  struct No *terceiro = NULL;
  struct No *quarto = NULL;

  cabeca = (struct No *)malloc(sizeof(struct No));
  segundo = (struct No *)malloc(sizeof(struct No));
  terceiro = (struct No *)malloc(sizeof(struct No));
  quarto = (struct No *)malloc(sizeof(struct No));

  cabeca->dado = 1;
  cabeca->proximo = segundo;

  segundo->dado = 2;
  segundo->proximo = terceiro;

  terceiro->dado = 4;
  terceiro->proximo = quarto;

  quarto->dado = 5;
  quarto->proximo = NULL;

  int valorInserir = 3;
  int posicao = 2;

  clock_t tempoComeco, tempoFinal;
  double tempoGasto;

  tempoComeco = clock();
  inserirNaListaLigada(&cabeca, valorInserir, posicao);
  tempoFinal = clock();

  tempoGasto = ((double)(tempoFinal - tempoComeco)) / CLOCKS_PER_SEC;

  printf("Lista após entrada: ");
  imprimirLista(cabeca);
  printf("Tempo de processamento: %f segundos\n", tempoGasto);

  return 0;
}