#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

#define ll long long
int main(void){
    ll x, n;
    cin >> x >> n;
    
    set<ll> arr;
    ll maxD = 0;
    for(int i = 0; i < n; i++){
        int d;
        cin >> d;
        arr.insert(d);
        maxD = max(x - *arr.end(), *arr.begin() - 0);
        maxD = max(*arr.upper_bound(d) - d, d - *arr.lower_bound(d));
        cout << maxD << "\n";

    }
    cout << maxD << "\n";
    return 0;
}