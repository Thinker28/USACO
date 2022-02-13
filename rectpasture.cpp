#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long

int n;
bool cmp(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}

int query(vector<vector<int> > &dp, int x1, int y1, int x2, int y2){
    return dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1];
}
int main(void){
    cin >> n;
    vector<vector<int> > dp(n + 1, vector<int> (n + 1, 0));
    pair<ll, ll> x_y[n];
    for(int i = 0; i < n; i++){
        cin >> x_y[i].first >> x_y[i].second;
    }
    sort(x_y, x_y + n);
    for(int i = 0; i < n; i++){
        x_y[i].first = i;
    }
    sort(x_y, x_y + n, cmp);
    for(int i = 0; i < n; i++){
        x_y[i].second = i;
    }
    for(int i = 0; i < n; i++){
        dp[x_y[i].first + 1][x_y[i].second + 1] = 1;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            dp[i][j] = dp[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
        }
    }
    long long ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            int left = min(x_y[i].first, x_y[j].first)+1;
            int right = max(x_y[i].first, x_y[j].first)+1;
            ans += 1LL * (query(dp, 1, i + 1, left, j + 1)) * query(dp, right, i + 1, n, j + 1);
        }
    }
    cout << ans + 1 << "\n";
    return 0;
}
// #include <iostream>
// #include <algorithm>
// using namespace std;
    
// #define ll long long
// bool ycmp(pair<int, int> a, pair<int, int> b){
//     return a.second < b.second;
// }
// int dp[2500][2500];
// int main(void){
//     int n;
//     cin >> n;
//     pair<int, int> p[n];
//     for(int i = 0; i < n; i++){
//         cin >> p[i].first >> p[i].second;
//     }
//     sort(p, p + n);
//     for(int i = 0; i < n; i++){
//         p[i].first = i + 1;
//     }
//     sort(p, p + n, ycmp);
//     for(int i = 0; i < n; i++){
//         p[i].second = i + 1;
//     }
//     for(int i = 0; i < n; i++){
//         dp[p[i].first][p[i].second] = 1;
//     }
//     for(int i = 0; i < n; i++){
//         for(int j = 0; j < n; j++){
//             if(i){
//                 dp[i][j] += dp[i - 1][j];
//             }
//             if(j){
//                 dp[i][j] += dp[i][j - 1];
//             }
//             if(i && j){
//                 dp[i][j] -= dp[i - 1][j - 1];
//             }
//         }
//     }
//     ll ans = 1;
//     for(int i = 0; i < n; i++){
//         for(int j = i + 1; j < n; j++){
//             int maxy = max(p[i].second, p[j].second);
//             int maxx = max(p[i].first, p[j].first);
//             int miny = min(p[i].second, p[j].second);
//             int minx = min(p[i].first, p[j].first);
//             int above = dp[miny - 1][maxx];
//             int below =  dp[n - 1][maxx] - dp[maxy - 1][maxx];
//             cout << "above: " << above << " " << "below: " << below << "\n";s
//             ans += (above + 1) * (below + 1);
//         }

//     }
//     cout << ans + 1 << "\n";
//     return 0;
// }