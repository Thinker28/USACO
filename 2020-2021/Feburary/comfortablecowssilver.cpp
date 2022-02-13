#include <iostream>
#include <queue>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
bool visited[1000][1000];
int main(void){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int ans = 0;
        pair<int, int> xy;
        cin >> xy.first >> xy.second;
        visited[xy.first][xy.second] = true;
        queue<pair<int, int> > bfs;
        bfs.push(make_pair(xy.first, xy.second));
        while(!bfs.empty()){
            pair<int, int> front = bfs.front();
            bfs.pop();
            int cowsadj = 0;
            pair<int, int> xy2;
            for(int i = 0; i < 4; i++){
                int x = front.first + dx[i];
                int y = front.second + dy[i];
                if(visited[x][y]){
                    cowsadj++;
                }else{
                    xy2.first = x;
                    xy2.second = y;
                }
            }
            if(cowsadj == 3){
                visited[xy2.first][xy2.second] = true;
                ans++;
                bfs.push(make_pair(xy2.first, xy2.second));
            }

        }
        cout << ans << "\n";
    }
    return 0;
}