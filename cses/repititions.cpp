// #include <iostream>
// #include <string>
// using namespace std;
// #define ll long long

// int main(void){
//     string a;
//     cin >> a;
//     // ll count = 1;
//     // ll ans = 1;
//     // for(ll i = 1; i < a.length(); i++){
//     //     if(a[i] == a[i - 1]){
//     //         count++;
//     //     }else{
//     //         count = 1;
//     //     }
//     // }

//     int left = 0;
//     int count = 0;
//     while(left < a.length()) {
//         int right = left;
//         while (right + 1 < a.length() && a[right] == a[right + 1]) {
//             right++;
//         }
//         if (count < right - left + 1) {
//             count = right - left + 1;
//         }
//         left = right + 1;
//     }
    
//     cout << count << "\n";
//     return 0;
// }
#include <iostream>

using namespace std;

int dp[4][1000000];
int main(void){
    string a;
    cin >> a;
    int n = a.length();
    int color[n];
    for(int i = 0; i < n; i++){
        char b;
        b = a[i];
        if(b == 'A'){
            color[i] = 0;
        }else if(b == 'T'){
            color[i] = 1;
        }else if(b == 'C'){
            color[i] = 2;
        }else{
            color[i] = 3;
        }
    }
    dp[color[0]][0] = 1;
    for(int i = 1; i < n; i++){
        if(dp[color[i]][i - 1] == 0){
            dp[color[i]][i] = 1;
        }else{
            dp[color[i]][i] = dp[color[i]][i - 1] + 1;
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        ans = max(ans, dp[color[i]][i]);
    }
    cout << ans << "\n";
    return 0;
}