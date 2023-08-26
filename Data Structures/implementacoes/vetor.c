#include <stdio.h>
#include <stdlib.h>
#define TAM 7
#define BUSCA_EXISTENTE TAM - 3
#define BUSCA_NAO_EXISTE TAM - 2
#define INSERE TAM - 2
#define POSICAO 3

void imprimeVetor(int tamanho, int vetor[])
{
  printf("Vetor:\n");
  for (int i = 0; i < tamanho; i++)
  {
    printf("Posição %d: %d\n", i, vetor[i]);
  }
  printf("\n");
}

int buscar(int valor, int vetor[], int tamanho)
{
  while (tamanho >= 0 && vetor[--tamanho] != valor)
    ;
  return tamanho;
}

int inserirNoFinal(int tamanho, int vetor[], int valor)
{
  vetor[tamanho] = valor;
  return ++tamanho;
}

int inserir(int tamanho, int posicao, int vetor[], int valor)
{
  int i = tamanho;
  while (i > posicao)
  {
    vetor[i] = vetor[i - 1];
    i--;
  }
  vetor[i] = valor;
  return ++tamanho;
}

int main(int argc, char const *argv[])
{
  /*definição do vetor, se quiser alterar os valores altere nas constantes*/
  int *vetor = (int *)(malloc(TAM * sizeof(int))); // aloca espaço para 7 elementos, os 5 iniciais e mais duas inserções
  int tamanho = 0;
  for (int i = 0; i < TAM - 2; i++)
  {
    vetor[i] = i;
    tamanho++;
  }
  /*fim da definição do vetor*/

  printf("Buscando o valor %d, que consta no indice %d do vetor: %d\n\n", BUSCA_EXISTENTE, BUSCA_EXISTENTE, buscar(BUSCA_EXISTENTE, vetor, tamanho));

  imprimeVetor(tamanho, vetor);

  printf("Buscando o valor %d, que não existe no vetor: %d\n\n", BUSCA_NAO_EXISTE, buscar(BUSCA_NAO_EXISTE, vetor, tamanho));

  tamanho = inserirNoFinal(INSERE, vetor, tamanho);

  printf("Inserir %d no final, novo tamanho: %d\n\n", INSERE, tamanho);
  imprimeVetor(tamanho, vetor);

  tamanho = inserir(tamanho, POSICAO, vetor, INSERE);

  printf("Inserir %d na posicao %d. Novo tamanho: %d\n\n", INSERE, POSICAO, tamanho);

  imprimeVetor(tamanho, vetor);

  free(vetor);
  return 0;
}
