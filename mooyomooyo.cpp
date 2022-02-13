#include <iostream>
#include <fstream>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int n;
bool visited[100][10];
bool visited2[100][10];
int board[100][10];
int area;
bool check(int i, int j){
    if(i < 100 && i >= 0 && j < 10 && j >= 0){
        return true;
    }
    return false;
}
void floodfill(int r, int c){
    visited[r][c] = true;
    for(int i = 0; i < 4; i++){
        int row = r + dx[i];
        int col = c + dy[i];
        if(check(row, col) && board[row][col] == board[r][c] && !visited[row][col]){
            area++;
            floodfill(row, col);
        }
    }
}
void convert(int r, int c){
    visited2[r][c] = true;
    for(int i = 0; i < 4; i++){
        int row = r + dx[i];
        int col = c + dy[i];
        if(check(row, col) && board[row][col] == board[r][c] && !visited2[row][col]){
            convert(row, col);
        }
    }
    board[r][c] = 0;
}
void gravity(void){
    for(int j = 0; j < 10; j++){
        int top = n-1;
        int bottom = n-1;
        while(top >= 0){
            while(top >= 0 && board[top][j] == 0){
                top--;
            }
            if(top >= 0){
                board[bottom--][j] = board[top--][j];
            }

        } 
        while(bottom >= 0){
            board[bottom--][j] = 0;
        }
    }

}
int main(void){
    // ifstream cin("mooyomooyo.in");
    // ofstream cout("mooyomooyo.out"); 
    int k;
    cin >> n >> k;
    string s;
    for(int i = 0; i < n; i++){
        cin >> s;
        for(int j = 0; j < 10; j++){
            board[i][j] = s[j] - '0';
        }
    }
    bool progress = true;
    while(true){
        progress = false;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 10; j++){
                if(!visited[i][j]){
                    floodfill(i, j);
                    if(area >= k){
                        progress = true;
                        convert(i, j);
                    }
                    area = 0;
                }
            }
        }
        gravity();
        if(!progress){
            break;
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 10; j++){
                visited[i][j] = visited2[i][j] = false;
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 10; j++){
            cout << board[i][j];
        }
        cout << "\n";
    }

    return 0;
}