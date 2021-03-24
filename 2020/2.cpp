#include <iostream>

int p1 = 1;
int p2 = 2;
int p3 = 3;

using namespace std;
int main()
{
    int n;
    cin >> n;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= i ; j++) {
            cout << n - i << " " << j << " " << i - j << " " << p1*(n-i) + p2*j + p3*(i-j) <<  endl;
        }
    }
}
