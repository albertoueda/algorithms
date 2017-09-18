#include <sys/time.h>
#include "ordenacao.c"

bool testeOrdemCrescente (int* vetor, int size) {
	int i;

	i = 1;

	while (i < size) {
		if (vetor[i-1] > vetor[i]) {
			printf("Erro: %d > %d\n", vetor[i-1], vetor[i]);
			return false;
		}
		
		i++;
	}

	return true;
}

void testaAlgoritmos (int* vetor, int numeroTeste) {
	  int i;
 		int* copia1, *copia2, *copia3;
	  struct timeval startTime, endTime; 
	  float tempo[4];

		copiaValores (vetor, copia1, N);
		copiaValores (vetor, copia2, N);
		copiaValores (vetor, copia3, N);

		for (i = 1; i < 5; i++) {
		  gettimeofday (&startTime, NULL);
			ordenaVetor (vetor, N, i);
	  	gettimeofday (&endTime, NULL);

			tempo[i] = endTime.tv_sec - startTime.tv_sec + 
				1e-6 * (endTime.tv_usec - startTime.tv_usec);

			// No fakesort sempre teremos erro
			if (i != 1)
				testeOrdemCrescente (vetor, N);
		}

		printf("Fim do %dº teste (%d numeros)\n", numeroTeste+1, N);
		printf("FakeSort: %.3g seg., BubbleSort: %.3g seg., QuickSort: %.3g seg., "
			"MergeSort: %.3g seg.\n\n", tempo[1], tempo[2], tempo[3], tempo[4]);
}

int main (int argc, char* argv[]) {
	int* vetor;
	int i, n;

	i = 0;
	n = 5;

	if (argc > 1)
		n = atoi (argv[1]);

	while (i < n) {
		vetor = geraVetor();

		#ifdef DEBUG
			imprimeVetor (vetor, "Inicial");
		#endif

		testaAlgoritmos (vetor, i);

		#ifdef DEBUG
			imprimeVetor (vetor, "Final");
		#endif


		free (vetor);	
		i++;
	}
}