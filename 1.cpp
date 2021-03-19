#include <iostream>
#include <bitset>

using namespace std;

const int max_n = 24;

int x[max_n];
int curr_sum = 0;
int sign[max_n];

int main()
{
    int n, s;
    cin >> n >> s;
    
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    
    for (int i = 0; i < max_n; i++) {
        sign[i] = 0;
    }
    
    curr_sum = x[0];
    
    for (int i = 1; i < n; i++) {
        curr_sum -= x[i];
    }
    
    if (curr_sum == s) {
        for (int i = 0; i < n; i++) {
            cout << x[i] << " ";
            if (i != n - 1)
                cout << (sign[i] == 0 ? "-" : "+") << " ";
        }
        return 0;
    }
        
    bitset<max_n> curr_set;
    int curr_n = 0;
    while(curr_set[n] == 0) {
        curr_n++;
        curr_set = bitset<max_n>(curr_n);
        for (int i = 0; i < n-1; i++) {
            if (curr_set[i] != sign[i]) {
                if (sign[i] == 0) {
                    curr_sum += x[i+1] * 2;
                    sign[i] = 1;
                } else {
                    curr_sum -= x[i+1] * 2;
                    sign[i] = 0;
                }
            }
        }
        
        if (curr_sum == s) {
            for (int i = 0; i < n; i++) {
                cout << x[i] << " ";
                if (i != n - 1)
                    cout << (sign[i] == 0 ? "-" : "+") << " ";
            }
            return 0;
        }
    }
    cout << "No solution";
    return 0;
}
