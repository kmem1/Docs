#include <iostream>

using namespace std;

const int max_n = 100;
const int no_way = -1;

int W[max_n][max_n];
int R[max_n];
int P[max_n];
bool active[max_n];

char alphabet[] = { 'A', 'B', 'C', 'D', 'E', 'F' };

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j)
				W[i][j] = 0;
			else
				W[i][j] = no_way;
		}
	}

	// no input
	W[0][1] = 2;
	W[1][0] = 2;
	W[0][2] = 4;
	W[2][0] = 4;
	W[1][2] = 9;
	W[2][1] = 9;
	W[1][3] = 7;
	W[3][1] = 7;
	W[2][4] = 1;
	W[4][2] = 1;
	W[2][3] = 8;
	W[3][2] = 8;
	W[3][4] = 3;
	W[4][3] = 3;
	W[3][5] = 1;
	W[5][3] = 1;
	W[4][5] = 2;
	W[5][4] = 2;

	for (int i = 0; i < n; i++) {
		active[i] = true;
		R[i] = (W[0][i] == no_way) ? INT_MAX : W[0][i];
		P[i] = 0;
	}

	active[0] = false;
	P[0] = -1;

	for (int i = 0; i < n - 1; i++) {
		int k_min;
		int min = INT_MAX;

		// find the minimum from the array R
		for (int j = 1; j < n; j++) {
			if (active[j] && R[j] < min) {
				min = R[j];
				k_min = j;
			}
		}

		active[k_min] = false;
    // update related cities
		for (int j = 1; j < n; j++) {
			if (W[k_min][j] != no_way) {
				if (R[j] > R[k_min] + W[k_min][j]) {
					R[j] = R[k_min] + W[k_min][j];
					P[j] = k_min;
				}
			}
		}
	}

	cout << "Minimal length: " << R[n - 1] << endl;

	int p = n-1;
	while (p != -1) {
		cout << alphabet[p];
		if (p != 0)
			cout << "--" << W[p][P[p]] << "--";
		p = P[p];
	}
}
