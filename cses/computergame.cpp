#include <iostream>

using namespace std;

bool range(int i, int j, int n){
    if(i < 2 && i >= 0 && j < n && j >= 0){
        return true;
    }
    return false;
}
int main(void){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        int arr[2][n];
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < n; k++){
                cin >> arr[j][k];
            }
        }
        int dp[2][n];
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < n; k++){
                dp[j][k] = 0;
            }
        }
        if(arr[0][0] == 1){
            cout << "NO\n";
            // continue;
        }
        dp[0][0] = 1;
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < n; k++){
                if(range(j - 1, k, n) && dp[j - 1][k] == 1 && arr[j][k] != 1){
                    dp[j - 1][k] = 1;
                }else if(range(j + 1, k, n) && dp[j + 1][k] == 1 && arr[j][k] != 1){
                    dp[j + 1][k] = 1;
                }else if(range(j, k - 1, n) && dp[j][k - 1] == 1 && arr[j][k] != 1){
                    dp[j][k - 1] = 1;
                }else if(range(j, k + 1, n) && dp[j][k + 1] == 1 && arr[j][k] != 1){
                    dp[j][k + 1] = 1;
                }else if(range(j - 1, k - 1, n) && dp[j - 1][k - 1] == 1 && arr[j][k] != 1){
                    dp[j - 1][k - 1] = 1;
                }else if(range(j + 1, k + 1, n) && dp[j + 1][k + 1] == 1 && arr[j][k] != 1){
                    dp[j + 1][k + 1] = 1;
                }
            }
        }
        if(dp[1][n - 1] == 1){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    // }
    return 0;
}