/*
 * Alberto Ueda - DCC/UFMG
 * 2017-09-05
   http://br.spoj.com/problems/OBIPOKER/
*/
#include <iostream>
#include <algorithm>
using namespace std;

int how_many(int c[]) {

	sort(c, c + 5);

	// straight
	for (int i=0; i<4; i++) {
		if (c[i] != c[i+1] - 1)
			break;				
		if (i == 3) 
			return c[0] + 200;
	}

	// four of a kind
	if ((c[0] == c[1] && c[1] == c[2] && c[2] == c[3] ) ||
						(c[1] == c[2] && c[2] == c[3] && c[3] == c[4]))
		return c[1] + 180;


	// full house
	if ((c[0] == c[1] && c[1] == c[2] && c[3] == c[4]) ||
		(c[0] == c[1] && c[2] == c[3] && c[3] == c[4]))
		return c[2] + 160;

	// from now on we can ignore the previous possibilities

	// three of a kind
	if ((c[0] == c[1] && c[1] == c[2]) ||
		(c[1] == c[2] && c[2] == c[3]) || 
		(c[2] == c[3] && c[3] == c[4]) )
		return c[2] + 140;

	// two pairs
	if ((c[1] == c[2] && c[3] == c[4]) ||
		(c[0] == c[1] && c[3] == c[4]) || 
		(c[0] == c[1] && c[2] == c[3]) )
		return 3*c[3] + 2*c[1] + 20;

	// single pair
	if (c[0] == c[1]) return c[0];
	if (c[1] == c[2]) return c[1];
	if (c[2] == c[3]) return c[2];
	if (c[3] == c[4]) return c[3];

	return 0;
}

int main() {

	int n, round = 1, c[5];
	cin >> n;

	for (int i = 0; i < n; i++) {
	
		for (int j = 0; j < 5; j++)	
			cin >> c[j];
		
		int points = how_many(c);

		cout << "Teste " << round++ << endl;
		cout << points << endl;
		cout << endl;
	}

}

