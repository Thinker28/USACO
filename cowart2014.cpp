#include <iostream>
#include <fstream>

using namespace std;
int n;
const int MAXN = 105;
char grid[MAXN][MAXN];
bool visited1[MAXN][MAXN];
bool visited2[MAXN][MAXN];

int counter = 0;
void floodfill1(int r, int c){
    if(r < 0 || r >= n || c < 0 || c >= n){
        return;
    }
    if(visited1[r][c]){
        return;
    }
    if(grid[r][c] != 'R'){
        return;
    }
    
    visited1[r][c] = true;
    floodfill1(r + 1, c);
    floodfill1(r - 1, c);
    floodfill1(r, c + 1);
    floodfill1(r, c - 1);
}

void floodfill2(int r, int c){
    if(r < 0 || r >= n || c < 0 || c >= n){
        return;
    }
    if(visited1[r][c]){
        return;
    }
    if(grid[r][c] != 'G'){
        return;
    }
    visited1[r][c] = true;
    floodfill2(r + 1, c);
    floodfill2(r - 1, c);
    floodfill2(r, c + 1);
    floodfill2(r, c - 1);
}

void floodfill3(int r, int c){
    if(r < 0 || r >= n || c < 0 || c >= n){
        return;
    }
    if(visited1[r][c]){
        return;
    }
    if(grid[r][c] != 'B'){
        return;
    }
    visited1[r][c] = true;
    floodfill3(r + 1, c);
    floodfill3(r - 1, c);
    floodfill3(r, c + 1);
    floodfill3(r, c - 1);
}
void floodfill4(int r, int c){
    if(r < 0 || r >= n || c < 0 || c >= n){
        return;
    }
    if(visited2[r][c]){
        return;
    }
    if(grid[r][c] == 'B'){
        return;
    }
    visited2[r][c] = true;
    floodfill4(r + 1, c);
    floodfill4(r - 1, c);
    floodfill4(r, c + 1);
    floodfill4(r, c - 1);
}
void floodfill5(int r, int c){
    if(r < 0 || r >= n || c < 0 || c >= n){
        return;
    }
    if(visited2[r][c]){
        return;
    }
    if(grid[r][c] == 'R' || grid[r][c] == 'G'){
        return;
    }
    visited2[r][c] = true;
    floodfill5(r + 1, c);
    floodfill5(r - 1, c);
    floodfill5(r, c + 1);
    floodfill5(r, c - 1);
}

int main(void){
    ifstream cin("cowart.in");
    ofstream cout("cowart.out");
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }
    int total1 = 0;
    int total2 = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!visited1[i][j] && grid[i][j] == 'R'){
                floodfill1(i, j);
                total1++;
            }else if(!visited1[i][j] && grid[i][j] == 'B'){
                floodfill3(i, j);
                total1++;
            }else if(!visited1[i][j] && grid[i][j] == 'G'){
                floodfill2(i, j);
                total1++;
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!visited2[i][j] && (grid[i][j] == 'R' || grid[i][j] == 'G')){
                floodfill4(i, j);
                total2++;
            }else if(!visited2[i][j] && (grid[i][j] != 'R' && grid[i][j] != 'G') && grid[i][j] == 'B'){
                floodfill5(i, j);
                total2++;
            }
        }
    }
    cout << total1 << " " << total2 << "\n";
    
    return 0;
}
