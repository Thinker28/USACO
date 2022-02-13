#include <iostream>
#include <fstream>
#include <set>
#include <vector>
using namespace std;

vector<pair<char, pair<int, int> > > instructions;
vector<int> colors2;
int color[15];
int ans = 0;
void dfs(int i, int n){
    if(i == n - 1){
        for(int v: colors2){
            color[i] = v;   
            int count = 0;
            for(pair<char, pair<int, int> > p : instructions){
                if(color[p.second.first] == color[p.second.second] && p.first == 'S'){
                    count++;
                }else if(color[p.second.first] != color[p.second.second] && p.first == 'D'){
                    count++;
                }
            }
            if(count == instructions.size()){
                ans++;
            }
        }
        return;
    }
    for(int v: colors2){
        color[i] = v;
        dfs(i + 1, n);
    }
}
int main(void){
    ifstream cin("assign.in");
    ofstream cout("assign.out");
    colors2.push_back(1);
    colors2.push_back(2);
    colors2.push_back(3);
    int cows, numI;
    cin >> cows >> numI;
    for(int i = 0; i < numI; i++){
        char a;
        int b, c;
        cin >> a >> b >> c;
        instructions.push_back(make_pair(a, make_pair(b, c)));
    }
    dfs(0, cows);
    cout << ans << "\n";
    return 0;
}