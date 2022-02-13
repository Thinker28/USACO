#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(void){
    int n;
    cin >> n;
    vector<int> x(n);
    for(int i = 0; i < n; i++){
        cin >> x[i];
    }
    
    vector<vector<bool> > dp(n + 1, vector<bool>(n*1000+1, false));
    dp[0][0] = true;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= n * 1000; j++){
            dp[i][j] = dp[i - 1][j];
            int left = j - x[i - 1];
            if(left >= 0 && dp[i - 1][left]){
                dp[i][j] = true;
            }
        }
    }
    set<int> possible;
    for(int i = 1; i <= n*1000; i++){
        if(dp[n][i]){
            possible.insert(i);
        }
    }
    cout << possible.size() << "\n";
    for(auto v: possible){
        cout << v << " ";
    }
    return 0;
}