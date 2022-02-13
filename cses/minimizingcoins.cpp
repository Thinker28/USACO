#include <iostream>

using namespace std;
#define ll long long
ll dp[10000000];
int main(void){
    int n, x;
    cin >> n >> x;
    ll coins[n];
    for(int i = 0; i < n; i++){
        cin >> coins[i];
    }
    for(int i = 0; i <= x; i++){
        dp[i] = 1e9;
    }
    dp[0] = 0; 
    for(int i = 1; i <= x; i++){
        for(int j = 0; j < n; j++){
            if(i - coins[j] >= 0){
                dp[i] = min(dp[i - coins[j]] + 1, dp[i]);
            }
        }
    }

    if(dp[x] == 1e9){
        cout << -1 << "\n";
    }else{
        cout << dp[x] << "\n";
    }
    return 0;
}