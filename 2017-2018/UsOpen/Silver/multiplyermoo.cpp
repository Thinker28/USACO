#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool visited[250][250];
int grid[250][250];
int n;
bool check(int a, int b){
    if(a >= 0 && a < n && b >= 0 && b < n){
        return true;
    }
    return false;
}
int floodfill(int x, int y, int color){
    visited[x][y] = true;
    int ans = 1;
    for(int i = 0; i < 4; i++){
        if(check(x + dx[i], y + dy[i]) && !visited[x + dx[i]][y + dy[i]] && (grid[x][y] == grid[x + dx[i]][y + dy[i]] || grid[x+dx[i]][y+dy[i]] == color)){
            ans += floodfill(x + dx[i], y + dy[i], color);
        }
    }
    return ans;
}
int main(void){
    // ifstream cin("multimoo.in");
    // ofstream cout("multimoo.out");
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }
    int ans1 = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!visited[i][j]){
                ans1 = max(ans1, floodfill(i, j, grid[i][j]));
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            visited[i][j] = false;
        }
    }
    int ans2 = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(j > 0 && grid[i][j] != grid[i][j - 1]){
                ans2 = max(ans2, floodfill(i, j, grid[i][j - 1]));
            }
            std::memset(visited, false, n * n);
        }
    }
    cout << ans1 << "\n" << ans2 << "\n";
    return 0;
}