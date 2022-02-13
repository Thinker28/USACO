#include <iostream>

using namespace std;

string board[8];
bool visited[8];
bool d1[15];
bool d2[15];
int ans = 0;
void dfs(int r){
    if(r == 8){
        ans++;
        return;
    }
    for(int i = 0; i < 8; i++){
        if(!visited[i] && board[r][i] == '.' && !d1[i-r+7] && !d2[i+r]){
            d2[i+r] = visited[i] = d1[i-r+7] = true;
            dfs(r + 1);
            d2[i+r] = visited[i] = d1[i-r+7] = false;
        }
    }
}
int main(void){
    for(int i = 0; i < 8; i++){
        cin >> board[i];
    }
    dfs(0);
    cout << ans << "\n";
    
    return 0;
}