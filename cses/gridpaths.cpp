#include <iostream>

using namespace std;
#define ll long long
ll dp[1005][1005];
#define MOD 10000007
int main(void){
    int n;
    cin >> n;
    char grid[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }
    dp[0][0] = 1;
    if(grid[0][0] == '*'){
        cout << 0 << "\n";
        return 0;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            dp[i][j] %= 1000000007;
            if(j + 1 < n){
                if(grid[i][j + 1] == '.'){
                    dp[i][j + 1] += dp[i][j];
                }
            }
            if(i + 1 < n){
                if(grid[i + 1][j] == '.'){
                    dp[i + 1][j] += dp[i][j];
                }
            }
        }
    }
    cout << dp[n - 1][n - 1];
    return 0;
}