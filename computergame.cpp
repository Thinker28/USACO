#include <iostream>

using namespace std;

int dx[9] = {1, 1, 0, 0, 1, -1, -1, 0, -1};
int dy[9] = {0, -1, 1, -1, 1, 0, 1, -1, -1};
int grid[101][101]; 
int dp[2][101];
int n;
bool valid(int r, int c){
    if(r < 2 && r >= 0 && c < n && c >= 0){
        return true;
    }
    return false;
}
int main(void){
    int t;
    cin >> t;
    for(int test = 0; test < t; test++){
        cin >> n;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> grid[i][j];
            }
        }
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < n; j++){
                dp[i][j] = 0;
            }
        }
        if(grid[0][0] == 1){
            cout << "NO\n";
        }else{
            dp[0][0] = 1;
        }
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < n; j++){
                if(dp[i][j] != 1){
                    continue;
                }
                for(int x = 0; x < 9; x++){
                    if(valid(i + dx[x], j + dy[x]) && grid[i + dx[x]][j + dy[x]] == 0){
                        dp[i + dx[x]][j + dy[x]] = 1;
                    }
                }
            }
        }
        if(dp[1][n - 1] == 1){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
    return 0;
}