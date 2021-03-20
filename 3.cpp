#include <iostream>

using namespace std;

const int max_n = 1000000;

int x[max_n];
int lis[max_n];
int pr[max_n];
int result[max_n];

int main()
{
    int n1, n2, k;
    cin >> n1 >> n2;

    n1 += (n1 % 2) + 1;
    n2 -= (n2 % 2);

    k = 0;
    for (int i = n1; i < n2; i += 2)
        k++;

    cout << k;
}
