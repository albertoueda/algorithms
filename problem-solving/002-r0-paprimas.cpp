/*
 * Alberto Ueda - DCC/UFMG
 * 2017-08-30

 http://br.spoj.com/problems/PAPRIMAS/

PAPRIMAS - Palavras primas
Um número primo é um número que possui somente dois divisores: ele mesmo e o número 1. Exemplos de números primos são: 1, 2, 3, 5, 17, 101 e 10007.

Neste problema você deve ler um conjunto de palavras, onde cada palavra é composta somente por letras no intervalo a-z e A-Z. Cada letra possui um valor específico, a letra a vale 1, a letra b vale 2 e assim por diante, até a letra z, que vale 26. Do mesmo modo, a letra A vale 27, a letra B vale 28 e a letra Z vale 52.

Você deve escrever um programa para determinar se uma palavra é uma palavra prima ou não. Uma palavra é uma palavra prima se a soma de suas letras é um número primo.
*/

#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;

bool isprime(int n) {

	// IMPROVMENT: max value could be sqrt(n)
	for (int i = 2; i <= n/2; i++) 
		if ((n % i) == 0) return false;			

	return true;
}

int main() {	
	string s;

	while (true) {
		cin >> s;

		if (!cin)
			break;

		int sum = 0;

		for (int i = 0; i < s.size(); i++) {
			int ints = (int) s[i];

			if (ints > 96)
				ints -= 96;
			else
				ints -= 38;
			
			// cout << ints << endl;
			sum += ints;
		}

		// cout << sum << " -> ";
		if (isprime(sum))
			cout << "It is a prime word." << endl;
		else
			cout << "It is not a prime word." << endl;
	}

}