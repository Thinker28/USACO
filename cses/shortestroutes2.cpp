#include <iostream>
#include <vector>
using namespace std;

int main(void){
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<long long> > dp(n + 1, vector<long long> (n + 1, 1e18)); 
    for(int i = 0; i < m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        if(w < dp[a][b]){
            dp[a][b] = w;
            dp[b][a] = w;
        } 
    }
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = i + 1; j <= n; j++){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                dp[j][i] = dp[i][j];

            }
        }
    }
    for(int i = 0; i < q; i++){
        int a, b;
        cin >> a >> b;
        if(a == b){
            dp[a][b] = 0;
        }
        if(dp[a][b] == 1e18){
            dp[a][b] = -1;
        }
        cout << dp[a][b] << "\n";
    }

    return 0;
}