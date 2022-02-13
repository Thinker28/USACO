#include <iostream>
#include <set>
using namespace std;

int main(void){
    int n;
    cin >> n;
    set<int> elsie1;
    set<int> elsie2;
    for(int i = 0; i < n / 2; i++){
        int x;
        cin >> x;
        elsie1.insert(x);
    }
    for(int i = 0; i < n / 2; i++){
        int x;
        cin >> x;
        elsie2.insert(x);
    }
    set<int> bessie;
    for(int i = 2; i <= 2*n; i++){
        if(elsie1.count(i) == 0 && elsie2.count(i) == 0){
            bessie.insert(i);
        }
    }
    int ans = 0;
    for(auto x: elsie1){
        // cout << x << "\n";
        auto it = bessie.upper_bound(x);
        // cout << *it << "\n";
        if(it == bessie.end()){
            bessie.erase(it--);
        }else{
            bessie.erase(it);
            ans++;
        }
    }
    for(auto x: elsie2){
        auto it = bessie.lower_bound(x);
        if(it == bessie.begin()){
            bessie.erase(it);
        }else{
            bessie.erase(it--);
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}