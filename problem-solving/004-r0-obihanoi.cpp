/*
 * Alberto Ueda - DCC/UFMG
 * 2017-08-31

 http://br.spoj.com/problems/OBIHANOI/

 OBIHANOI - Torres de Hanói
 Sua tarefa é escrever um programa que determine quantos movimentos de trocar um disco de um pino para outro serão executados pelo algoritmo acima para resolver o quebra-cabeça.
*/

#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

int solution;

/*
 * Pillars are unnecessary.
 */
void hanoi(int n, int orig, int dest, int temp) {

	if (n == 1) 
		solution++; 	
	else { 
		hanoi(n-1, orig, temp, dest);
		solution++;
		hanoi(n-1, temp, dest, orig);
	}

	// cout << n << ": " << solution << endl;
}

int main() {	

	int round = 1;

	while (true) {
		int n;		
		solution = 0;

		cin >> n;

		if (n == 0 || !cin)
			break;


		// A simpler way would be 2^n - 1
		solution = pow(2, n) - 1;

		// hanoi(n, 1, 2, 3);

		cout << "Teste " << round++ << endl;
		cout << solution << endl;
		cout << endl;	
	}
}