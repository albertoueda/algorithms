#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// #define NELEMS(x)  (sizeof(x) / sizeof(x[0]))
#define N 100000

// descomentar a linha abaixo ligara o modo DEBUG 
// #define DEBUG 
 
static int COUNT = 0;

/************ Funções auxiliares **************/

int* geraVetor (int size);
int* geraVetor () ;
void imprimeVetor (int* vetor);
void copy_values (int* origem, int* destino, int size);
void imprimeVetor (int* vetor, int size, const char* id);
void imprimeVetor (int* vetor, int size);
void imprimeVetor (int* vetor, const char* id);

/************ Algoritmos de Ordenação **************/
void fakeSort (int* vetor, int size);
void bubbleSort (int* vetor, int size);
void quickSort (int* vetor, int r, int q);
int* mergeSort (int* vetor, int r, int q);
void ordenaVetor (int* vetor, int size, int algoritmo);
