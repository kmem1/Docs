#include <iostream>

using namespace std;

const int max_n = 100;
const int no_way = -1;

int W[max_n][max_n];

int col[max_n];

int ostov[max_n][2];

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		col[i] = i;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			W[i][j] = no_way;
	}

  // no input
	W[0][1] = 2;
	W[0][2] = 4;
	W[1][2] = 9;
	W[1][3] = 7;
	W[2][4] = 1;
	W[2][3] = 8;
	W[3][4] = 3;
	W[3][5] = 1;
	W[4][5] = 2;

	for (int k = 0; k < n - 1; k++) {
		int min = INT_MAX;
		int i_min, j_min;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (W[i][j] != no_way && col[i] != col[j] && W[i][j] < min) {
					min = W[i][j];
					i_min = i;
					j_min = j;
				}
			}
		}
		ostov[k][0] = i_min;
		ostov[k][1] = j_min;

		for (int i = 0; i < n; i++)
			if (col[i] == col[j_min])
				col[i] = col[i_min];
	}

	for (int i = 0; i < n - 1; i++)
		cout << ostov[i][0] << " - " << ostov[i][1] << endl;
}
