#include <iostream>

using namespace std;

int main(void){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int dp[n];
    dp[0] = 0;
    for(int i = 1; i < n; i++){
        if(i - 1 >= 0){
            dp[i] = dp[i - 1] + abs(arr[i] - arr[i - 1]);
        }
        if(i - 2 >= 0){
            dp[i] = min(dp[i], dp[i - 2] + abs(arr[i] - arr[i - 2]));
        }
    }
    cout << dp[n - 1] << "\n";
    return 0;
}