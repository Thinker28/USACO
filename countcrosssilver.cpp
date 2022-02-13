#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(void){
    // ifstream cin("countcross.in");
    // ofstream cout("countcross.out");
    int n, r, k;
    cin >> n >> r >> k;
    bool visited[n][n];
    bool cow[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cow[i][j] = visited[i][j] = false;
        }
    }
    vector<pair<int, int> > adj[n][n];
    int ans = 0;
    for(int i = 0; i < r; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--, b--, c--, d--;
        adj[a][b].push_back(make_pair(c, d));
    }
    for(int i = 0; i < k; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        cow[a][b] = true;
    }
    queue<pair<int, int> > p;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(cow[i][j] && !visited[i][j]){
                p.push(make_pair(i, j));
                while(!p.empty()){
                    int a = p.front().first;
                    int b = p.front().second;
                    visited[a][b] = true;
                    p.pop();
                    for(int i = 0; i < 4; i++){
                        if(a + dx[i] < n && a + dx[i] >= 0 && b + dy[i] < n && b + dy[i] >= 0 && !visited[a+dx[i]][b+dy[i]] && cow[a+dx[i]][b+dy[i]] && find(adj[a][b].begin(), adj[a][b].end(), make_pair(a+dx[i], b+dy[i])) != adj[a][b].end()){
                            p.push(make_pair(a+dx[i], b+dy[i]));
                            visited[a+dx[i]][b+dy[i]] = true;
                            ans++;
                        }
                    }
                }
            }
        }
    }    
    cout << ans + 1 << "\n";
    return 0;
}