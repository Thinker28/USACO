#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;

bool visited[2005][2005];
vector<pair<int, int> > grid[2005][2005];

int main(void){
    // ifstream cin("gates.in");
    // ofstream cout("gates.out");
    int n;
    cin >> n;
    string a;
    cin >> a;
    int curx = 1000;
    int cury = 1000;
    int pastx = curx;
    int pasty = cury;
    for(int i = 0; i < a.length(); i++){
        int dirx = 0;
        int diry = 0;
        if(a[i] == 'N'){
            dirx = -1;
        }else if(a[i] == 'S'){
            dirx = 1;
        }else if(a[i] == 'W'){
            diry = -1;
        }else if(a[i] == 'E'){
            diry = 1;
        }
        grid[curx + dirx][cury + diry].push_back(make_pair(pastx, pasty));
        pastx = curx;
        pasty = cury;
        curx += dirx;
        cury += diry; 
    }
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    queue<pair<int, int> > q;
    int count = 0;
    q.push(make_pair(0, 0));
    for(int i = 0; i < 2000; i++){
        for(int j = 0; j < 2000; j++){
            if(!visited[i][j]){
                while(!q.empty()){
                    int a = q.front().first;
                    int b = q.front().second;
                    q.pop();
                    for(int i = 0; i < 4; i++){
                        if(a + dx[i] >= 0 && a+dx[i] < 2000 && b+dy[i] >= 0 && b+dy[i] < 2000 && find(grid[a+dx[i]][b + dy[i]].begin(), grid[a+dx[i]][b + dy[i]].end(),make_pair(a , b)) == grid[a+dx[i]][b + dy[i]].end() && !visited[a+dx[i]][b+dy[i]]){
                            q.push(make_pair(a+dx[i], b+dy[i]));
                            visited[a+dx[i]][b+dy[i]] = true;
                        }else if(find(grid[a+dx[i]][b + dy[i]].begin(), grid[a+dx[i]][b + dy[i]].end(),make_pair(a , b)) != grid[a+dx[i]][b + dy[i]].end()){
                            break;
                        }
                    } 
                } 
                count++;
            }
        }
    }
    
    cout << count << "\n";
    return 0;
}
