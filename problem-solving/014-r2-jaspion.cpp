/*
 * Alberto Ueda - DCC/UFMG
 * 2017-09-09
*/
#include <iostream>
#include <sstream>
#include <string>
#include <map>
using namespace std;		

// Use of 'getline' and 'cin.ignore' :)
int main() {
	int k, m, n; 
	string jp, pt, verse;

	cin >> k;

	for (int i = 0; i < k; i++) {
		cin >> m >> n;

		map<string,string> d;

		// Read dictionary
		for (int j = 0; j < m; j++) {
			cin >> jp;
			cin.ignore();
			getline(cin, pt);

			d[jp] = pt;
		}

		// Translate each line
		for (int j = 0; j < n; j++) {

			getline(cin, verse);

			istringstream is(verse);
			string w;			

			if (!(is >> w)) {
				cout << endl;
				break;
			}

			while(true) {
				if (d.find(w) != d.end())
					cout << d[w];
				else
					cout << w;

				if ((is >> w))
					cout << " ";
				else
					break;
			}
			cout << endl;
		}

		cout << endl;
	}
	
}