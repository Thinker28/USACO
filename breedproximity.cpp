#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

#define ll long long
int main(void){
    cin.tie(0)->sync_with_stdio;
    ifstream cin("proximity.in");
    ofstream cout("proximity.out");
    ll n, k;
    cin >> n >> k;
    ll arr[n];
    for(ll i = 0; i < n; i++){
        cin >> arr[i];
    }
    ll max2 = -1;
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < n; j++){
            if(i == j){
                continue;
            }else{
                if(arr[i] == arr[j] && abs(j - i) <= k){
                    max2 = max(max2, max(arr[i], arr[j]));
                }
            }
        }
    }
    cout << max2 << "\n";
    return 0;
}
