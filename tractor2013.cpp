#include <iostream>
#include <fstream>
using namespace std;


int grid[500][500];

bool visited[500][500];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int n;
int floodfill(int r, int c, int diff){
    visited[r][c] = true;
    int ans = 1;
    bool adj = false;
    for(int i = 0; i < 4; i++){
        if(r + dx[i] < n && r + dx[i] >= 0 && c + dy[i] < n && c + dy[i] >= 0 && !visited[r + dx[i]][c + dy[i]] && abs(grid[r][c] - grid[r + dx[i]][c + dy[i]]) <= diff){
            adj = true;
            ans += floodfill(r + dx[i], c + dy[i], diff);
        }
    }
    if(!adj){
        return 1;
    }
    return ans;
    
}
int main(void){
    ifstream cin("tractor.in");
    ofstream cout("tractor.out");
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }
    int low = 0;
    int high = 1e9;
    while(low < high){
        int mid = (low + high) / 2;
        bool works = false;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int count;
                if(!visited[i][j]){
                    count = floodfill(i, j, mid);
                    if(count * 2 >= ((n * n))){
                        works = true;
                        break;
                    }
                }
            }
            if(works){
                break;
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                visited[i][j] = false;
            }
        }
        if(works){
            high = mid; 
        }else{
            low = mid + 1;
        }
    }
    cout << high << "\n";
    return 0;
}