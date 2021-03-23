#include <iostream>

using namespace std;

const int max_n = 100;

int levels[max_n][max_n];

int moves[max_n];
int max_moves[max_n];
int max_sum = 0;

void findSums(int i, int j, int sum, int n) {
    sum += levels[i][j];
    moves[i] = j;

    if (i + 1 < n) {
        findSums(i + 1, j, sum, n);
        findSums(i + 1, j + 1, sum, n);
    } else {
        if (sum > max_sum) {
            max_sum = sum;
            for (int i = 0; i < n; i++)
                max_moves[i] = moves[i];
        }
    }
}

int main()
{
    setlocale(LC_CTYPE, "rus");
    int n;
    cin >> n;

    int k = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            cin >> levels[i][j];
        }
        k++;
    }

    findSums(0, 0, 0, n);
    cout << "Общая сложность: " << max_sum << endl;
    cout << "Маршрут (от вершины) ";
    for (int i = 0; i < n; i++) {
        cout << "(" << i + 1 << "," << max_moves[i] + 1 << ")";
        if (i < n - 1)
            cout << " -> ";
    }

    return 0;
}
