/*
 * Alberto Ueda - DCC/UFMG
 * 2017-08-31

 http://br.spoj.com/problems/COPA1/
 Dados os resultados dos quinze jogos da Fase final, escreva um programa que determine a equipe campeã.

*/
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

// Version 2 :)
int main() {	
	int t1, t2; // match result: t1 x t2
	string results[17][4]; // results[0] not used

	for (int i = 1; i <= 16; i++) 
		results[i][0] = (char) (i + (int) 'A' - 1);	

	// i results of level k
	for (int k = 1; k <= 4; k++) {
		for (int i = 1; i <= 8/pow(2, k-1); i++) {
			cin >> t1 >> t2;

			if (t1 > t2) 
				results[i][k] = results[i*2 - 1][k-1];
			else 
				results[i][k] = results[i*2][k-1];		
		}
	}

	cout << results[1][4] << endl;	
}

int main_v1() {	
	int t1, t2; // match result: t1 x t2
	string results[9][4]; // results[0] not used

	for (int i = 1; i <= 8; i++) {
		cin >> t1 >> t2;

		if (t1 > t2) {
			results[i][0] = (char) (i*2 + (int) 'A' - 2);
		}	else {
			results[i][0] = (char) (i*2 + (int) 'A' - 1);	
		}

		// cout << (char) (i*2 + (int) 'A' - 2) << t1 << " X " << t2 << 
		// 	(char) (i*2 + (int) 'A' - 1) << endl;
		// cout << results[i][0] << endl;
	}

	for (int i = 1; i <= 4; i++) {
		cin >> t1 >> t2;

		if (t1 > t2) 
			results[i][1] = results[i*2 - 1][0];
		else 
			results[i][1] = results[i*2][0];		

		// cout << results[i*2 - 1][0] << t1 << " X " << t2 << 
		// 	results[i*2][0] << endl;
		// cout << results[i][1] << endl;
	}

	for (int i = 1; i <= 2; i++) {
		cin >> t1 >> t2;

		if (t1 > t2) 
			results[i][2] = results[i*2 - 1][1];
		else 
			results[i][2] = results[i*2][1];	
	}

	cin >> t1 >> t2;
	if (t1 > t2) 
		cout << results[1][2] << endl;
	else 
		cout << results[2][2] << endl;	
}
