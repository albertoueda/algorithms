/*
 * Alberto Ueda - DCC/UFMG
 * 2017-01-16

   https://www.urionlinejudge.com.br/judge/pt/problems/view/1088
 */

#include <iostream>
#include <algorithm>
using namespace std;		

long long merge(int a[], int p, int r, int q) {

	int size = q - p + 1;
	int sorted[size];
	long long inv = 0;

	int lk = p, rk = r+1;

	for (int k = 0; k < size; k++) {

		if ((a[lk] > a[rk] && rk <= q) || lk > r) {
			sorted[k] = a[rk];
			if (lk <= r) {
				inv += r - lk + 1;
			}
			rk++;
		}
		else {
			sorted[k] = a[lk];
			lk++;
		}		
	}

	copy(sorted, sorted+size, a+p);

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

// Accepted. O(n log(n))
int main_nlogn() 
{
	while(true) {
		int n;
		cin >> n;

		if (n == 0)
			break;

		int a[n];

		for (int k = 0; k < n; k++)
			cin >> a[k];

		long long invs = count_inv(a, 0, n-1);

		if (invs % 2 == 0)
			cout << "Carlos" << endl;
		else
			cout << "Marcelo" << endl;
	}
}

// Also accepted. O(n)
int main() 
{
	while(true) {
		int n;
		cin >> n;

		if (n == 0)
			break;

		int a[n+1]; // 1-based		

		for (int k = 1; k <= n; k++) 
			cin >> a[k];

		long long invs = 0;

		for (int k = 1; k < n+1; k++) {

			if (a[k] == k)
				continue;

			invs += 2 * (a[k] - k) - 1;
			swap(a[k], a[a[k]]);
			k--;
		}

		if (invs % 2 == 0)
			cout << "Carlos" << endl;
		else
			cout << "Marcelo" << endl;
	}
}
