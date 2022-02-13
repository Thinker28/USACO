#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
vector<int> clocks;
vector<int> adj[100000];

int sum1 = 0;
int sum2 = 0;
int num1 = 0;
int num2 = 0;
void dfs(int node, int parent, int color){
    if(color == 0){
        sum1 += clocks[node];
        num1++;
    }else{
        sum2 += clocks[node];
        num2++;
    }
    for(auto v: adj[node]){
        if(v != parent){
            dfs(v, node, color ^ 1);
        }
    }
}
int main(void){
    ifstream cin("clocktree.in");
    ofstream cout("clocktree.out");
    int n;
    cin >> n;
    clocks = vector<int> (n);
    for(int i = 0; i < n; i++){
        cin >> clocks[i];
    }
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        adj[a - 1].push_back(b - 1);
        adj[b - 1].push_back(a - 1);
    }
    dfs(0, -1, 0);
    if(sum1%12 == sum2%12){
        cout << n << "\n";
    }else if((sum1+1)%12 == (sum2)%12){
        cout << num2 << "\n";
    }else if(sum1%12 == (sum2+1)%12){
        cout << num1 << "\n";
    }else{
        cout << 0 << "\n";
    }
    return 0;
}