#include <iostream>
#include <vector>

using namespace std;

int main(void){
    int n, x;
    cin >> n >> x;
    vector<int> h(n + 1);
    vector<int> s(n + 1);
    for(int i = 0; i < n; i++){
        cin >> h[i];
    }
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    vector<vector<int> > dp(n + 1,vector<int>(x + 1,0));
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= x; j++){
            dp[i][j] = dp[i - 1][j];
            int left = j - h[i - 1];
            if(left >= 0){
                dp[i][j] = max(dp[i][j], dp[i - 1][left] + s[i - 1]);
            }
        }
    }
    cout << dp[n][n] << "\n";
    return 0;
}