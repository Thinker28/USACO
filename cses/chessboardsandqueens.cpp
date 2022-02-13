#include <iostream>
#include <vector>

using namespace std;
#define pi pair<int, int> 
const int MAXN = 8;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
char grid[MAXN][MAXN];
bool visited[MAXN][MAXN];
vector<pi> v;
bool check(int i, int j){
    if(i >= 0 && i < 8 && j >= 0 && j < 8){
        return true;
    }
    return false;
}
bool diagonal(int i, int j){
    for(int i2 = i; i2 < 8; i2++){
        for(int j2 = j; j2 < 8; j2++){
            if(visited[i][j] && (abs(i2-i) == abs(j2-j)) || (i2 = i)|| (j2 == j)){
                return true;
            }
        }
    }
    return false;
}
int ans = 0;
void dfs(int placed){
    if(placed == 8){
        ans++;
        return;
    }
    for(int i = 0; i < MAXN; i++){
        for(int j = 0; j < MAXN; j++){
            if(grid[i][j] == '.' && !diagonal(i, j) && !visited[i][j]){
                visited[i][j] = true;
                dfs(placed + 1);
                visited[i][j] = false;
            }
        }
    }
}
int main(void){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            cin >> grid[i][j];
        }
    }
    dfs(0);
    cout << ans << "\n";
    return 0;
}