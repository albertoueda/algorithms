/*
 * Alberto Ueda - DCC/UFMG
 * 2017-08-31
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