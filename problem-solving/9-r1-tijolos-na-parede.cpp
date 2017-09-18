/*
 * Alberto Ueda - DCC/UFMG
 * 2017-09-04
*/
#include <iostream>
#include <iomanip>
using namespace std;

// Version 2
int main() {
	int n;
	cin >> n;

	// For each instance k 
	for (int k = 0; k < n; k++) {

		int p[9][9];

		// Read
		for (int i = 0; i < 9; i += 2) {
			for (int j = 0; j <= i; j += 2) {
				cin >> p[i][j];
			}
		}

		// Solve last line (8)
		for (int j = 1; j < 9; j+=2) {
			p[8][j] = (p[6][j-1] - p[8][j-1] - p[8][j+1]) / 2;
		}

		// Solve remaining lines (0-7)
		for (int i = 7; i >= 0; i--) {
			for (int j = 0; j <= i; j++) {
				p[i][j] = p[i+1][j] + p[i+1][j+1];		
			}
		}		

		// Print solution
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j <= i; j++) {
				cout << p[i][j]; 
				if (j != i) cout << " "; 
			}
			cout << endl;
		}
	}

}

// Version 1
int main_v1() {	
	
	int n;
	cin >> n;

	int v[45];

	for (int i = 0; i < n; i++) {

		// Reading
		// read k numbers in each level, then skip s positions
		int pos = 0, k = 1;

		for (int s = 2; s <= 10; s+=2) {			

			for (int j = 0; j < k; j++) {
				cin >> v[pos];
				// cout << "v[" << pos << "] = " << v[pos] << endl;
				pos += 2;
			}

			pos -= 2;
			pos += s + 1;
			k++;
		}

		// Top-down I
		// The value of grandchild is the remaining value between her brothers and grandparent
		int pos_gp;
		pos = 4; k = 1;

		for (int s = 4, ss = 4; s <= 10; s+=2, ss+=4) {			

			for (int j = 0; j < k; j++) {
				pos_gp = pos - ss;				
				v[pos] = (v[pos_gp] - (v[pos-1] + v[pos+1])) / 2;
				pos += 2;
			}
			
			pos -= 2;
			pos += s + 3;
			k++;
		}

		// Top-down II	
		// The value of parent is the sum of her children's
		int pos_ch;
		pos = 1; k = 2;

		for (int s = 3, ss = 2; s <= 9; s+=2, ss+=2) {	

			for (int j = 0; j < k; j++) {

				pos_ch = pos + ss;
				v[pos] = v[pos_ch] + v[pos_ch+1];
				pos++;
			}
			
			pos -= 1;
			pos += s + 1;
			k += 2; 
		}

		// Printing
		int total = 1;
		k = 0;
		for (int j = 0; j < 45; j++) {
			cout << v[j];
			k++;

			if (k == total) {
				cout << endl;
				k = 0;
				total++;
			}
			else {
				cout << " ";
			}
		}
	}

}

