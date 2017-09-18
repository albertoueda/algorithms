/*
 * Alberto Ueda - DCC/UFMG
 * 2017-09-15
*/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <time.h>
using namespace std;		

clock_t t;
void start() { t = clock(); }
void finish() { cout << ((float)(clock() - t) / CLOCKS_PER_SEC) << " sec" << endl; }

// 3.9 sec for generated vector and n=300
long count_solutions(vector<vector<int> >& v, int n, bool stat) {

	for (int i = 0; i < 4; i++) 
		sort(v[i].begin(), v[i].end());

	long s = 0;

	if(stat) start();
	for (int i = 0; i < n; i++) {
		int sum = v[0][i]; // 1st element of 4

		for (int j = 0; j < n; j++) {
			sum += v[1][j];

			for (int k = 0; k < n; k++) {
				sum += v[2][k];

				for (int l = 0; l < n; l++) {
					sum += v[3][l];				
					if (sum == 0) {
						if(stat) {
							cout << v[0][i] << ' ';
							cout << v[1][j] << ' ';
							cout << v[2][k] << ' ';
							cout << v[3][l] << endl;						
						}
						s++;						
					}
					sum -= v[3][l];
				}
				sum -= v[2][k];
			}
			sum -= v[1][j];
		}
	}
	if(stat) finish();

	return s;
}


pair<int,int> bin_search(vector<int>& v, int p, int q, int x) {
	
	if (p > q) return make_pair(-1,-1);

	int m = (p + q) / 2;
	if (v[m] == x) {
		int first = m, last = m;

		while (v[first] == x) first--; 
		first++;

		while (v[last] == x) last++;
		last--;

		return make_pair(first, last);
	}

	if (v[m] > x)
		return bin_search(v, p, m-1, x);
	else
		return bin_search(v, m+1, q, x);
}

// O(n^3 * nlogn) AND W.A. :(
// 0.2 sec for generated vector and n=300
// 9.2 sec for generated vector and n=1000
long count_solutions_2(vector<vector<int> >& v, int n, bool stat) {

	// there may be repeated values! 
	for (int i = 0; i < 4; i++) {		
		set<int> s(v[i].begin(), v[i].end());
		v[i] = vector<int>(s.begin(), s.end());
	}

	long s = 0;
	int i, j, k, l, r;

	if (stat) start();
	for (i = 0; i < v[0].size(); i++) {
		long sum = v[0][i]; // 1st element of 4

		for (j = 0; j < v[1].size(); j++) {
			sum += v[1][j];

			for (k = 0; k < v[2].size(); k++) {
				sum += v[2][k];

				// now we already know which value we are looking for
				r = 0 - sum;
				// if (bin_search(v[3], 0, v[3].size(), r) == true) {
				// 	// cout << "found! " << r << endl;
				// 	s++;											
				// }
				
				sum -= v[2][k];
			}
			sum -= v[1][j];
		}
	}
	if (stat) finish();

	return s;
}

// 0.96 sec for generated vector and n=2500 :))
// 0.16 sec for generated vector and n=1000 :)
// Idea: all possibilities of sum between A and B, then all for C + D
// STILL W.A.!
long count_solutions_3(vector<vector<int> >& v, int n, bool stat) {
	
	if (stat) start();

	set<int> a(v[0].begin(), v[0].end());
	set<int> b(v[1].begin(), v[1].end());
	set<int> c(v[2].begin(), v[2].end());
	set<int> d(v[3].begin(), v[3].end());

	// with a set we do not count possibilities in which 2 values have the same sum
	// (previous version)
	vector<int> ab;
	for (set<int>::iterator it_a = a.begin(); it_a != a.end(); it_a++)
		for (set<int>::iterator it_b = b.begin(); it_b != b.end(); it_b++)
			ab.push_back(*it_a + *it_b);

	vector<int> cd;
	for (set<int>::iterator it_c = c.begin(); it_c != c.end(); it_c++)
		for (set<int>::iterator it_d = d.begin(); it_d != d.end(); it_d++)
			cd.push_back(*it_c + *it_d);

	sort(ab.begin(), ab.end());
	sort(cd.begin(), cd.end());

	long s = 0;	
	for (vector<int>::iterator it_ab = ab.begin(); it_ab != ab.end(); it_ab++) {		
		int r = 0 - *it_ab;
	
		// FIXED: for each element in ab, there may be multiple solutions in cd		
		vector<int>::iterator lb = lower_bound(cd.begin(), cd.end(), r);				
		vector<int>::iterator ub = upper_bound(cd.begin(), cd.end(), r);	

		cout << ub-lb << " new solutions for ab: " << *it_ab << " and cd: " << *lb;
		cout << " (r: " << r << ")" << endl; 
		s += ub - lb;
	}

	if (stat) finish();

	return s;
}

// ACCEPTED!
// I was wrong in removing duplicates in a column (e.g., A)
long count_solutions_4(vector<vector<int> >& v, int n, bool stat) {
	
	if (stat) start();

	vector<int> ab;
	for (vector<int>::iterator it_a = v[0].begin(); it_a != v[0].end(); it_a++)
		for (vector<int>::iterator it_b = v[1].begin(); it_b != v[1].end(); it_b++)
			ab.push_back(*it_a + *it_b);

	vector<int> cd;
	for (vector<int>::iterator it_c = v[2].begin(); it_c != v[2].end(); it_c++)
		for (vector<int>::iterator it_d = v[3].begin(); it_d != v[3].end(); it_d++)
			cd.push_back(*it_c + *it_d);

	sort(ab.begin(), ab.end());
	sort(cd.begin(), cd.end());

	long s = 0;	

	for (vector<int>::iterator it_ab = ab.begin(); it_ab != ab.end(); it_ab++) {		
		int r = 0 - *it_ab;

		vector<int>::iterator lb = lower_bound(cd.begin(), cd.end(), r);				
		vector<int>::iterator ub = upper_bound(cd.begin(), cd.end(), r);	

		// cout << ub-lb << " new solutions for ab: " << *it_ab << " and cd: " << *lb;
		// cout << " (r: " << r << ")" << endl; 
		s += ub - lb;
	}

	if (stat) finish();

	return s;
}

// A FASTER VERSION (but still TLE)
// TODO: tried to use bin-search, but no success (weird answer for 
// generated vector and TLE in SPOJ)
// with generated vector and n=2500: before: 7.9 sec, after: ??? sec
long count_solutions_5(vector<vector<int> >& v, int n, bool stat) {
	
	if (stat) start();

	vector<int> ab;
	ab.reserve(n*n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			ab.push_back(v[0][i] + v[1][j]);

	vector<int> cd;
	cd.reserve(n*n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cd.push_back(v[2][i] + v[3][j]);

	sort(ab.begin(), ab.end());
	sort(cd.begin(), cd.end());

	long s = 0;	
	vector<int>::iterator lb, ub;

	for (int i = 0; i < n*n; i++) {
		int r = 0 - ab[i];

		// IMPROV: bin search + checking neighbors?
		// lb = lower_bound(cd.begin(), cd.end(), r);				
		// ub = upper_bound(lb, cd.end(), r);	
		pair<int, int> pos = bin_search(cd, 0, n*n-1, r);

		if (pos.first != -1) {
			// cout << ub-lb << " new solutions for ab: " << *it_ab << " and cd: " << *lb;
			// cout << " (r: " << r << ")" << endl; 
			s += pos.second - pos.first + 1;			
		}

	}

	if (stat) finish();

	return s;
}

vector<vector<int> >* generate_v(int n) {	
	vector<vector<int> >* v = new vector<vector<int> >(4, vector<int>(n));
	
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < n; j++)
			(*v)[i][j] = j;

	return v;
}

int main() {	
	int n;

	cin >> n;
	vector<vector<int> > v(4, vector<int>(n));
	for (int i = 0; i < n; i++) {
		cin >> v[0][i];
		cin >> v[1][i];
		cin >> v[2][i];
		cin >> v[3][i];
	}

	// n = 2500; // 300 2500
	// vector<vector<int> > v = *generate_v(n);

	cout << count_solutions_4(v, n, false) << endl;
}