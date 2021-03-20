#include <iostream>

using namespace std;

const int n = 8;

int field[n][n];

const int way = -2;
const char way_char = '@';
const int _empty = -1;
const int knight = 0;


int from_x, from_y, to_x, to_y;

int row[] = { 1, -1, 1, -1, 2, -2, 2, -2 };
int col[] = { -2, 2, 2, -2, -1, 1, 1, -1 };

bool isValid(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < n;
}

int main()
{
	cin >> from_x >> from_y >> to_x >> to_y;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			field[i][j] = _empty;

	field[from_y][from_x] = knight;

	bool isMoved = true;
	int curr_n = 0;

	while (isMoved) {
		isMoved = false;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (field[i][j] == curr_n) {
					for (int k = 0; k < n; k++) {
						int tmp_x = j + col[k];
						int tmp_y = i + row[k];
						if (isValid(tmp_y, tmp_x)) {
							if (field[tmp_y][tmp_x] == _empty) {
								isMoved = true;
								field[tmp_y][tmp_x] = curr_n + 1;
							}
						}
					}
				}
			}
		}
		curr_n++;
	}

	curr_n = field[to_y][to_x];
	int x, y;
	x = to_x;
	y = to_y;

	while (curr_n != 0) {
		field[y][x] = way;
		for (int k = 0; k < n; k++) {
			int tmp_x = x + col[k];
			int tmp_y = y + row[k];
			if (isValid(tmp_x, tmp_y)) {
				if (field[tmp_y][tmp_x] == curr_n - 1) {
					x = tmp_x;
					y = tmp_y;
					curr_n--;
					break;
				}
			}
		}
	}

	cout << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (field[i][j] == way)
				cout << way_char;
			else
				cout << field[i][j];
		}
		cout << endl;
	}
}
