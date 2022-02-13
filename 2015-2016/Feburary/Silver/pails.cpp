#include <iostream>
#include <queue>
#include <fstream>
using namespace std;

//visited[i][j] = the number of operations it took to get to the current state if it was possible
int visited[102][102];

queue<pair<int, int> > q;
int main(void){
    //file input output
    ifstream cin("pails.in");
    ofstream cout("pails.out");
    for(int i = 0; i < 102; i++){
        for(int j = 0; j < 102; j++){
            visited[i][j] = 1e9;
        }
    }
    int x, y, k, m;
    cin >> x >> y >> k >> m;
    queue<pair<int, int> > q;
    q.push(make_pair(0, 0));
    //first state is given to be 0 from sample case
    visited[0][0] = 0;
    //bfs
    while(!q.empty()){
        pair<int, int> front = q.front();
        q.pop();
        //Operation of pouring one bucket into other
        int xamt = min(y-front.second, front.first);
        int yamt = min(x-front.first, front.second);
        //All possible instructions
        int dx[6] = {front.first, 0, x, front.first, front.first - xamt, front.first + yamt};
        int dy[6] = {0, front.second, front.second, y, front.second + xamt, front.second - yamt};
        for(int i = 0; i < 6; i++){
            //if operations +1 is greater than max operations || we have visited this state before   
            if(visited[dx[i]][dy[i]] != 1e9 || visited[front.first][front.second] + 1 > k){
                continue;
            }
            //add one because we did a operation
            visited[dx[i]][dy[i]] = visited[front.first][front.second] + 1;
            //put this on the queue for bfs
            q.push(make_pair(dx[i], dy[i]));
        }
    }
    int ans = 1e9;
    for(int i = 0; i <= x; i++){
        for(int j = 0; j <= y; j++){
            //if number of operations to get to this state it took is less than or equal to max operations
            if(visited[i][j] <= k){
                //i is the number of milk in bucket 1, j is milk in bucket 2, find the difference between the milk and target
                ans = min(ans, abs(i+j-m));
            }
        }
    }
    cout << ans << "\n";
    return 0;
}