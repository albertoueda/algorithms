/*
 * Alberto Ueda - DCC/UFMG
 * 2017-12-18

 http://br.spoj.com/problems/DOMINO/

 */

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;		

#define mp(a, b) make_pair((a),(b)) 

// input board
vector<vector<int> > b(7, vector<int>(8, -1));

// board with piece ids
vector<vector<int> > bids(7, vector<int>(8, -1));

// values -> piece_id
map<pair<int,int>, int> m;

// 1-based
vector<int> used(29, 0); 

// num of solutions, max. pieces allocated (debug)
int s, top;

pair<int,int> find_empty(int i, int j) {

	// remaining of current line
	for (int b = j; b < 8; b++) {
		if (bids[i][b] == -1) {				
			return mp(i, b);
		}
	}

	// next lines
	for (int a = i+1; a < 7; a++)	{
		for (int b = 0; b < 8; b++) {
			if (bids[a][b] == -1) {				
				return mp(a, b);
			}
		}
	}

	return mp(-1, -1);
}

bool solve(int i, int j, int k) {	

	pair<int,int> ij = find_empty(i, j);
	i = ij.first; j = ij.second;
	// cout << string(k, ' ') << "next empty: " << ij.first << "," << ij.second << endl;

	// End
	if (i == -1) {
		for (int u = 1; u < used.size(); u++) {			
			if (!used[u]) { 
				// cout << "FAIL piece id " << u << " not used" << endl;
				return false;
			}
		}

		// cout << "SOLUTION FOUND!" << endl;						
		return true;
	}

	// both
	int v1 = b[i][j]; 

	// horizontally
	if (j+1 < 8 && bids[i][j+1] == -1) {

		int v2 = b[i][j+1];
		int id = m[make_pair(min(v1, v2), max(v1, v2))];	
		// cout << string(k, ' ') << v1 << "," << v2 << " ? (h)" << endl;

		if (!used[id]) {
		
			if (k > top) {
				// cout << string(k, ' ') << k << "# piece " << v1 << "," << v2 << " allocated!" << endl;
				top = k;
			}
			k++;

			used[id] = true;
			bids[i][j] = id; bids[i][j+1] = id;				

			// cout << string(k, ' ') << "Trying from " << i << "," << j+2 << "... (h)" << endl;
			if (solve(i, j+2, k)) {
				s++;
			}

			// cout << string(k, ' ') << "## rollback (h) " << v1 << "," << v2 << endl;
			bids[i][j] = -1; bids[i][j+1] = -1;				
			used[id] = false;
			k--;
		}
	}

	// vertically
	if (i+1 < 7 && bids[i+1][j] == -1) {

		int v2 = b[i+1][j];
		int id = m[make_pair(min(v1, v2), max(v1, v2))];
		// cout << string(k, ' ') << v1 << "," << v2 << " ? (v)" << endl;

		if (used[id]) {
			return false;
		}

		if (k > top) {
			// cout << string(k, ' ') << k << "# piece " << v1 << "," << v2 << " allocated!" << endl;
			top = k;
		}
		k++;

		used[id] = true;
		bids[i][j] = id; bids[i+1][j] = id;				

		// cout << string(k, ' ') << "Trying from " << i << "," << j+1 << "... (v)" << endl;
		if (solve(i, j+1, k)) {
			s++;
		} 
		
		// cout << string(k, ' ') << "## rollback (v) " << v1 << "," << v2 << endl;
		bids[i][j] = -1; bids[i+1][j] = -1;				
		used[id] = false;
		k--;		
	}

	return false;
}

int count_solutions() {
	s = 0;
	top = 0;

	solve(0, 0, 1);

	return s;
}

int main() {
	int n;
	cin >> n;

	m[mp(0,0)] =  1; m[mp(1,1)] =  8; m[mp(2,3)] = 15; m[mp(3,6)] = 22;
	m[mp(0,1)] =  2; m[mp(1,2)] =  9; m[mp(2,4)] = 16; m[mp(4,4)] = 23;
	m[mp(0,2)] =  3; m[mp(1,3)] = 10; m[mp(2,5)] = 17; m[mp(4,5)] = 24;
	m[mp(0,3)] =  4; m[mp(1,4)] = 11; m[mp(2,6)] = 18; m[mp(4,6)] = 25;
	m[mp(0,4)] =  5; m[mp(1,5)] = 12; m[mp(3,3)] = 19; m[mp(5,5)] = 26;
	m[mp(0,5)] =  6; m[mp(1,6)] = 13; m[mp(3,4)] = 20; m[mp(5,6)] = 27;
	m[mp(0,6)] =  7; m[mp(2,2)] = 14; m[mp(3,5)] = 21; m[mp(6,6)] = 28;

	// for each input case
	for (int k = 0; k < n; k++) {

		// read board
		for (int i = 0; i < 7; i++)
			for (int j = 0; j < 8; j++) 
				cin >> b[i][j];

		// count solutions
		cout << "Teste " << k+1 << endl << count_solutions() << endl << endl;

		// reset data
		vector<vector<int> > tmp(7, vector<int>(8, -1));
		b = tmp;
		bids = tmp;
	}
}
