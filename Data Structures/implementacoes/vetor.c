#include <stdio.h>

int buscar(int valor, int vetor[], int tamanho)
{
  int i = tamanho - 1;
  while (i >= 0 && vetor[i--] != valor)
  {
  }
  return i;
}

int inserirNoFinal(int tamanho, int vetor[], int valor)
{
  vetor[tamanho] = valor;
  return ++tamanho;
}

int main(int argc, char const *argv[])
{
  int vetor[] = {0, 1, 2, 3, 4, 5};
  printf("%d\n", inserirNoFinal(5, vetor, 6));
  return 0;
}
