/*
 * Alberto Ueda - DCC/UFMG
 * 2017-09-09
*/
#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
#include <time.h>
using namespace std;		

clock_t t;

void start() {
	t = clock();
}

void finish() {
	cout << t << " cticks (" << ((float) (clock() - t) / CLOCKS_PER_SEC) << " sec)" << endl;
}

// [p ... r ... q]
int bin_search_1st(int x, const vector<int>& v, int p, int q) {
	
	if (p > q)
		return -1;

	int r = (q + p)/2;
	// cout << "Searching in position " << r << endl;

	if (v[r] == x) {
		while (r >= 0 && v[r] == x) r--;
		return ++r;
	}

	if (v[r] > x)
		return bin_search_1st(x, v, p, r-1);
	else 
		return bin_search_1st(x, v, r+1, q);
}

void test_performance() {

	int n = 10'000'000, q = 10'000'000; // C++14 Notation
	vector<int> v(n);
	// v.resize(n);

	srand (time(NULL));
	int random = 0; 

	start();
	for (int i = 0; i < n; i++) {
		random = random + rand() % 100'000;
		v[i] = random;
		// cout << random << ' ';
	}
	// cout << random << endl;
	
	random = 0;
	for (int i = 0; i < q; i++) {
		int pos = -1;		
		
		random = random + rand() % 100'000;
		// cout << random << ' ';
		pos = bin_search_1st(random, v, 0, n-1);

		// cout << pos << endl;	
	}
	finish();
	// cout << random << endl;
}

// To solve this problem within the time limit requirement,
// it was need to replace iostream by scanf/printf !
int main() {
	int n, q;
	scanf("%d %d", &n, &q);

	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}
	
	int x;
	for (int i = 0; i < q; i++) {
		scanf("%d", &x);
		printf("%d\n", bin_search_1st(x, v, 0, n-1));
	}

	// test_performance();	
}