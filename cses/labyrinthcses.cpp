#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

char dir_c[4] = {'D', 'U', 'R', 'L'};
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(void){
    int n, m, ai, aj, bi, bj;
    cin >> n >> m;
    char grid[n][m];
    pair<char, pair<int, int> > parent[n][m];
    bool visited[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 'A'){
                ai = i;
                aj = j;
            } else if (grid[i][j] == 'B') {
                bi = i;
                bj = j;
            }

            parent[i][j] = make_pair('N', make_pair(-1, -1));
            visited[i][j] = false;
        }
    }
    queue<pair<int, int> > q;
    q.push(make_pair(ai, aj));
    visited[ai][aj] = true;
    // cout << "bi=" << bi << ", bj=" << bj << "\n";
    while(!q.empty()) {
        int ci = q.front().first;
        int cj = q.front().second;
        // cout << "ci=" << ci << ", cj=" << cj << "\n";
        q.pop();
        
        for (int dir = 0; dir < 4; dir++) {
            int di = ci + dx[dir];
            int dj = cj + dy[dir];
            if (di >= 0 && di < n && dj >= 0 && dj < m && !visited[di][dj] && grid[di][dj] != '#') {
                // cout << "di=" << di << ", dj=" << dj << "\n";
                visited[di][dj] = true;
                parent[di][dj] = make_pair(dir_c[dir], make_pair(ci, cj));
                // if (di == bi && dj == bj) {
                //     cout << "parent: " << parent[di][dj].second.first << " " << parent[di][dj].second.second << "\n";
                // }
                q.push(make_pair(di, dj));
            }
        }
        // cout << "\n";
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << parent[i][j].first;
    //     }
    //     cout << "\n";
    // }

    string path = "";
    int ci = bi, cj = bj;
    while(!(ci == -1 && cj == -1)) {
        path += parent[ci][cj].first;
        pair<int, int> p = parent[ci][cj].second;
        ci = p.first;
        cj = p.second;
        if (ci == ai && cj == aj) {
            break;
        }
    }

    // cout << path << "\n";

    if (ci != ai && cj != aj) {
        cout << "NO\n";
    } else {
        reverse(path.begin(), path.end());
        cout << "YES\n" << path.length() << "\n" << path << "\n";
    }

    return 0;
}
