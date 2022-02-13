#include <iostream>
#include <fstream>
using namespace std;

string grid[15];
int dp[15][15];
// int dfs(int n, int m, int r, int c){
//     if (r == n - 1 && c == m - 1) {
//         return 1;
//     }

//     int ans = 0;
//     for (int i = r + 1; i < n; i++){
//         for (int j = c + 1; j < m; j++){
//             if (grid[r][c] != grid[i][j]) {
//                 ans += dfs(n, m, i, j);
//             }
//         }
//     }
//     return ans;
// }
int main(void){
    int r, c;
    ifstream cin("hopscotch.in");
    ofstream cout("hopscotch.out");
    cin >> r >> c;
    for(int i = 0; i < r; i++){
        cin >> grid[i];
    }

    dp[0][0] = 1;
    for (int i1 = 0; i1 < r; i1++) {
        for (int j1 = 0; j1 < c; j1++) {
            for (int i2 = 0; i2 < i1; i2++) {
                for (int j2 = 0; j2 < j1; j2++) {
                    if (grid[i1][j1] != grid[i2][j2]) {
                        dp[i1][j1] += dp[i2][j2];
                    }
                }
            }
        }
    }
    cout << dp[r - 1][c - 1] << "\n";

    // cout << dfs(r, c, 0, 0) << "\n";
    return 0;
}