#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int dp[100005][25][3];
vector<int> fj;
#define HOOF 0
#define PAPER 1
#define SCISSOR 2     
int addone(int a, int b){
    if(a == HOOF && fj[b] == SCISSOR){
        return 1;
    }else if(a == SCISSOR && fj[b] == PAPER)    {
        return 1;
    }else if(a == PAPER && fj[b] == HOOF){
        return 1;
    }
    return 0;
}
int main(void){
    ifstream cin("hps.in");
    ofstream cout("hps.out");
    int n, k;
    cin >> n >> k;
    fj = vector<int>(n+1);
    for(int i = 1; i <= n; i++){
        char a;
        cin >> a;
        if(a == 'H'){
            fj[i] = HOOF;
        }else if(a == 'P'){
            fj[i] = PAPER;
        }else{
            fj[i] = SCISSOR;
        }
    }
    int ans = 0;
    for(int i = 1; i < n+1; i++){
        for(int j = 1; j < k + 2; j++){
            int add = addone(HOOF, i);
            dp[i][j][HOOF] = max(dp[i - 1][j][HOOF] + add, max(dp[i - 1][j - 1][PAPER] + add, dp[i - 1][j - 1][SCISSOR] + add));
            add = addone(PAPER, i);
            dp[i][j][PAPER] = max(dp[i - 1][j][PAPER] + add, max(dp[i - 1][j - 1][HOOF] + add, dp[i - 1][j - 1][SCISSOR] + add));
            add = addone(SCISSOR, i);
            dp[i][j][SCISSOR] = max(dp[i - 1][j][SCISSOR] + add, max(dp[i - 1][j - 1][PAPER] + add, dp[i - 1][j - 1][HOOF] + add));
            if(i == n){
                ans = max(ans, max(max(dp[i][j][HOOF], dp[i][j][PAPER]), dp[i][j][SCISSOR]));
            }
        }
    }
    cout << ans << "\n";
    return 0;
}