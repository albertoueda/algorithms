/*
 * Alberto Ueda - DCC/UFMG
 * 2017-09-04
   https://www.urionlinejudge.com.br/judge/pt/problems/view/1435
*/
#include <iostream>
#include <iomanip>
#include <string.h>
#include <math.h>
using namespace std;

// Version 2 :)
int main() {	
	
	int n;

	while (true) {				
		cin >> n;
		if (n == 0 || !cin)
			break;

		int m[n][n];

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) 
				m[i][j] = 1;

		for (int k = 1; k <= (n-1)/2; k++)
			for (int i = 0 + k; i < n - k; i++)
				for (int j = 0 + k; j < n - k; j++) 		
					m[i][j] += 1;	

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

