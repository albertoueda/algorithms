/*
 * Alberto Ueda - DCC/UFMG
 * 2017-08-31

http://br.spoj.com/problems/QUERM/

 QUERM - Quermesse
 Conhecendo a lista de participantes, por ordem de chegada, sua tarefa é determinar o número do ingresso premiado, sabendo que o ganhador é o único participante que tem o número do ingresso igual à sua posição de entrada na festa.
*/

#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

// Assumes that there is always a solution
int main() {	

	int round = 1;

	while (true) {
		int n, solution;		

		cin >> n;

		if (n == 0 || !cin)
			break;

		int ning;
		for (int i = 1; i <= n; i++) {
			cin >> ning;
			
			if (i == ning) 
				solution = i;
				// (or) cin.ignore(n, '\n'); // Cool! But I've used it wrongly.
				// break;
		}

		cout << "Teste " << round++ << endl;
		cout << solution << endl;
		cout << endl;	
	}

}