// Given a 2D screen, location of a pixel in the screen ie(x,y) and a color(K),
// your task is to replace color of the given pixel and all
// adjacent(i.e top left bottom right) same colored pixels with the given color K.

// Example:

// {{1, 1, 1, 1, 1, 1, 1, 1},
// {1, 1, 1, 1, 1, 1, 0, 0},
// {1, 0, 0, 1, 1, 0, 1, 1},
// {1, 2, 2, 2, 2, 0, 1, 0},
// {1, 1, 1, 2, 2, 0, 1, 0},
// {1, 1, 1, 2, 2, 2, 2, 0},
// {1, 1, 1, 1, 1, 2, 1, 1},
// {1, 1, 1, 1, 1, 2, 2, 1},
//  };

//  x=4, y=4, color=3

// {{1, 1, 1, 1, 1, 1, 1, 1},
// {1, 1, 1, 1, 1, 1, 0, 0},
// {1, 0, 0, 1, 1, 0, 1, 1},
// {1, 3, 3, 3, 3, 0, 1, 0},
// {1, 1, 1, 3, 3, 0, 1, 0},
// {1, 1, 1, 3, 3, 3, 3, 0},
// {1, 1, 1, 1, 1, 3, 1, 1},
// {1, 1, 1, 1, 1, 3, 3, 1}, };

// Note: zero based indexing is used.


// Example:
// Input:
// 3
// 3 4
// 0 1 1 0 1 1 1 1 0 1 2 3
// 0 1 5
// 2 2
// 1 1 1 1
// 0 1 8
// 4 4
// 1 2 3 4 1 2 3 4 1 2 3 4 1 3 2 4
// 0 2 9

// Output:
// 0 5 5 0 5 5 5 5 0 5 2 3
// 8 8 8 8
// 1 2 9 4 1 2 9 4 1 2 9 4 1 3 2 4






#include<bits/stdc++.h>
using namespace std;
const int N = 10005;

// for iterating over the neighbours
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

// Main Flood Fill function
void floodfill(int a[100][100], int x, int y, int k, int row, int col, int r) {


    // checking for the limits
    if (x < 0 || x >= row || y < 0 || y >= col)return ;
    if (a[x][y] == k)return ;

    if (a[x][y] == r)
    {   a[x][y] = k;
        for (int i = 0; i < 4; i++) {
            floodfill(a, x + dx[i], y + dy[i], k, row, col, r);

        }
    }

}
int main() {
    int t;
    cin >> t;
    // taking the input
    for (int i = 0; i < t; i++) {
        int n, m, x, y;
        cin >> n >> m;
        int a[100][100];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }
        cin >> x >> y;
        int k;
        cin >> k;
        int r = a[x][y];


        floodfill(a, x, y, k, n, m, r);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << a[i][j] << " ";
            }
        }

        cout << endl;
    }
    return 0;
}