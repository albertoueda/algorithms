/*
 * Alberto Ueda - DCC/UFMG
 * 2017-09-17

 http://br.spoj.com/problems/MARIO/

 Mário está muito ocupado com seus clientes e pediu que você fizesse um programa para determinar o número mínimo de trocas necessário para satisfazer o pedido de locação de um novo cliente.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;		

int count_swaps_2(int* v, int i, int n, int l) {
	int* pos = upper_bound(v+i, v+l, *(v+i) + n - 1);

	return n - ((pos - v) - i);
}

// Recap the using of pointers and arrays
int count_swaps(int* v, int i, int n, int l) {
	
	// the id the last locker would be
	int would_be = *(v+i) + n - 1;
	// cout << "  looking for: " << would_be << endl;

	// look forward only
	int* pos = lower_bound(v+i, v+l, would_be);
	// cout << "  *pos = " << *pos << " , pos = " << pos << endl;

	int free_l, used_l = 0;

	if (*pos != would_be && pos > v)
		pos--;

	free_l = (pos - v) - i + 1;  // wow
	used_l = n - free_l;
	
	// cout << "  free_l = " << free_l << " , used_l (tot) = " << used_l << endl;
	return used_l;
}

int main() {	

	while (true) {
		int n, l;
		cin >> n >> l;

		if (n == 0 && l == 0) 
			break;

		int v[l];
		for (int i = 0; i < l; i++) {
			cin >> v[i];
		}

		// int last = v[l-1];
		int min_swaps = n+1; // infinite
		int swaps;

		// Test each possibility for the begin of the allocation (a free locker)
		for (int i = 0; i < l; i++) {
			swaps = count_swaps_2(v, i, n, l);
			
			// cout << "result swaps = " << swaps << endl;
			if (min_swaps > swaps) 
				min_swaps = swaps;
		}

		cout << min_swaps << endl;
	}
}

// Idea: use a moving window to count the min number of swaps
// 1st window = [1..i..n], then 2nd window = [2..i..n+1] and so on.
void main_TLE() {	

	while (true) {
		int n, l;
		cin >> n >> l;

		if (n == 0 && l == 0) 
			break;

		// Avoids creating a vector of size 100'000, using
		// previously a temporary array instead
		int tmp[l];
		for (int i = 0; i < l; i++) {
			cin >> tmp[i];
		}

		int last = tmp[l-1];
		vector<int> v(last+1); // 1-based, locker 0 is not used

		// PROBLEM: TLE, Too memory used also
		// 'last' could be = 1'000'000'000

		for (int i = 0; i < l; i++) {
			int loc = tmp[i];
			v[loc] = true;			
		}

		// Count how many swaps are needed in the first n lockers
		int swaps = 0;
		for (int i = 1; i <= n; i++) {
			if (v[i] == false) // it must be swapped
				swaps++;
		}
		
		// Compare with all possibilities moving the window
		// one position per iteration
		int min_swaps = swaps;
		// cout << "min_swaps (1.." << n << "): " << min_swaps << endl;

		for (int i = n+1; i < last+1; i++) {

			// check the (wbegin-1)'th position of v (locker discarded from window)			
			int wbegin = i-n + 1;

			if (v[wbegin-1] == false)
				swaps--;
			
			// cout << "  (begin) v[" << wbegin-1 << "] = " << v[wbegin-1];

			// check the i'th position of v (locker added to window)
			if (v[i] == false) 
				swaps++;

			// cout << "  (end) v[" << i << "] = " << v[i] << endl;

			if (min_swaps > swaps) 
				min_swaps = swaps;

			// cout << "  swaps (" << wbegin << ".." << i << "): " << swaps << endl;
			// cout << "min_swaps (" << wbegin << ".." << i << "): " << min_swaps << endl;

		}

		cout << min_swaps << endl;
	}
}