/*
 * Alberto Ueda - DCC/UFMG
 * 2017-09-16

 https://icpcarchive.ecs.baylor.edu/index.php?option=onlinejudge&page=show_problem&problem=3061

 Given the initial strength of all contestants, determine who will win the tournament and which contestant he will beat.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <math.h>
using namespace std;		

// Queues, unordered_map, pairs, and vectors 
//
// I have attempted to use 'short' variables, but get W.A. 
// and then replaced all for usual 'int's
int main() {
	int t;
	cin >> t;
	
	// for each instance k
	for (int i = 0; i < t; i++) {

		int n, k;
		cin >> n >> k;

		unordered_map<int, pair<int, queue<int> > > p;
		vector<int> initial_p(pow(2,n)+1);
		queue<int> w; 

		// 1-based
		for (int j = 1, jmax = pow(2, n); j <= jmax; j++) {
			int new_p; 
			pair<int, queue<int> > new_pair;
			queue<int> new_queue;

			cin >> new_p;
			new_pair = make_pair(new_p, new_queue);
			p[j] = new_pair;
			initial_p[j] = new_p;

			w.push(j);
		}

		int id1, id2;
		while (!w.empty()) {
			// Ready?
			id1 = w.front(); w.pop();
			if (w.empty()) // we have a winner! id1
				break;

			id2 = w.front(); w.pop();

			// Fight!
			if (p[id1].first > p[id2].first || 
				(p[id1].first == p[id2].first && id1 < id2)) {
				w.push(id1);
				p[id1].second.push(id2);

				// reducing power and recover
				p[id1].first = p[id1].first - p[id2].first + k;

				if (p[id1].first > initial_p[id1])
					p[id1].first = initial_p[id1];
			}
			else {
				w.push(id2);
				p[id2].second.push(id1);
				p[id2].first = p[id2].first - p[id1].first + k;
				
				if (p[id2].first > initial_p[id2])
					p[id2].first = initial_p[id2];
			}
		}

		// Printing
		cout << id1 << endl;
		while (!p[id1].second.empty()) {
			cout << p[id1].second.front(); 
			p[id1].second.pop();
			
			if (!p[id1].second.empty())
				cout << ' ';
		}
		cout << endl;
	}
}