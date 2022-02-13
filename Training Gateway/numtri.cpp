/*
ID: amogh.d1
TASK: numtri
LANG: C++ 
*/
#include <iostream>
#include <fstream>
using namespace std;

int grid[1005][1005];
int dp[1005][1005];
int main(void){
    ifstream cin("numtri.in");
    ofstream cout("numtri.out");
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            cin >> grid[i][j];
        }
    }
    dp[1][1] = grid[1][1];
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= i; j++){
            dp[i][j] = grid[i][j];
            if(j == 1){
                dp[i][j] += dp[i - 1][j];
            }else if(i == j){
                dp[i][j] += dp[i - 1][j - 1];
            }else{
                dp[i][j] += max(dp[i - 1][j - 1], dp[i - 1][j]);
            }
        }
    }
    int ans = -1;
    for(int i = 1; i <= n; i++){
        ans = max(dp[n][i], ans);
    }
    cout << ans << "\n";

    return 0;
}