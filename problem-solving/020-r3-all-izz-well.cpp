/*
 * Alberto Ueda - DCC/UFMG
 * 2017-12-13

 http://www.spoj.com/problems/ALLIZWEL/

 Find whether there is a path in the given matrix which makes the sentence “ALL IZZ WELL”.

*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;		

int r, c;
vector<vector<char> > v;	
string word = "ALLIZZWELL";

// the trick is to use a new copy of the vector 'used'
bool find_path(int k, int i, int j, vector<vector<int> > used) {

	if (i < 0 || i >= r || j < 0 || j >= c)
		return false;

	if (v[i][j] != word[k] || used[i][j])
		return false;

	// DONE: the word path is complete
	if (k == word.size() - 1) {
		// cout << "  DONE! " << word[k] << " at " << i << "," << j << endl;
		return true;
	}

	// cout << word[k] << " found it! " << " at " << i << "," << j << endl;	
	used[i][j] = true;

	// try all neighbors of i,j
	if (find_path(k+1, i-1, j  , used)) return true;
	if (find_path(k+1, i+1, j  , used)) return true;
	if (find_path(k+1, i  , j-1, used)) return true;
	if (find_path(k+1, i  , j+1, used)) return true;			
	if (find_path(k+1, i-1, j-1, used)) return true;
	if (find_path(k+1, i-1, j+1, used)) return true;
	if (find_path(k+1, i+1, j-1, used)) return true;
	if (find_path(k+1, i+1, j+1, used)) return true;

	// cout << "    Not found at stack. " << t[k] << endl;
	return false;
}

int main() {	
	int t;
	cin >> t;

	for (int n = 0; n < t; n++) {	
		cin >> r >> c;				

		vector<vector<int> > used(r, vector<int>(c, 0));	
		vector<pair<int, int> > init;
		char x;

		vector<vector<char> > tmp(r, vector<char>(c));
		v = tmp;

		// read test case and select the possible initial positions
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {	

				cin >> x;
				v[i][j] = x;
				
				if (x == word[0]) 
					init.push_back(make_pair(i, j));
			}				 		
		}			
		
		// try to find any path from an initial position
		string answer = "NO";
		for (int m = 0; m < init.size(); m++) {
			if (find_path(0, init[m].first, init[m].second, used)) {
				answer = "YES";
				break;
			}
		}

		cout << answer << endl;
	}
}

// previous attempts
typedef pair<char, pair<int,int> > letter;

int main_with_queue_without_rollback() {	

	int t;
	cin >> t;

	for (int n = 0; n < t; n++) {		

		int r, c;
		cin >> r >> c;
		
		vector<vector<letter> > v(r, vector<letter>(c));	
		vector<vector<int> > used(r, vector<int>(c, 0));			
		stack<letter> s;			

		// read test case
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++) {	

				char x;
				cin >> x;
				
				letter l = make_pair(x, make_pair(i, j));
				v[i][j] = l;
				s.push(l);
			}				 					
		
		string t = "ALLIZZWELL";		
		string answer = "NO";

		for (int k = 0; k < t.size(); k++) {

			cout << "k=" << k << " : searching for " << t[k] << endl;			

			while (!s.empty() && 
				   (s.top().first != t[k] || (s.top().first == t[k] && used[s.top().second.first][s.top().second.second]))
				  )				 
				s.pop();
			
			if (s.empty())	{
				cout << "    Not found at stack. " << t[k] << endl;
				break;
			}

			if (k == t.size() - 1 && s.top().first == t[t.size() - 1]) {

				cout << "    DONE! " << s.top().first << " at " << s.top().second.first << "," << s.top().second.second << endl;
				answer = "YES";
				break;
			}

			// here l is equal to (t[k], (lr, lc))
			letter l = s.top();
			int lr = l.second.first;
			int lc = l.second.second;
			s.pop();

			cout << "    Found it! " << l.first << "(" << t[k] << ") at " << lr << "," << lc << endl;

			used[lr][lc] = true;

			// stack all neighbors of l
			if (lr > 0)   s.push(v[lr - 1][lc]);			
			if (lr < r-1) s.push(v[lr + 1][lc]);									
			if (lc > 0)   s.push(v[lr][lc - 1]);			
			if (lc < c-1) s.push(v[lr][lc + 1]);			

			if (lr > 0 && lc > 0)     s.push(v[lr - 1][lc - 1]);			
			if (lr > 0 && lc < c-1)   s.push(v[lr - 1][lc + 1]);			
			if (lr < r-1 && lc > 0)   s.push(v[lr + 1][lc - 1]);			
			if (lr < r-1 && lc < c-1) s.push(v[lr + 1][lc + 1]);			
		}

		cout << answer << endl;
	}
}


