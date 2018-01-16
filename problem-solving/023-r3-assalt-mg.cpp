/*
 * Alberto Ueda - DCC/UFMG
 * 2017-12-24

http://br.spoj.com/problems/ASSALTMG/
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;		

#define INFINITE_D 21 // max_d + 1

vector<int> keys;

void print_bits(int bits) {

	for (int i = 31; i >= 0; i--) {
		if ((bits & 1 << i) != 0)
			cout << "1";
		else
			cout << "0";
	}
	cout << endl;	

	cout << "popcount: " << __builtin_popcount(bits) << endl;
}

// return the min number of directors required
int solve(int d, int cur_keys, int m) {
	// cout << "d = " << d << endl;

	if (__builtin_popcount(cur_keys) >= m) {
		// cout << ">= m ! : "; print_bits(cur_keys);
		return 0;
	}

	if (d >= keys.size())
		return INFINITE_D;

	int wo_d = solve(d+1, cur_keys, m);
	// cout << "d = " << d << ": wo_d = " << wo_d << ": "; print_bits(cur_keys); 

	cur_keys = cur_keys | keys[d];
	int with_d = 1 + solve(d+1, cur_keys, m);
	// cout << "d = " << d << ": wi_d = " << with_d << ": "; print_bits(cur_keys); ;

	return min(wo_d, with_d);
}

int main() {	
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {

		int M, D;	
		cin >> M >> D;

		// each int is a bit representation of the keys of a director
		vector<int> tmp(D, 0);
		keys = tmp;

		for (int d = 0; d < D; d++) {
			int C;
			cin >> C;

			// read the keys of a director
			for (int c = 0; c < C; c++) {
				int key;
				cin >> key;

				keys[d] |= 1 << key;
			}
		}

		int answer = solve(0, 0, M);
		if (answer <= D)
			cout << answer << endl;
		else
			cout << "Desastre!" << endl;
	}

	//TODO try using unsigned ints
}