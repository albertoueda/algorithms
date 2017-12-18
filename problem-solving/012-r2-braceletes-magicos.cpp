/*
 * Alberto Ueda - DCC/UFMG
 * 2017-09-07

 http://br.spoj.com/problems/BRACELMG/
 
 Para cada caso de teste, imprima uma linha contendo S se a sequência proibida está presente naquele bracelete e N se ela não está presente.
*/
#include <iostream>
using namespace std;

string reverse(string orig) {
	string r = orig;
	int n = orig.length();

	for (int i = 0; i < n; i++)
		r[i] = orig[n-i-1];

	return r;
}

bool find(string s, string orig) {
	
	// standard way
	auto found = orig.find(s);	

	if (found != string::npos)
		return true;

	// reversed
	string s_r = reverse(s);
	found = orig.find(s_r);

	if (found != string::npos)
		return true;

	// loop
	// each forbidden sequence has at most 100 caracters, each bracelet at most 10.000
	while (orig.length() < 20000) 
		orig.append(orig);

	if (orig.find(s) != string::npos || orig.find(s_r) != string::npos)
		return true;		

	return false;
}

int main() {

	int n;
	cin >> n;

	string seq, brac;

	for (int i = 0; i < n; i++) {
		cin >> seq >> brac;
		
		bool found = find(seq, brac);

		if (found)
			cout << "S" << endl;
		else
			cout << "N" << endl;
	}

}

