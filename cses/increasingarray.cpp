#include <iostream>

using namespace std;

#define ll long long
int main(void){
    ll n;
    cin >> n;
    ll arr[n];
    for(ll i = 0; i < n; i++){
        cin >> arr[i];
    }
    ll past = arr[0];
    ll steps = 0;
    for(ll i = 1; i < n; i++){
        if(arr[i] < past){
            steps += past - arr[i];
            arr[i] += past - arr[i];
        }
        past = arr[i];
    }
    cout << steps << "\n";
    return 0;
}