/*
ID: amogh.d1
TASK: milk3
LANG: C++ 
*/
#include <iostream>
#include <set>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

bool visited[20][20][20];
set<int> possible;
int maxa, maxb, maxc;
void dfs(int a, int b, int c){
    if(a < 0 || a > maxa || b < 0 || b > maxb || c < 0 || c > maxc){
        return;
    }
    if(visited[a][b][c]){
        return;
    }
    if(a == 0){
        possible.insert(c);
    }
    visited[a][b][c] = true;
    int pour1 = min(maxb - b, c);
    dfs(a, b + pour1, c - pour1);
    int pour2 = min(maxc - c, b);
    dfs(a, b - pour2, c + pour2);
    int pour3 = min(maxa - a, b);
    dfs(a + pour3, b - pour3, c);
    int pour4 = min(maxb - b, a);
    dfs(a - pour4, b + pour4, c);
    int pour5 = min(maxa - a, c);
    dfs(a + pour5, b, c - pour5);
    int pour6 = min(maxc - c, a);
    dfs(a - pour6, b, c + pour6);

}
int main(void){
    ifstream cin("milk3.in");
    ofstream cout("milk3.out");
    cin >> maxa >> maxb >> maxc;
    dfs(0, 0, maxc);
    vector<int> ans;
    for(auto p: possible){
        ans.push_back(p);
    }
    for(int i = 0; i < ans.size(); i++){
        if(i == ans.size()-1){
            cout << ans[i] << "\n";
        }else{
            cout << ans[i] << " ";
        }
    }
    return 0;
}