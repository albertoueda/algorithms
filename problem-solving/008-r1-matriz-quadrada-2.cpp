/*
 * Alberto Ueda - DCC/UFMG
 * 2017-09-04
   https://www.urionlinejudge.com.br/judge/pt/problems/view/1478
*/
#include <iostream>
#include <iomanip>
#include <string.h>
#include <math.h>
using namespace std;

int main() {	
	
	int n;

	while (true) {				
		cin >> n;
		if (n == 0 || !cin)
			break;

		int m[n][n];

		// for (int i = 0; i < n; i++)
		// 	for (int j = 0; j < n; j++) 
		// 		m[i][j] = 0;

		for (int k = 0; k < n; k++) {
			int x = 1;									
			for (int j = 0 + k; j < n; j++) 
				m[0+k][j] = x++;	

			x = 1;		
			for (int i = 0 + k; i < n; i++) 		
				m[i][0+k] = x++;	
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {				
				cout << right << setw(3) << m[i][j];
				if (j < n-1) cout << ' ';
			}
			cout << endl;
		}
		
		cout << endl;
	}
}

