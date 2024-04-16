#include <stdio.h>

int main() {
  int num1, num2;
  char operador;
  float resultado;
resultado = 0.0;
  printf("Faça seu calculo em formato RPN: ");
  scanf("%d %d %c", &num1, &num2, &operador);

  switch (operador) {
  case '+':
    resultado = num1 + num2;
    printf("Soma: %f\n", resultado);
    printf("Formula Algebrica: %d %c %d\n", num1 
      ,operador,num2 );
    break;
  case '-':
    resultado = num1 - num2;
    printf("Diferença: %f\n", resultado);
    printf("Formula Algebrica: %d %c %d\n", num1 
      ,operador,num2 );
    break;
  case '*':
    resultado = num1 * num2;
    printf("Produto: %f\n", resultado);
    printf("Formula Algebrica: %d %c %d\n", num1 
      ,operador,num2 );
    break;
  case '/':
    resultado = num1 / num2;
    printf("Sobra: %f\n", resultado);
    printf("Formula Algebrica: (%d %c %d)\n", num1 
      ,operador,num2 );
    break;
  default:
    printf("Escolha invalida\n");
  }

  return 0;
}