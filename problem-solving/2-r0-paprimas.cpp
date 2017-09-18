/*
 * Alberto Ueda - DCC/UFMG
 * 2017-08-30
*/

#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;

bool isprime(int n) {

	// IMPROVMENT: max value could be sqrt(n)
	for (int i = 2; i <= n/2; i++) 
		if ((n % i) == 0) return false;			

	return true;
}

int main() {	
	string s;

	while (true) {
		cin >> s;

		if (!cin)
			break;

		int sum = 0;

		for (int i = 0; i < s.size(); i++) {
			int ints = (int) s[i];

			if (ints > 96)
				ints -= 96;
			else
				ints -= 38;
			
			// cout << ints << endl;
			sum += ints;
		}

		// cout << sum << " -> ";
		if (isprime(sum))
			cout << "It is a prime word." << endl;
		else
			cout << "It is not a prime word." << endl;
	}

}