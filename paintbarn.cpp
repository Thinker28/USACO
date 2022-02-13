// #include <iostream>
// #include <fstream>

// using namespace std;

// int twodprefix[1001][1001];
// int main(void){
//     ifstream cin("paintbarn.in");
//     ofstream cout("paintbarn.out");
//     int n, k;
//     cin >> n >> k;
//     for(int i = 0; i < n; i++){
//         int a, b, c, d;
//         cin >> a >> b >> c >> d;
//         for(int j = a; j < c; j++){
//             twodprefix[j][b]++;
//             twodprefix[j][d]--;
//         }
//     }
//     int ans = 0;
//     for(int i = 0; i < 1000; i++){
//         for(int j = 0; j < 1000; j++){
//             if(twodprefix[i][j] == k){
//                 ans++;
//             }
//             twodprefix[i][j + 1] += twodprefix[i][j];
//         }
//     }
//     cout << ans << "\n";
//     return 0;
// }
#include <iostream>

using namespace std;

int dp[1001][1001];
#define endl "\n"
int main() {
  freopen("paintbarn.in", "r", stdin);
  freopen("paintbarn.out", "w", stdout);
  int n, k;
  cin >> n >> k;
  while(n--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    dp[a][b]++;
    dp[a][d]--;
    dp[c][b]--;
    dp[c][d]++;
  }
  int ret = 0;
  for(int i = 0; i < 1000; i++) {
    for(int j = 0; j < 1000; j++) {
      if(i) dp[i][j] += dp[i - 1][j];
      if(j) dp[i][j] += dp[i][j - 1];
      if(i && j) dp[i][j] -= dp[i - 1][j - 1];
      if(dp[i][j] == k) ret++;
    }
  }
    cout << ret << endl;
}