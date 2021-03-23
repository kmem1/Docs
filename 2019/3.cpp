#include <iostream>
#include <fstream>

using namespace std;

const int tree = 1;

const int max_n = 50;

int field[max_n][max_n];
bool checked[max_n][max_n];
int forests[max_n];

void getForest(int i, int j, int k, int n, int m) {
	if (i < 0 || i >= m || j < 0 || j >= n)
		return;

	if (field[i][j] != tree || checked[i][j] == true)
		return;

	forests[k] += 1;
	cout << "found" << k << endl;
	checked[i][j] = true;
	getForest(i + 1, j, k, n, m);
	getForest(i - 1, j, k, n, m);
	getForest(i, j + 1, k, n, m);
	getForest(i, j - 1, k, n, m);
}

int main()
{
	int n, m;
	cin >> n >> m;

	ifstream fin("file.txt");

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			checked[i][j] = false;
			fin >> field[i][j];
			cout << field[i][j] << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < m * n; i++)
		forests[i] = 0;

	int k = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (field[i][j] == tree && checked[i][j] == false) {
				getForest(i, j, k, n, m);
				k++;
			}
		}
	}

	int count_2, count_3, count_more;
	count_2 = count_3 = count_more = 0;
	for (int i = 0; i < k; i++) {
		if (forests[i] == 2)
			count_2++;
		else if (forests[i] == 3)
			count_3++;
		else if (forests[i] > 3)
			count_more++;
	}

	cout << "2: " << count_2 << "; 3: " << count_3 << "; >3: " << count_more << endl;
}
