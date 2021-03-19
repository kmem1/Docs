/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

const char empty_char = '.';
const int empty = 0;
const char rock_char = '#';
const int rock = 1;

const int max_n = 35;

int field[max_n][max_n];

int n_walls = 0;

void paint(int i, int j) {
    cout << i << " " << j << endl;
    if (n_walls == 22)
        return;
    if (i < 1 || i >= max_n)
        return;
    if (j < 1 || j >= max_n)
        return;
    if (field[i][j] != empty) {
        cout << "ahhahahahahahahahahahhahaha" << endl;
        return;
    }
    if (field[i+1][j] == rock)
        n_walls++;
    if (field[i-1][j] == rock)
        n_walls++;
    if (field[i][j+1] == rock)
        n_walls++;
    if (field[i][j-1] == rock)
        n_walls++;
        
    paint(i-1, j);
    paint(i+1, j);
    paint(i, j+1);
    paint(i, j-1);

}

int main()
{
    for (int i = 0; i < max_n; i++)
        for(int j = 0; j < max_n; j++)
            field[i][j] = 3;
    
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            field[i+1][j+1] = empty;
        }
    }
    
    for (int i = 0; i < n; i++) {
        field[0][i+2] = rock;
        field[i+2][0] = rock;
    }
    
    for (int i = 0; i < n - 1; i++) {
        field[i+1][n+1] = rock;
        field[n+1][i+1] = rock;
    }
    
    field[2][4] = rock;
    field[2][5] = rock;
    field[3][3] = rock;
    field[4][3] = rock;
    field[4][4] = rock;
    field[4][5] = rock;
        
    for (int i = 0; i < n + 2; i++) {
        for(int j = 0; j < n + 2; j++) {
            cout << field[i][j];
        }
        cout << endl;
    }
    
    paint(1, 1);
    cout << n_walls;
    return 0;
}
