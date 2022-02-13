#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long
int main(void){
    ll n;
    cin >> n;
    ll arr[n];
    for(ll i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr, arr + n);
    ll median;
    if(n % 2 == 1){
        median = arr[n / 2];
    }else if(n % 2 == 0){
        median = (arr[n / 2] + arr[(n / 2) - 1]) / 2;
    }
    ll ans = 0;
    for(ll i = 0; i < n; i++){
        ans += abs(median - arr[i]);
    }
    cout << ans << "\n";
    return 0;
}