#include <iostream>
#include <fstream>
#include <set>
#include <algorithm>
using namespace std;

int main(void){
    ifstream cin("highcard.in");
    ofstream cout("highcard.out");
    int n;
    cin >> n;
    set<int> bessie;
    set<int> elsie;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        elsie.insert(a);
    }
    for(int i = 1; i <= 2 * n; i++){
        if(elsie.count(i) == 0){
            bessie.insert(i);
        }
    }
    int ans = 0;
    for(int v: elsie){
        auto it = bessie.upper_bound(v);
        if(it == bessie.end()){
            break;
        }else{
            ans++;
            bessie.erase(it);
        }
    }
    cout << ans << "\n";
    return 0;
}