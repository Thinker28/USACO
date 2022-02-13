// #include <iostream>

// using namespace std;

// int dp[1000][1000];

// int main(void){
//     int n, q;
//     cin >> n >> q;
//     for(int i = 0; i < n; i++){
//         for(int j = 0; j < n; j++){
//             char a;
//             cin >> a;
//             if(a == '*'){
//                 if(j == 0){
//                     dp[i][j] = 1;
//                 }else{
//                     dp[i][j] = dp[i][j - 1] + 1;
//                 }
//             }
//         }
//     } 
//     for(int i = 0; i < q; i++){
//         int a, b, c, d;
//         cin >> a >> b >> c >> d;
//         --a, --b, --c, --d;
//         int sum = 0;
//         for(int j = b; j <= d; j++){
//             if(a - 1){
//                 sum += dp[j][c] - dp[j][a - 1];
//                 continue;
//             }
//             sum += dp[j][c] - dp[j][a];
//         }
//         cout << sum << "\n";
//     }
//     return 0;
// }
#include <iostream>

using namespace std;

int dp[1001][1001];
int main(void){
    int n, q;
    cin >> n >> q;
    //setup 2d prefix sums
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; j++){
            char a;
            cin >> a;
            if(a == '*'){
                dp[i][j] += dp[i - 1][j];
                dp[i][j] += dp[i][j - 1];
                dp[i][j] -= dp[i - 1][j - 1];
                dp[i][j]++;
            }else{
                dp[i][j] += dp[i - 1][j];
                dp[i][j] += dp[i][j - 1];
                dp[i][j] -= dp[i - 1][j - 1];
            }
        }
    }
    for(int i = 0; i < q; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << dp[c][d] - dp[a - 1][d] - dp[c][b - 1] + dp[a - 1][b - 1] << "\n";
    }
    return 0;
}