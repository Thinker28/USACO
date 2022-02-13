#include <iostream>
#include <vector>
using namespace std;

int n, m;
char grid[1000][1000];
bool visited[1000][1000];
int area;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
bool bounds(int r, int c){
    if(r < n && r >= 0 && c >= 0 && c < m){
        return true;
    }
    return false;
}
void floodfill(int r, int c){
    visited[r][c] = true;
    for(int i = 0; i < 4; i++){
        int a = r+dx[i];
        int b = c+dy[i];
        if(bounds(a, b) && !visited[a][b] && grid[a][b] == '#'){
            area++;
            floodfill(a, b);
        }
    }
}
int main(void){
    vector<int> areas;
    area = 0;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!visited[i][j] && grid[i][j] == '#'){
                floodfill(i, j);
                areas.push_back(area+1);
                area = 0;
            }
        }
    }
    int max_area = -1;
    for(int i = 0; i < areas.size(); i++){
        if(areas[i] > max_area){
            max_area = areas[i];
        }
    }
    int ans = 0;
    for(int i = 0; i < areas.size(); i++){
        if(areas[i] == max_area){
            ans++;
        }
    }
    cout << max_area << " " << ans << "\n";
    return 0;
}