#include <iostream>

using namespace std;

const int max_n = 100;

int weights[max_n];

int matrix[max_n][max_n];

int max(int n1, int n2);

int main()
{
	int n, w;
	cin >> n >> w;

	for (int i = 0; i < n; i++)
		cin >> weights[i];

	for (int i = 0; i < n; i++)
		for (int j = 0; j <= w; j++)
			matrix[i][j] = 0;

	for (int i = 1; i < n + 1; i++)
		for (int j = 1; j <= w; j++) {
			matrix[i][j] = matrix[i - 1][j];
			if (weights[i - 1] <= j)
				matrix[i][j] = max(matrix[i - 1][j - weights[i - 1]] + weights[i - 1], matrix[i][j]);
		}

	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j <= w; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}

	int curr_w = matrix[n][w];
	int choosed_items[max_n];
	int n_choosed_items = 0;
	int i = n;
	int j = w;
	while (i != 0) {
		while (matrix[i - 1][j] == curr_w) {
			i--;
		}
		choosed_items[n_choosed_items++] = weights[i - 1];
		curr_w = matrix[i - 1][j - weights[i - 1]];
		i--;
	}

	for (i = 0; i < n_choosed_items; i++)
		cout << choosed_items[i] << " ";

}

int max(int n1, int n2) {
	return (n1 > n2) ? n1 : n2;
}
