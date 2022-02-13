#include <iostream>
#include <fstream>
#include <set>
#include <algorithm>
using namespace std;

#define ll long long
int main(void){
    ifstream cin("number-games-1.txt");
    ll n;
    cin >> n;
    set<ll> thor;
    int loki[n];
    for(ll i = 0; i < n; i++){
        ll a;
        cin >> a;
        thor.insert(a);
    }
    for(int i = 0; i < n; i++){
        cin >> loki[i];
    }

    ll ans = 0;
    for(int i = 0; i < n; i++){
        auto it = thor.upper_bound(loki[i]);
        if(it != thor.end()){
            ans++;
            thor.erase(it);
        }
    }
    cout << ans << "\n";
    return 0;
}