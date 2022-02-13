// #include <iostream>
// #include <vector>
// #include <fstream>
// #include <unordered_set>
// using namespace std;

// int n, m;
// // D, U, R, L
// int dx[4] = {1, -1, 0, 0};
// int dy[4] = {0, 0, 1, -1};
// unordered_set<int> lit;
// bool visited[100][100];
// vector<pair<int, int> > adj[10000];

// void dfs(int x, int y){
//     visited[x][y] = true;
//     // turn on lights whatever this room has a switch for
//     for (pair<int, int>  p : adj[x * n + y]) {
//         lit.insert(p.first * n + p.second);
//     }

//     // out of all the lighted rooms, try to do dfs on them if they're not visited yet
//     for (int idx : lit) {
//         int x1 = idx / n;
//         int y1 = idx % n;
//         if (visited[x1][y1]) {
//             continue;
//         }
//         bool is_close = false;
//         for (int dir = 0; dir < 4; dir++) {
//             int x2 = x1 + dx[dir];
//             int y2 = y1 + dy[dir];
//             if (x2 >= 0 && x2 < n && y2 >= 0 && y2 < n && visited[x2][y2]) {
//                 is_close = true;
//                 break;
//             }
//         }

//         if (is_close) {
//             dfs(x1, y1);
//         }
//     }
// }
// int main(void){
//     ifstream cin("lightson.in");
//     ofstream cout("lightson.out");
//     cin >> n >> m;
//     for(int i = 0; i < m; i++){
//         int a, b, c, d;
//         cin >> a >> b >> c >> d;
//         adj[(a-1) * n + (b-1)].push_back(make_pair(c-1, d-1));
//     }

//     lit.insert(0);
//     dfs(0, 0);

//     cout << lit.size() << "\n";
//     return 0;
// }
