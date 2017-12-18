/*
 * Alberto Ueda - DCC/UFMG
 * 2017-09-06
 
 http://br.spoj.com/problems/POSLIVRE/
 
 POSLIVRE - Posições Livres
 Escreva um programa que, dado um tabuleiro e uma lista de sub-partes retangulares do tabuleiro, retorna o número de posições que não pertencem a nenhuma sub-parte.
*/

#include <iostream>
using namespace std;

bool** board;

int count_free(int w, int h) {	
	int count = 0;

	for (int i = 1; i < w; i++)
		for (int j = 1; j < h; j++) {			
			// cout << "Trying to count free in board [" << i << "][" << j << "]" << endl;
			if (board[i][j] == 0) count++;
		}

	return count;	
}

void fill(int x1, int y1, int x2, int y2) {
	int lx, gx, ly, gy;

	if (x1 <= x2) { lx = x1; gx = x2; }
	else {		    lx = x2; gx = x1; }

	if (y1 <= y2) { ly = y1; gy = y2; }
	else { 			ly = y2; gy = y1; }


	for (int i = lx; i <= gx; i++)
		for (int j = ly; j <= gy; j++) {
			// cout << "Trying to access board[" << i << "][" << j << "]" << endl;
			board[i][j] = 1;
			// cout << "board[" << i << "][" << j << "] = 1" << endl;
		}
}

int main() {

	while(true) {

		int w, h, n;
		cin >> w >> h >> n;

		if (w == 0 && h == 0 && n == 0)
			break;

		// board[w][h]
		// Be careful with 0-based (program) x 1-based (input) !
		board = new bool* [w+1];
		for (int i = 1; i < w+1; i++)	{
			board[i] = new bool[h+1];
		}

		int x1, y1, x2, y2;

		for (int i = 0; i < n; i++)	{
			cin >> x1 >> y1 >> x2 >> y2;
			fill(x1, y1, x2, y2);
		}			
		
		int solution = count_free(w+1, h+1);
		
		if (solution == 0)
			cout << "There is no empty spots." << endl;
		else if (solution == 1)
			cout << "There is one empty spot." << endl;
		else		
			cout << "There are " << solution << " empty spots." << endl;

		// Good, but don't use this on SPOJ (SIGABRT, Runtime Error)
		// for (int i = 0; i < w; i++)	{
		// 	delete[] board[i];
		// }
		// delete[] board;
	}

}

