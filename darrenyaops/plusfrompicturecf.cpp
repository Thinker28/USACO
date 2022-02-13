#include <iostream>

using namespace std;

char grid[500][500];
bool visited[500][500];
int n, m;
bool center(int i, int j){
    if(grid[i][j] == '*' && grid[i - 1][j] == '*' && grid[i][j - 1] == '*' && grid[i + 1][j] == '*' && grid[i][j + 1] == '*'){
        return true;
    }
}
bool leftray(int x, int y){
    while(true){
        if(y - 1 < 0){
            return true;
        }
        if(grid[x][y - 1] == '*' && ((grid[x - 1][y - 1] == '.' && grid[x + 1][y - 1] == '.'))){
            visited[x][y - 1] = true;
            y--;
        }else if(grid[x][y - 1] != '.' && ((grid[x - 1][y - 1] != '.' || grid[x + 1][y - 1] != '.'))){
            return false;
        }else if(grid[x][y - 1] != '.' && ((grid[x - 1][y - 1] == '.' && grid[x + 1][y - 1] == '.'))){
            return true;
        }
    }
}
bool rightray(int x, int y){
    while(true){
        if(y + 1 > m){
            return true;
        }
        if(grid[x][y + 1] == '*' && ((grid[x - 1][y + 1] == '.' && grid[x + 1][y + 1] == '.'))){
            visited[x][y + 1] = true;
            y++;
        }else if(grid[x][y + 1] == '.' && ((grid[x - 1][y + 1] != '.' || grid[x + 1][y + 1] != '.'))){
            return false;
        }else if(grid[x][y + 1] == '.' && ((grid[x - 1][y + 1] == '.' && grid[x + 1][y + 1] == '.'))){
            return true;
        }
    }
}
bool upray(int x, int y){
    while(true){
        if(x - 1 < 0){
            return true;
        }
        if(grid[x - 1][y] == '*' && ((grid[x - 1][y + 1] == '.' && grid[x - 1][y - 1] == '.'))){
            visited[x - 1][y] = true;
            x--;
        }else if(grid[x - 1][y] == '.' && ((grid[x - 1][y + 1] != '.' || grid[x - 1][y - 1] != '.'))){
            return false;
        }else if(grid[x - 1][y] == '.' && ((grid[x - 1][y + 1] == '.' && grid[x - 1][y - 1] == '.'))){
            return true;
        }
    }
}
bool downray(int x, int y){
    while(true){
        if(x + 1 > n){
            return true;
        }
        if(grid[x + 1][y] == '*' && ((grid[x + 1][y - 1] == '.' && grid[x + 1][y + 1] == '.'))){
            visited[x + 1][y] = true;
            x++;
        }else if(grid[x + 1][y] != '.' && ((grid[x + 1][y - 1] != '.' || grid[x + 1][y + 1] != '.'))){
            return false;
        }else if(grid[x + 1][y] == '.' && ((grid[x + 1][y - 1] == '.' && grid[x + 1][y + 1] == '.'))){
            return true;
        }
    }
}
bool otherpieces(void){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == '*' && !visited[i][j]){
                return false;
            }
        }
    }
    return true;
}
int main(void){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }
    int x = -1, y = -1;
    for(int i = 1; i < n - 1; i++){
        for(int j = 1; j < m - 1; j++){
            if(center(i, j)){
                x = i;
                y = j;
                break;
            }
        }
    }
    if(x == -1 && y == -1){
        cout << "NO\n";
        return 0;
    }
    if(upray(x, y) && leftray(x, y) && downray(x, y) && rightray(x, y)){
        if(otherpieces()){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }else{
        cout << "NO\n";
        return 0;
    }
    return 0;
}