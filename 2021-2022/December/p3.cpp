#include <iostream>
#include <string>
using namespace std;

char grid[50][50];
int n;
int k;
int ans = 0;
void dfs(int r, int c, int k2, char curdir){
    if(r == n - 1 && c == n - 1){
        ans++;
        return;
    }
    if(r + 1 < n && grid[r + 1][c] != 'H' && curdir == 'D'){
        dfs(r + 1, c, k2, curdir);
    }
    if(r + 1 < n && grid[r + 1][c] != 'H' && curdir == 'R' && k2 + 1 <= k){
        dfs(r + 1, c, k2 + 1, 'D');
    }
    if(c + 1 < n && grid[r][c + 1] != 'H' && curdir == 'R'){
        dfs(r, c + 1, k2, curdir);
    }
    if(c + 1 < n && grid[r][c + 1] != 'H' && curdir == 'D' && k2 + 1 <= k){
        dfs(r, c + 1, k2 + 1,'R');
    }

}
int main(void){
    int t;
    cin >> t;
    for(int test = 0; test < t; test++){
        cin >> n >> k;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> grid[i][j];
            }
        }
        if(1 < n && grid[1][0] != 'H'){
            dfs(1, 0, 0, 'D');  
        }
        if(1 < n && grid[0][1] != 'H'){
           dfs(0, 1, 0, 'R'); 
        }
        cout << ans << "\n";
        ans = 0;
    }
    return 0;
}