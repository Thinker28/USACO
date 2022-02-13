#include <iostream>
#include <vector>
using namespace std;

int n, m;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
char grid[100][50][50];
bool visited[100][50][50];

bool check(int x, int y){
    if(x >= 0 && x < n && y < m && y >= 0){
        return true;
    }
    return false;
}
void dfs(int t, int x, int y){
    visited[t][x][y] = true;
    for(int i = 0; i < 4; i++){
        if(check(x+dx[i], y+dy[i]) && grid[t][x+dx[i]][y+dy[i]] == '.' || grid[t][x+dx[i]][y+dy[i]] == 'G'){
            dfs(t, x+dx[i], y+dy[i]);
        }
    }
}
bool bad = false;
void block(int t){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[t][i][j] == 'B'){
                for(int k = 0; k < 4; k++){
                    if(check(i + dx[k], j + dy[k]) && grid[t][i + dx[k]][j + dy[k]] == '.'){
                        grid[t][i + dx[k]][j + dy[k]] = '#';
                    }else if(check(i + dx[k], j + dy[k]) &&  grid[t][i+dx[k]][j+dy[k]] == 'G'){
                        bad = true;
                    }
                }
            }
        }
    }
}
int main(void){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n >> m;
        vector<pair<int,int> > goodpos;
        for(int j = 0; j < n; j++){
            for(int k = 0; k < m; k++){
                cin >> grid[i][j][k];
                if(grid[i][j][k] == 'G'){
                    goodpos.push_back(make_pair(j, k));
                }
            }
        }
        block(i);
        if(bad){
            cout << "No\n";
            continue;
        }
        dfs(i, n - 1, m - 1);
        bad = false;
        for(int j = 0; j < goodpos.size(); j++){
            if(!visited[i][goodpos[j].first][goodpos[j].second]){
                bad = true;
            }
        }
        if(bad){
            cout << "No\n";
        }else{
            cout << "Yes\n";
        }
        goodpos.clear();
    }
    return 0;
}