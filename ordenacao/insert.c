#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

static int COUNT = 0;

/************ Funções auxiliares **************/

int* geraVetor (int size) {
  int i, seed;
  int* vetor;

  srand ((int) time (NULL));
  vetor = (int*) malloc(size * sizeof(int));

  for (i = 0; i < size; i++)
    vetor[i] = rand() % 100;    

  return vetor;
}

int* geraVetor () {
  return geraVetor(N);
}

/* TODO usar ponteiros! */
void copy_values (int* origem, int* destino, int size) {
  int i;

  for (i = 0; i < size; i++) {
    destino[i] = origem[i];
  }
}

void imprimeVetor (int* vetor, int size, const char* id) {
  int i;

  printf("> ");
  for (i = 0; i < size; ++i) 
    printf("%d ", vetor[i]);

  printf(" %s\n", id);
}  

void imprimeVetor (int* vetor, int size) {
  char id[2] = "";
  imprimeVetor (vetor, size, id);
}  

void imprimeVetor (int* vetor, const char* id) {
  imprimeVetor (vetor, N, id);
}

void imprimeVetor (int* vetor) {
  char id[2] = "";
  imprimeVetor (vetor, N, id);
}


/************ Algoritmos de Ordenação **************/

void fakeSort (int* vetor, int size) {
  int i, t;

  for (i = 0; i < size/2; i++){
    t = vetor[i]; 
    vetor[i] = vetor[size-1-i]; 
    vetor[size-1-i] = t; 
  }
}

void bubbleSort (int* vetor, int size) {
  int i, j, t, min;

  for (i = 0; i < size; i++) {
    min = i;

    for (j = i+1; j < size; j++) {
      if (vetor[j] < vetor[min]) { 
        min = j;
      } 
    }

    t = vetor[i]; 
    vetor[i] = vetor[min]; 
    vetor[min] = t; 
  }
}

int separa (int* vetor, int r, int q) {
    int i, j, valorPivo, tmp;

    i = r + 1;
    j = q;
    valorPivo = vetor[r];

    while (1) {
      while (i <= q && vetor[i] <= valorPivo) i++;
      while (vetor[j] > valorPivo) j--;

      if (i >= j) break;    

      tmp = vetor[i]; vetor[i] = vetor[j]; vetor[j] = tmp;
    }

    vetor[r] = vetor[j]; vetor[j] = valorPivo;
    return j;
}

void quickSort (int* vetor, int r, int q) {
  int p;

  if (r < q) {
    p = separa (vetor, r, q);
    quickSort (vetor, r, p-1);
    quickSort (vetor, p+1, q);
  }
}

int* intercala (int* vetorE, int* vetorD, int sizeE, int sizeD) {
  int i, j, k, maior;
  int* ordenado;

  ordenado = (int*) malloc ((sizeE + sizeD) * sizeof(int));

  imprimeVetor(vetorE, sizeE, "vetorE");
  imprimeVetor(vetorD, sizeD, "vetorD");

  for (k = 0, i = 0, j = 0; i < sizeE && j < sizeD; ) {

    if (vetorE[i] < vetorD[j])
      ordenado[k++] = vetorE[i++];
    else
      ordenado[k++] = vetorD[j++];
  }

  for (; i < sizeE; )
    ordenado[k++] = vetorE[i++];

  for (; j < sizeD; )
    ordenado[k++] = vetorD[j++];

  imprimeVetor(ordenado, sizeE+sizeD, "intercalado");
  printf("vez=%d\n\n", COUNT++);
  return ordenado;
}

/** TODO analisar melhor algoritmo, mtos a esquerda */
int* mergeSort (int* vetor, int r, int q) {
  int meio;
  int* esq, *dir, *ordenado;

  ordenado = (int*) malloc ((q-r+1) * sizeof(int));

  if (r == q)
    ordenado[0] = vetor[r];

  else if (r < q) {
    meio = r + (q-r) / 2;
    esq = mergeSort (vetor, r, meio);
    dir = mergeSort (vetor, meio+1, q);

    ordenado = intercala (esq, dir, meio-r+1, q-meio);
  }

  return ordenado;
}

void ordenaVetor (int* vetor, int size) {

  // fakeSort(vetor, size);
  // bubbleSort(vetor, size);
  // quickSort(vetor, 0, size-1);
  copy_values ( mergeSort (vetor, 0, size-1), vetor, size);

}

void ordenaVetor (int* vetor) {
  ordenaVetor (vetor, N);
}

/************ Rotina principal **************/

int main (int arg, char* argv[]) {
  int* numbers;
  int i;
 
  numbers = geraVetor();

  imprimeVetor (numbers, "Inicial");
  ordenaVetor (numbers);
  imprimeVetor (numbers, "Mergesort");

  free (numbers);
}

