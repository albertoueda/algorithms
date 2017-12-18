/*
 * Alberto Ueda - DCC/UFMG
 * 2017-08-31

 http://br.spoj.com/problems/MINHOCA/

 MINHOCA - Campo de Minhocas
 Escreva um programa que, fornecido o mapa do campo de minhocas, descrevendo a produtividade estimada em cada célula, calcule o número esperado total de minhocas a serem colhidas pela máquina durante o teste, conforme descrito acima.
*/

#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

int main() {	

	int n, m;
	cin >> n >> m;

	int map[n][m];

	// read
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];	

	int sum, solution = 0;


	// search line by line 
	for (int i = 0; i < n; i++) {
		sum = 0;

		for (int j = 0; j < m; j++) 
			sum += map[i][j];

		if (solution < sum) 
			solution = sum;
	}

	// search column by column 
	for (int j = 0; j < m; j++) {
		sum = 0;

		for (int i = 0; i < n; i++) 		
			sum += map[i][j];
		
		if (solution < sum) 
			solution = sum;
	}

	cout << solution << endl;
}
