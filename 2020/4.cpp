#include <iostream>
#include <fstream>

using namespace std;

const int max_n = 100;

int field[max_n][max_n];

int mtrx1[max_n][max_n];
int mtrx2[max_n][max_n];


int min(int n1, int n2);
int main()
{
	setlocale(LC_CTYPE, "rus");

	ifstream fin = ifstream("file.txt");

	int n, m, p_x, p_y;
	fin >> n >> m;

	fin >> p_y >> p_x;
	p_y--; p_x--;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			fin >> field[i][j];

	for (int i = 0; i <= p_y; i++) {
		for (int j = 0; j <= p_x; j++) {
			cout << field[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl;

	for (int i = p_y; i < n; i++) {
		for (int j = p_x; j < m; j++) {
			cout << field[i][j] << " ";
		}
		cout << endl;
	}
	
	// fill first matrix
	for (int i = 0; i <= p_y; i++) 
		mtrx1[0][i] = field[0][i];
	

	for (int i = 0; i <= p_x; i++)
		mtrx1[i][0] = field[i][0];

	for (int i = 1; i <= p_y; i++)
		for (int j = 1; j <= p_x; j++)
			mtrx1[i][j] = field[i][j] + min(mtrx1[i - 1][j], mtrx1[i][j - 1]);


}

int min(int n1, int n2) {
	return (n1 > n2) ? n2 : n1;
}
