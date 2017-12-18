/*
 * Alberto Ueda - DCC/UFMG
 * 2017-12-13

 http://br.spoj.com/problems/POPULAR/

 Escrever um programa que, dadas as informações sobre simulações de preenchimento das cédulas, informe quantos votos recebeu o vencedor da eleição.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;		

int main() {	
	short n;

	while (true) {		
		cin >> n;
		if (n == 0) break;


		vector<short> v(n, 0);
		short maxv = 0, x;

		for (short i = 0; i < n; i++) {
			for (short j = 0; j < n; j++) {

				cin >> x;
				
				if (x) v[j]++;

				maxv = max(maxv, v[j]);
			}
		}
		
		cout << maxv << endl;
	}
}