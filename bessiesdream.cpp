#include <iostream>
#include <queue>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int main(void){
    int n, m;
    cin >> n >> m;
    int arr[n][m];
    bool visited[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }
    queue<pair<int, int> > q;
    pair<int, int> parents[n][m];
    q.push(make_pair(0, 0));
    int curState = -1;
    while(!q.empty()){
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            if(a+dx[i] < n && b+dy[i] < m && arr[a+dx[i]][b+dy[i]] == 1){
                q.push(make_pair(a+dx[i], b+dy[i]));
                visited[a + dx[i]][b + dy[i]] = true;
                parents[a+dx[i]][b+dy[i]] = make_pair(a, b);
                curState = 1;
            }else if(a+dx[i] < n && b+dy[i] < m && arr[a+dx[i]][b+dy[i]] == 2){
                q.push(make_pair(a+dx[i],a+dy[i]));
                visited[a + dx[i]][b + dy[i]] = true;
                parents[a+dx[i]][b+dy[i]] = make_pair(a, b);
                curState = 2;
            }else if(a+dx[i] < n && b+dy[i] < m && arr[a+dx[i]][b+dy[i]] == 3 && curState == 2){
                q.push(make_pair(a+dx[i],a+dy[i]));
                visited[a + dx[i]][b + dy[i]] = true;
                parents[a+dx[i]][b+dy[i]] = make_pair(a, b);
                curState = 2;
            }else if(a+dx[i] < n && b+dy[i] < m && arr[a+dx[i]][b+dy[i]] == 4 && curState == 2){
                if(dx[i] == 0 && dy[i] == -1){
                    if(dy[i] - 1 >= 0){
                        visited[a+dx[i]][(b+dy[i])] = true;
                        q.push(make_pair(a+dx[i], b+dy[i]));
                        q.push(make_pair(a+dx[i], (b+dy[i]) - 1));
                        curState = -1;
                    }
                }else if(dx[i] == 0 && dy[i] == 1){
                    if(dx[i] + 1 < n){
                        visited[a+dx[i]][b+dy[i]] = true;
                        a.push(make_pair())
                    }
                }

            }
        }

    }
    return 0;
}