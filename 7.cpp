#include <iostream>

using namespace std;

const int max_n = 100;
const int way = -1;

int field[max_n][max_n];

int matrix[max_n][max_n];

int min(int n1, int n2);


int main()
{
	int n; 
	cin >> n;


	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> field[i][j];

	matrix[0][0] = field[0][0];

	for (int i = 1; i < n; i++) {
		matrix[0][i] = field[0][i] + matrix[0][i - 1];
		matrix[i][0] = field[i][0] + matrix[i - 1][0];
	}

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			matrix[i][j] = field[i][j] + min(matrix[i - 1][j], matrix[i][j - 1]);
		}
	}

	int x, y;
	x = y = n - 1;
	while (x != 0 || y != 0) {
		field[y][x] = way;
		if (x == 0) {
			y--;
			continue;
		}

		if (y == 0) {
			x--;
			continue;
		}

		if (matrix[y - 1][x] < matrix[y][x - 1])
			y--;
		else
			x--;
	}

	cout << endl;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << field[i][j] << " ";
		}
		cout << endl;
	}
}

int min(int n1, int n2) {
	return (n1 < n2) ? n1 : n2;
}
