#include <iostream>
#include <fstream>
using namespace std;

int perm = 0;
bool cows[100][100];
bool visited[100][100];
void floodfill(int r, int c){
    if(r >= 100 || c >= 100 || r < 0 || c < 0){
        perm++;
        return;
    }
    if(visited[r][c]){
        return;
    }
    visited[r][c] = true;
    if(!cows[r + 1][c]){
        perm++;
    }else if(!visited[r + 1][c]){
        floodfill(r + 1, c);
    }
    if(!cows[r][c + 1]){
        perm++;
    }else if(!visited[r][c + 1]){
        floodfill(r, c + 1);
    }
    if(!cows[r - 1][c]){
        perm++;
    }else if(!visited[r - 1][c]){
        floodfill(r - 1, c);
    }
}

int main(void){
    ifstream cin("perimeter.in");
    ofstream cout("perimeter.out");
    int n;
    cin >> n;
    pair<int,int> p[n];
    for(int i = 0; i < n; i++){
        cin >> p[i].first >> p[i].second;
        cows[p[i].first][p[i].second] = true;
    }
    floodfill(p[0].first, p[0].second);
    cout << perm + 1 << "\n";
    return 0;
}