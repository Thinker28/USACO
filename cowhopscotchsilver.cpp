#include <iostream>
#include <fstream>
using namespace std;

int grid[100][100];
int dp[100][100];
int main(void){
    int r, c, k;
    ifstream cin("hopscotch.in");
    ofstream cout("hopscotch.out");
    cin >> r >> c >> k;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> grid[i][j];
        }
    }

    dp[0][0] = 1;
    for (int i1 = 0; i1 < r; i1++) {
        for (int j1 = 0; j1 < c; j1++) {
            for (int i2 = 0; i2 < i1; i2++) {
                for (int j2 = 0; j2 < j1; j2++) {
                    if (grid[i1][j1] != grid[i2][j2]) {
                        dp[i1][j1] = (dp[i1][j1] + dp[i2][j2]) % 1000000007;
                    }
                }
            }
        }
    }
    cout << dp[r - 1][c - 1] << "\n";
    return 0;
}