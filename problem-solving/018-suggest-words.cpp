#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;

set<string> wordlist;

void load_dict(string path) {
	std::ifstream infile(path.c_str());

	string w;
	while (infile >> w) {
		wordlist.insert(w);
	}
}

//TODO Deal with accents
int main() {

	// problem input
	char l[] = {'p', 'e', 'ô', 'u', 'z', 'p', 'q', 'a', 'a', 'e', 'r', 'v'};
	//char l[] = {'o', 'v', 'o', 'c'};
	unsigned ws = 6;
	load_dict("../misc/brazilian");

	unsigned s = sizeof(l)/sizeof(char);
	sort(l, l+s);
	set<string> found;

	do {		
		char new_w[ws];

		for (int i = 0; i < ws; i++) {
			new_w[i] = l[i];			
		}
		new_w[ws] = '\0';

		// problem specific
		// new_w[ws-1] = 'o';
		
		if (wordlist.find(new_w) != wordlist.end() && found.find(new_w) == found.end()) {
			found.insert(new_w);
			cout << new_w << endl;						
		}

	} while (next_permutation(l, l+s));

}