// #include <iostream>
// #include <fstream>
// #include <queue>

// using namespace std;

// #define ll long long
// int main(void){
//     ifstream cin("angry.in");
//     ofstream cout("angry.out");
//     int n;
//     cin >> n;
//     ll bales[n];
//     for(int i = 0; i < n; i++){
//         cin >> bales[i];
//     }
//     int maxHit = -1;
//     for(int start = 0; start < n; start++){
//         bool marked[n];
//         fill(marked, marked + n, false);
//         queue<pair<ll, int> > q;
//         q.push(make_pair(bales[start], 0));
//         int hit = 0;
//         while(!q.empty()){
//             pair<ll, int> p = q.front();
//             q.pop();
//             for(int i = 0; i < n; i++){
//                 if(!marked[i] && abs(p.first - bales[i]) < p.second + 1){
//                     marked[i] = true;
//                     q.push(make_pair(bales[i], p.second + 1));
//                     hit++;
//                 }

//             }
//         }
//         maxHit = max(hit, maxHit);
        
//     }
//     cout << maxHit << "\n";
//     return 0;
// }
//sol2 recursion

#include <iostream>
#include <fstream>
using namespace std;

int bales[105];
int ans = 0;
bool visited[105];
void dfs(int original, int radius, int size){
    visited[original] = true;
    for(int i = 0; i < size; i++){
        if(abs(bales[original] - bales[i]) <= radius && !visited[i]){
            ans++;
            dfs(i, radius++, size);
        }
    }
}
int main(void){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> bales[i];
    }
    int ans2 = -1;
    for(int start = 0; start < n; start++){
        fill(visited, visited + n, false);
        dfs(start, 1, n);
        ans2 = max(ans, ans2);
        ans = 0;
    }
    cout << ans2 << "\n";
    return 0;
}