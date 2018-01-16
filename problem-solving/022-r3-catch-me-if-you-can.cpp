/*
 * Alberto Ueda - DCC/UFMG
 * 2017-12-19

 http://www.spoj.com/problems/CMIYC/

 */

#include <iostream>
using namespace std;		

// after testing for p = 1, 2, 3... 10
int main() {	
	int t;	
	cin >> t;	

	long long p;	

	for (int i = 0; i < t; i++) {
		cin >> p;
		
		if (p % 3 == 0)			
			cout << p/3 << endl;				
		else
			cout << 0 << endl;				
	}

}

// Learned module of negative numbers in practice!
int main_v1_slow() {

	int t;	
	// cin >> t;	
	//t = 1;

	unsigned long int p;	

	//for (int i = 0; i<t; i++) {
	for (p = 1; p < 100; p++) {
		//cin >> p;
		// p = 100000000000000000; // 10^17
		// p = 100000000000000; // 10^14

		int r = 0, h = 0, dist;			

		while (true) {
			
			if (r + 1 < p)
				r = r + 1;
			else
				r = (r + 1) % p; // surprisingly, (%) is faster than (-) with -03 flag
			
			if (h - 2 >= 0)
				h = (h - 2);
			else
				//  = p - ((h-2) % p); // 1st version (it may be wrong)
				h = (h - 2) + p;

			//cout << r << "," << h << endl;
			if (r == h)
				break;
		}

		dist = r; // actually: r +1 (mod correction) -1 (dist)

		// cout << "r,h:" << r << "," << h << endl;
		cout << p << ": " << dist << endl;
	}

	return 0;
}

