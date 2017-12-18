/*
 * Alberto Ueda - DCC/UFMG
 * 2017-09-13

 http://br.spoj.com/problems/FUTEBOL/

 Escreva um programa que, dados os resultados de um campeonato de futebol, imprime a classificação correspondente seguindo o formato especificado.
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <iomanip> // setw()
#include <algorithm> // transform()
using namespace std;		

typedef struct {
	string name;
	int points;
	int games;
	int goals;
	int goals_r;
} info;

// all teams
unordered_map<string, info> teams;
vector<info> teams_sorted;
// unordered_map<int, vector<string> > p2t;

// I have tried to use a map comparator, but 
// I ended with a self-reference loop !
struct classcomp {
  bool operator() (const string& lhs, const string& rhs) const
  {
  	return lhs < rhs;
  	// return teams["a"]>teams["a"];
  }
};

info new_info(string name) {
	info x;
	x.name = name;
	x.points = 0;
	x.games = 0;
	x.goals = 0;
	x.goals_r = 0;

	return x;
}

void print(int pos, string t, bool print_pos) {
	info i = teams[t];	
	cout << right;
	
	// position in ranking
	if (print_pos)
		cout << setw(2) << pos << '.';
	else 
		cout << setw(3) << ' ';

	// other attributes
	cout << setw(16) << t;	
	cout << setw(4) << i.points;
	cout << setw(4) << i.games;
	cout << setw(4) << i.goals;
	cout << setw(4) << i.goals_r;
	cout << setw(4) << i.goals - i.goals_r;

	// success rate
	if (i.games == 0) {
		cout << setw(7) << "N/A";
	} else {
		float success = 100.00 * i.points / (i.games * 3);
		cout << setw(7) << fixed << setprecision(2) << success;	
	}

	cout << endl;
}

bool compare_teams(info t1, info t2) {

	if (t1.points != t2.points)
		return t1.points > t2.points;

	int balance1 = t1.goals - t1.goals_r;
	int balance2 = t2.goals - t2.goals_r;
	if (balance1 != balance2)
		return balance1 > balance2;

	if (t1.goals != t2.goals)
		return t1.goals > t2.goals;

	// OH GOD
	string lname1 = t1.name, lname2 = t2.name;
	transform(t1.name.begin(), t1.name.end(), lname1.begin(), ::tolower);
	transform(t2.name.begin(), t2.name.end(), lname2.begin(), ::tolower);
	
	return lname1 < lname2;
}

void sort_results() {
	// add all teams to a vector
	for (auto it = teams.begin(); it != teams.end(); it++)
		teams_sorted.push_back(it->second); // add a info

	// sort them
	sort(teams_sorted.begin(), teams_sorted.end(), compare_teams);
}

void print_table() {
	int pos = 1;
	int prev_points = -1, prev_balance = -1, prev_goals = -1;

	for (auto it = teams_sorted.begin(); it != teams_sorted.end(); it++, pos++) {		
		int balance = it->goals - it->goals_r;

		if (it->points != prev_points || balance != prev_balance || it->goals != prev_goals)
			print(pos, it->name, true);
		else 
			print(pos, it->name, false);

		prev_points = it->points;
		prev_balance = balance;
		prev_goals = it->goals;
	}
}

// The OUTPUT of this problem really demands effort!
int main() {	
	while (true) {
		int t, g; 
		cin >> t >> g;

		if (t == 0 && g == 0)
			break;

		// read teams
		string name;

		for (int i = 0; i < t; i++) {
			cin >> name;
			teams[name] = new_info(name);				
		}
		
		// read games
		string t1, t2, tmp;
		int s1, s2;

		for (int i = 0; i < g; i++) {
			cin >> t1 >> s1 >> tmp >> s2 >> t2;		
			
			// t1
			teams[t1].goals += s1;		
			teams[t1].goals_r += s2;
			teams[t1].games++;

			// t2
			teams[t2].goals += s2;
			teams[t2].goals_r += s1;
			teams[t2].games++;

			if (s1 > s2) {
				teams[t1].points += 3;		
			} 
			else if (s1 == s2) {
				teams[t1].points += 1;		
				teams[t2].points += 1;		
			} 
			else {
				teams[t2].points += 3;		
			}
		}	

		sort_results();
		print_table();		
		cout << endl;

		teams.clear();
		teams_sorted.clear();
	}
}