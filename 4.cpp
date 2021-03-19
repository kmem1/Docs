#include <iostream>

using namespace std;

const int n = 5;
int field[n][n];
const int way = -3;
const int wall = -2;
const int empty = -1;
char wall_char = '0';
char empty_char = '.';
char from_char = '@';
char to_char = 'X';


int from_x = 4;
int from_y = 1;

int to_x = 0;
int to_y = 1;

int main()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            field[i][j] = empty;
    
    field[0][2] = wall;
    field[1][2] = wall;
    field[2][2] = wall;
    field[3][2] = wall;
    
    field[from_y][from_x] = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c = wall_char;
            if (field[i][j] == empty)
                c = empty_char;
            if (i == from_y && j == from_x)
                c = from_char;
            else if (i == to_y && j == to_x)
                c = to_char;
            cout << c;
        }
        cout << endl;
    }
    
    int curr_n = 0;
    bool isChanged = true;
    while (isChanged) {
        isChanged = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (field[i][j] == curr_n) {
                    isChanged = true;
                    // up
                    if (i - 1 >= 0 && field[i-1][j] == empty)
                        field[i-1][j] = curr_n + 1;
                    // down
                    if (i + 1 < n && field[i+1][j] == empty)
                        field[i+1][j] = curr_n + 1;
                    // left
                    if (j - 1 >= 0 && field[i][j-1] == empty)
                        field[i][j-1] = curr_n + 1;
                    // right
                    if (j + 1 < n && field[i][j+1] == empty)
                        field[i][j+1] = curr_n + 1;
                }
            }
        }
        curr_n++;
    }
    
    curr_n = field[to_y][to_x];
    field[to_y][to_x] = way;
    int curr_x = to_x;
    int curr_y = to_y;
    
    while (curr_n != 0) {
        // right
        if (curr_x + 1 < n && field[curr_y][curr_x + 1] == curr_n - 1) {
            field[curr_y][curr_x] = way;
            curr_x = curr_x + 1;
            curr_n--;
        }
        // left
        else if (curr_x - 1 > 0 && field[curr_y][curr_x - 1] == curr_n - 1) {
            field[curr_y][curr_x] = way;
            curr_x = curr_x - 1;
            curr_n--;
        }
        // down
        else if (curr_y + 1 < n && field[curr_y + 1][curr_x] == curr_n - 1) {
            field[curr_y][curr_x] = way;
            curr_y = curr_y + 1;
            curr_n--;
        }
        // up
        else if (curr_y - 1 > 0 && field[curr_y - 1][curr_x] == curr_n - 1) {
            field[curr_y][curr_x] = way;
            curr_y = curr_y - 1;
            curr_n--;
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << field[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
