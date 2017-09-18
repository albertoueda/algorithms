/*
 * Alberto Ueda - DCC/UFMG
 * 2017-09-09
*/
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <sstream>
#include <limits>
#include <algorithm>
 
using namespace std;

// Macros from TopCoder STL Tutorial
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 

// #define all(v) v.begin(), v.end()

// Compilation Error: 'typeof' (GNU) is not recognized
// #define tr(c, it) for(__typeof__((c).begin()) it = (c).begin(); it != (c).end(); it++)


// Time measurement
clock_t t;

void start() {
	t = clock();
}

void finish() {
	cout << clock()-t << " cticks (" << ((float) (clock() - t) / CLOCKS_PER_SEC) << " sec)" << endl;
}


void modify(vector<int>& v, const vector<int>& a) {
	v[0]++;
	// a[0]++; // Compilation error (const variable)
}

template<typename T> void show(T first, T last) {
	// using iterators, try to always avoid "<" comparisons,
	// using "==, !=" instead
	for (; first != last; first++)
		cout << *first << " ";
	cout << endl;
}

void show_3rd(const vector<int>& container) {
	vector<int>::const_iterator it = container.begin();

	it += 2;
	cout << *it << endl;
}

void f(const vector<int>& v) { 
      int r = 0; 

      cout << "traversal: ";
      tr(v, it) { 
           cout << (*it) << " "; 
      } 
      cout << endl;
 } 

int main() {
	vector<int> v(10, 0);

	// modify
	cout << v[0] << " ";
	modify(v, v);
	cout << v[0] << endl;

	// show
	show(v.begin(), v.end());
	cout << "with all(v): "; show(all(v));

	// reverse
	int a[] = {1, 2, 3, 4};
	vector<int> w(a, a + 4);
	show(w.begin(), w.end());

	reverse(a, a+4);
	vector<int> w_r(a, a + 4);
	show(w_r.begin(), w_r.end());
	show(w.rbegin(), w.rend());

	// iterator
	show_3rd(w);
	show_3rd(w_r);

	// traversal
	f(w);

	// string substr: how many it will cut and how many will be printed
	string s = "study";
	cout << "s = study --> s.substr(2) = " << s.substr(2);
	cout << " and s.substr(2,1) = " << s.substr(2,1) << endl;

		// be careful!
		unsigned z = 0;
		cout << z - 1 << endl;

	// set --> removal of duplicates and sort trick
	int numbers[] = {3, 2, 1, 1, 10, 5};
	set<int> my_set(numbers, numbers + 6);
	show(all(my_set));
	vector<int> numbers_from_set(all(my_set));
	show(all(numbers_from_set));

	// map
	map<int, string> m;
	m[0] = "hello";
	if (m.find(1) == m.end()) 
		cout << "m[1] not found." << endl;
	
	if (m[1] != "i have just born") {  // be careful! Use "find" instead
		cout << m[0] << ", look that: " << m[1];
		if (m.find(1) != m.end()) cout << " m[1] found!" << endl;
	}

	// map and set --> internally are red black trees
	// don't change the keys while traversing!

	do { 
		cout << "Will I exist?" << endl;
	} while(false);

	// stringstream
	string text = "text 1 2 3";
	istringstream is(text);
	ostringstream os(text);

	cout << "os before: " << os.str() << endl;

	vector<string> words; 
	string tmp;

	if (is)
		cout << "is is true" << endl;
	while (is >> tmp) {
		cout << tmp << "-";
		words.push_back(tmp);
	}
	cout << endl;
	if (!is)
		cout << "false/true check works on is" << endl;

	for (vector<string>::iterator it = words.begin(); it != words.end(); it++) 
		os << *it << "#";
	cout << "os after: " << os.str() << endl; //TODO why the initial text was erased?

	// next permutation
	int sequence[] = {3, 2, 4, 1};
	vector<int> seq(sequence, sequence + 4);
	cout << "Next Permutations: " << endl;
	do {
		show(all(seq)); 
	} while (next_permutation(all(seq)));

	// Numerical limit
	cout << std::numeric_limits<int>::min() << endl;
	cout << std::numeric_limits<int>::max() << endl << endl;

	// Lower/Upper Bound 
	int ints[] = {1, 3, 6, 7, 7, 20, 8, 10};
	vector<int> v_ints(ints, ints+7);

	vector<int>::iterator lb = lower_bound(v_ints.begin(), v_ints.end(), 7);
	vector<int>::iterator ub = upper_bound(v_ints.begin(), v_ints.end(), 7);

	cout << "lower_bound(7): pos=" << lb - v_ints.begin() << ", value=" << *lb << endl;
	cout << "upper_bound(7): pos=" << ub - v_ints.begin()<< ", value=" << *ub << endl << endl;


}


// Classcomp (e.g., for maps)
struct classcomp {
  bool operator() (const char& lhs, const char& rhs) const
  {return lhs<rhs;}
};