#include <iostream>
#include <fstream>
using namespace std;

#define ll long long
int main(void){
    ifstream cin("overlapping-segments-1.txt");
    ll q;
    cin >> q;
    ll ans = 0;
    for(ll i = 0; i < q; i++){
        ll x, y, x2, y2;
        cin >> x >> y >> x2 >> y2;
        ll d = (min(y, y2) - max(x, x2));
        ans += max((ll)0, d);
    }
    cout << ans << "\n";
    return 0;
}