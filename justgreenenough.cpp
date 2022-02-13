#include <iostream>

using namespace std;

int dp[101][101];
int rsum(int r1, int c1, int r2, int c2){
    return dp[r2][c2] - dp[r2][c1 - 1] - dp[r1 - 1][c2] + dp[r1 - 1][c1 - 1];
    //cout << dp[c][d] - dp[a - 1][d] - dp[c][b - 1] + dp[a - 1][b - 1] << "\n";
}
int main(void){
    int n;
    cin >> n;
    int arr[n + 1][n + 1];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> arr[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            dp[i][j] += dp[i][j - 1];
            dp[i][j] += dp[i - 1][j];
            dp[i][j] += arr[i][j];
        }
    }
    int ans = 0;
    for(int ir = 1; ir <= n; ir++){
        for(int jr = ir; jr <= n; jr++){
            for(int ic = 1; ic <= n; ic++){
                for(int jc = ic; jc <= n; jc++){
                    if((jr > ir || jc > ic) && rsum(ir, jr, ic, jc) >= 100){
                        ans++;
                    }
                }
            }
        }
    }
    cout << ans - (n + 2) << "\n";
    return 0;
}