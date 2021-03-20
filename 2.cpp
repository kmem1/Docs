#include <iostream>

using namespace std;

const int max_n = 1000000;

int x[max_n];
int lis[max_n];
int pr[max_n];
int result[max_n];

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x[i];
        lis[i] = 1;
        pr[i] = -1;
    }

    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
            if (x[j] < x[i] && lis[i] < lis[j] + 1) {
                lis[i] = lis[j] + 1;
                pr[i] = j;
            }
    
    int max_indx = 0;

    for (int i = 0; i < n; i++)
        if (lis[i] >= lis[max_indx])
            max_indx = i;

    int prev_indx = max_indx;
    int res_len = 0;
    while (prev_indx != -1) {
        result[res_len++] = x[prev_indx];
        prev_indx = pr[prev_indx];
    }

    // reversed
    for (int i = res_len - 1; i >= 0; i--)
        cout << result[i] << " ";
}
