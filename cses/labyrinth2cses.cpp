#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(void){
    int n, m;
    cin >> n >> m;
    char grid[n][m];
    bool visited[n][m];
    pair<int, int>  parents[n][m];
    int ai, aj, bi, bj;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 'A'){
                ai = i;
                aj = j;
            }else if(grid[i][j] == 'B'){
                bi = i;
                bj = j;
            }
        }
    }


    queue<pair<int, int> > q;
    q.push(make_pair(ai, aj));
    parents[ai][aj] = make_pair(-1, -1);
    while(!q.empty()){
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int ci = a + dx[i];
            int cj = b + dy[i];
            if(ci < n && cj < m && grid[ci][cj] == '.'){
                parents[ci][cj] = make_pair(a, b);
                visited[ci][cj] = true;
            }
        }
    }
    string path = "";
    //backtracking
    if(!visited[bi][bj]){
        cout << "NO\n";
        return 0;
    }else{
        int a = parents[bi][bj].first;
        int b = parents[bi][bj].second;
        while(a != -1 && b != -1){
            int c = parents[a][b].first;
            int d = parents[a][b].second;
            if(a == c && d == b - 1){
                path += 'L';
            }else if(a == c  && d == b + 1){
                path += 'R';
            }else if(a == c - 1 && d == b){
                path += 'U';
            }else if(a == c + 1 && d == b){
                path += 'D';
            }
            a = parents[a][b].first;
            b = parents[a][b].second;
        }
    }
    reverse(path.begin(), path.end());
    cout << "YES\n" << path.length() << "\n" << path << "\n";

    return 0;
}