#include <iostream>

using namespace std;

const int MAXN = 1005;
char grid[MAXN][MAXN];
bool visited[MAXN][MAXN];
int n, m;
void floodfill(int r, int c){
    if(r >= n || r < 0 || c >= m || c < 0){
        return;
    }
    if(visited[r][c]){
        return;
    }
    if(grid[r][c] == '#'){
        return;
    }
    
    visited[r][c] = true;
    floodfill(r - 1, c);
    floodfill(r + 1, c);
    floodfill(r, c - 1);
    floodfill(r, c + 1);
}

int main(void){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }
    int count = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!visited[i][j] && grid[i][j] == '.'){
                floodfill(i, j);
                count++;
            }
        }
    }
    cout << count << "\n";
    return 0;
}