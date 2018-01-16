/*
 * Alberto Ueda - DCC/UFMG
 * 2017-12-30

   http://www.spoj.com/problems/INVCNT/
 */

#include <iostream>
#include <algorithm>
using namespace std;		

// W.A. if we use int, ok if we use long long

long long merge(int a[], int p, int r, int q) {

	int size = q - p + 1;
	int sorted[size];
	long long inv = 0;

	int lk = p, rk = r+1;
	// cout << "p:" << p << ", r:" << r << ", q:" << q << endl;

	for (int k = 0; k < size; k++) {

		if ((a[lk] > a[rk] && rk <= q) || lk > r) {
			sorted[k] = a[rk];
			if (lk <= r) {
				// cout << "Found " << r-lk+1 << " inversions for right: " << a[rk] << endl;
				inv += r - lk + 1; // e.g.: 1 (3 4 5) 2 6 7;
			}
			rk++;
		}
		else {
			sorted[k] = a[lk];
			lk++;
		}

		// cout << "k=" << k << " : " << sorted[k] << endl;
	}

	// cout << endl << "i: ";
	// for (int i = p; i < q+1; i++)
	// 	cout << a[i] << " ";

	copy(sorted, sorted+size, a+p);

	// cout << endl << "f: ";
	// for (int i = p; i < q+1; i++)
	// 	cout << a[i] << " ";
	// cout << endl;

	return inv;
}


// mergesort-based
long long count_inv(int a[], int p, int q) {

	if (p >= q)
		return 0;

	int r = (p+q)/2;

	long long left = count_inv(a, p, r);
	long long right = count_inv(a, r+1, q);
	long long merge_result = merge(a, p, r, q);

	return left + right + merge_result;
}

int main() 
{
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) { 		
		int n;
		cin >> n;

		int a[n];

		for (int k = 0; k < n; k++)
			cin >> a[k];

		// merge(a, 0, n/2, n-1);
		cout << count_inv(a, 0, n-1) << endl;

		// cout << endl << "f: ";
		// for (int i = 0; i < n; i++)
		// 	cout << a[i] << " ";
		// cout << endl;
	}
}
