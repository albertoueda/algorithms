/*
 * Alberto Ueda - DCC/UFMG
 * 2017-09-24
*/
#include <iostream>
#include <vector>
#include <numeric> // accumulate, inner_product
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

void set_operations() {
	int data[] = {1, 3, 5, 7, 9, 11};
	int data2[] = {3, 6, 9, 12};

	vector<int> d(data, data + sizeof(data)/sizeof(data[0]));
	vector<int> d2(data2, data2 + 4);
	vector<int> r( max(d.size(), d2.size()) );

	cout << "set_intersection: ";
	set_intersection(d.begin(), d.end(), d2.begin(), d2.end(), r.begin());
	for (int i = 0; i < r.size(); i++) cout << r[i] << ' ';

	cout << "\nset_union: ";
	r.resize(d.size() + d2.size());
	set_union(d.begin(), d.end(), d2.begin(), d2.end(), r.begin());
	for (int i = 0; i < r.size(); i++) cout << r[i] << ' ';

	cout << "\nset_difference: ";
	set_difference(d.begin(), d.end(), d2.begin(), d2.end(), r.begin());
	for (int i = 0; i < r.size(); i++) cout << r[i] << ' ';
	r.clear();

	cout << "\nset_symmetric_diff: ";
	r.resize(d.size() + d2.size());
	set_symmetric_difference(d.begin(), d.end(), d2.begin(), d2.end(), r.begin());
	for (int i = 0; i < r.size(); i++) cout << r[i] << ' ';

	cout << "\nvector copied: ";
	copy(d.begin(), d.end(), d2.begin());
	for (int i = 0; i < d2.size(); i++) cout << d2[i] << ' ';

	cout << endl;
}

void accumulate_and_inner_product() {	
	int data[] = {1, 3, 5, 7, 9, 11}; vector<int> d(data, data + sizeof(data)/sizeof(data[0]));
	int data2[] = {3, 6, 9, 12}; vector<int> d2(data2, data2 + sizeof(data2)/sizeof(data2[0]));

	cout << "accumulate(d2.begin(), d2.end(), 0): " << accumulate(d2.begin(), d2.end(), 0) << endl;
	cout << "accumulate(d2.begin(), d2.end(), (long long) 10): " 
		<< accumulate(d2.begin(), d2.end(), (long long) 10) << endl;

	cout << "accumulate(d2.begin(), d2.end()-2, 1, multiplies<int>()): " 
		<< accumulate(d2.begin(), d2.end()-2, 1, multiplies<int>()) << endl;

	cout << "inner_product(d2.begin(), d2.end()-2, d.begin(), 0): " 
		<< inner_product(d2.begin(), d2.end()-2, d.begin(), 0) << endl;
}

// TopCoder example of custom compare function
struct fraction { 
      int n, d; // (n/d) 
      bool operator < (const fraction& f) const { 
           if(false) { 
                return (double(n)/d) < (double(f.n)/f.d); 
           } 
           else { 
                return n*f.d < f.n*d; 
           } 
      } 
 }; 
 // RULE: all comparison is based on 'operator <'
 // 
 // Also remember that 'operator <' should always return false for equal objects. 
 // It's very important.
 //
 // To store a new struct in maps/sets, we need to implement the < operator. 
  
// SWAP deallocate not used memory
// vector<int> v; 
// // ... fill v 
// vector<int>(all(v)).swap(v); 


int main() {
	// set_operations();
	// accumulate_and_inner_product();

	// TODO DFS
	// for_each(all(W[i]), dfs); 
}
















