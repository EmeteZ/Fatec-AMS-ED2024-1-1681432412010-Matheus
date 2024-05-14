#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Cliente {
  char nome[50];
  int idade;
  char motivoConsulta[100];
  int prioridade;
  time_t inicioAtendimento;
  time_t fimAtendimento;
  int numeroConsultorio;
  struct Cliente *proximo;
} Cliente;

typedef struct Fila {
  Cliente *inicio;
  Cliente *fim;
} Fila;

typedef struct HistoricoAtendimentos {
  Cliente *inicio;
  Cliente *fim;
} HistoricoAtendimentos;

Fila *criarFila() {
  Fila *f = (Fila *)malloc(sizeof(Fila));
  f->inicio = NULL;
  f->fim = NULL;
  return f;
}

HistoricoAtendimentos *criarHistorico() {
  HistoricoAtendimentos *historico =
      (HistoricoAtendimentos *)malloc(sizeof(HistoricoAtendimentos));
  historico->inicio = NULL;
  historico->fim = NULL;
  return historico;
}

Cliente *criarCliente(char *nome, int idade, char *motivoConsulta,
                      int prioridade) {
  Cliente *c = (Cliente *)malloc(sizeof(Cliente));
  strcpy(c->nome, nome);
  c->idade = idade;
  strcpy(c->motivoConsulta, motivoConsulta);
  c->prioridade = prioridade;
  c->proximo = NULL;
  return c;
}

void adicionarCliente(Fila *f, Cliente *c) {
  if (f->inicio == NULL) {
    f->inicio = c;
    f->fim = c;
  } else {
    f->fim->proximo = c;
    f->fim = c;
  }
}

Cliente *atenderCliente(Fila *filaUrgente, Fila *filaPrioritaria,
                        Fila *filaNormal, int numeroConsultorio) {
  Cliente *c = NULL;
  if (filaUrgente->inicio != NULL) {
    c = filaUrgente->inicio;
    filaUrgente->inicio = filaUrgente->inicio->proximo;
  } else if (filaPrioritaria->inicio != NULL) {
    c = filaPrioritaria->inicio;
    filaPrioritaria->inicio = filaPrioritaria->inicio->proximo;
  } else if (filaNormal->inicio != NULL) {
    c = filaNormal->inicio;
    filaNormal->inicio = filaNormal->inicio->proximo;
  }

  if (c != NULL) {
    c->inicioAtendimento = time(NULL);
    c->fimAtendimento = 0;
    c->numeroConsultorio = numeroConsultorio;
  }

  return c;
}

void finalizarAtendimento(Cliente *c) { c->fimAtendimento = time(NULL); }

void removerCliente(Cliente *c) { free(c); }

void visualizarFila(Fila *f) {
  Cliente *c = f->inicio;
  while (c != NULL) {
    printf("Nome: %s, Idade: %d, Motivo da Consulta: %s, Prioridade: %d\n",
           c->nome, c->idade, c->motivoConsulta, c->prioridade);
    c = c->proximo;
  }
}

void adicionarHistorico(HistoricoAtendimentos *historico, Cliente *c) {
  if (historico->inicio == NULL) {
    historico->inicio = c;
    historico->fim = c;
  } else {
    historico->fim->proximo = c;
    historico->fim = c;
  }
}

void visualizarHistorico(HistoricoAtendimentos *historico) {
  Cliente *c = historico->inicio;
  printf("Histórico de Atendimentos:\n");
  while (c != NULL) {
    printf("Nome: %s, Idade: %d, Motivo da Consulta: %s, Prioridade: %d, "
           "Consultório: %d\n",
           c->nome, c->idade, c->motivoConsulta, c->prioridade,
           c->numeroConsultorio);
    c = c->proximo;
  }
}

int main() {
  Fila *filaNormal = criarFila();
  Fila *filaPrioritaria = criarFila();
  Fila *filaUrgente = criarFila();
  HistoricoAtendimentos *historico = criarHistorico();

  char nome[50];
  int idade;
  char motivoConsulta[100];
  int prioridade;
  int opcao;
  int numeroConsultorio = 1;

  do {
    printf("\nEscolha uma opção:\n");
    printf("1. Adicionar cliente\n");
    printf("2. Visualizar filas\n");
    printf("3. Atender cliente\n");
    printf("4. Visualizar histórico de atendimentos\n");
    printf("5. Sair\n");
    scanf("%d", &opcao);

    switch (opcao) {
    case 1:
      printf("Digite o nome do cliente: ");
      scanf("%s", nome);
      printf("Digite a idade do cliente: ");
      scanf("%d", &idade);
      printf("Digite o motivo da consulta: ");
      scanf("%s", motivoConsulta);
      printf("Digite a prioridade do cliente (1 para normal, 2 para "
             "prioritária, 3 para urgente): ");
      scanf("%d", &prioridade);

      if (prioridade == 1) {
        adicionarCliente(filaNormal,
                         criarCliente(nome, idade, motivoConsulta, prioridade));
      } else if (prioridade == 2) {
        adicionarCliente(filaPrioritaria,
                         criarCliente(nome, idade, motivoConsulta, prioridade));
      } else if (prioridade == 3) {
        adicionarCliente(filaUrgente,
                         criarCliente(nome, idade, motivoConsulta, prioridade));
      } else {
        printf("Prioridade inválida.\n");
      }
      break;
    case 2:
      printf("\nFila Normal:\n");
      visualizarFila(filaNormal);
      printf("\nFila Prioritária:\n");
      visualizarFila(filaPrioritaria);
      printf("\nFila Urgente:\n");
      visualizarFila(filaUrgente);
      break;
    case 3:
      if (filaUrgente->inicio != NULL || filaPrioritaria->inicio != NULL ||
          filaNormal->inicio != NULL) {
        Cliente *c = atenderCliente(filaUrgente, filaPrioritaria, filaNormal,
                                    numeroConsultorio);
        printf("\nCliente %s, dirija-se ao consultório %d.\n", c->nome,
               c->numeroConsultorio);
        finalizarAtendimento(c);
        adicionarHistorico(historico, c);
        removerCliente(c);
        numeroConsultorio++;
      } else {
        printf("\nNenhum cliente na fila.\n");
      }
      break;
    case 4:
      visualizarHistorico(historico);
      break;
    case 5:
      printf("\nSaindo do sistema...\n");
      break;
    default:
      printf("\nOpção inválida.\n");
    }
  } while (opcao != 5);

  return 0;
}
