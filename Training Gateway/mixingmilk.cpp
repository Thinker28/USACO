/*
ID: amogh.d1
TASK: milk
LANG: C++ 
*/
#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b){
    return a.first < b.first;
}
int main(void){
    ifstream cin("milk.in");
    ofstream cout("milk.out");
    int n, m;
    cin >> n >> m;
    pair<int, int> p[m];
    for(int i = 0; i < m; i++){
        cin >> p[i].first >> p[i].second;
    }
    sort(p, p + m, cmp);
    int amt = 0;
    int cost = 0;
    //40, cost: 310 
    for(int i = 0; i < m; i++){
        if(amt + p[i].second > n){
            cost += p[i].first * (n - amt);
            amt += (n - amt);
            break;
        }else{
            cost += (p[i].second * p[i].first);
            amt += p[i].second;
        }
    }
    cout << cost << "\n";
    return 0;
}