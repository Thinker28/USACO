#include <iostream>
#include <fstream>

using namespace std;

int n;
const int MAXN = 1005;
char grid[MAXN][MAXN];
bool visited[MAXN][MAXN];
int perm = 0;
int area = 0;

void floodfill(int r, int c){
    if((r == n + 1 || r == 0) || (c == n + 1 || c == 0)){
        perm++;
        return;
    }
    if(grid[r][c] == '.'){
        perm++;
        return;
    }
    
    visited[r][c] = true;
    if(grid[r][c] == '#'){
        area++;
    }
    
    if (r + 1 <= n + 1 && !visited[r + 1][c]) {
        floodfill(r + 1, c);
    }

    if (r - 1 >= 0 && !visited[r - 1][c]) {
        floodfill(r - 1, c);
    }

    if (c + 1 <= n + 1 && !visited[r][c + 1]) {
        floodfill(r, c + 1);
    }

    if (c - 1 >= 0 && !visited[r][c - 1]) {
        floodfill(r, c - 1);
    }
}
int main(void){
    ifstream cin("perimeter.in");
    ofstream cout("perimeter.out");
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> grid[i][j];
        }
    }
    int max_area = -1;
    int perm2 = -1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(!visited[i][j] && grid[i][j] == '#'){
                floodfill(i, j);
            }
            if(area > max_area){
                max_area = area;
                perm2 = perm;
            } else if (area == max_area && perm < perm2) {
                perm2 = perm;
            }
            area = 0;
            perm = 0;
        }
    }
    cout << max_area << " " << perm2 << "\n";
    return 0;
}