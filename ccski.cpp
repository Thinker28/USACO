#include <iostream>
#include <algorithm>
#include <cstring>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

#define ll long long
int n, m;
ll grid[500][500];
bool visited[500][500];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
void floodfill(ll r, ll c, ll d){
    queue<pair<int, int> > q;
    q.push(make_pair(r, c));
    while(!q.empty()){
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            if((a + dx[i] < n) && (b + dy[i] < m) && (a + dx[i] >= 0) && (b + dy[i] >= 0) && abs(grid[a][b] - grid[a+dx[i]][b+dy[i]]) <= d && !visited[a+dx[i]][b+dy[i]]){
                q.push(make_pair(a+dx[i], b+dy[i]));
                visited[a+dx[i]][b+dy[i]] = true;
            }
        }
    }
    
}
int main(void){
    ifstream cin("ccski.in");
    ofstream cout("ccski.out");
    cin >> n >> m;
    int waypoints[n][m];
    ll minC = 1e9;
    ll maxC = -1;
    vector<pair<int, int> > vp;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
            minC = min(grid[i][j], minC);
            maxC = max(grid[i][j], maxC);

        }
    }
    int starti;
    int startj;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> waypoints[i][j];
            if(waypoints[i][j] == 1){
                vp.push_back(make_pair(i, j));
                starti = i;
                startj = j;
            }
        }
    }
    ll low = 0;
    ll high = maxC - minC;
    while(low <= high){
        ll mid = (low + high) / 2;
        floodfill(starti, startj, mid);
        bool works = true;
        for(int i = 0; i < vp.size(); i++){
            pair<int, int> p = vp[i];
            if(!visited[p.first][p.second]){
                works = false;
            }
        }
        memset(visited, false, sizeof(visited));
        // for(int i = 0; i < n; i++){
            // for(int j = 0; j < m; j++){
                // visited[i][j] = false;
            // }
        // }
        if(works){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    cout << high + 1 << "\n";
    return 0;
}