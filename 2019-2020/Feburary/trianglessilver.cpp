#include <iostream>
#include <fstream>

using namespace std;

#define ll long long
int main(void){
    ifstream cin("triangles.in");
    ofstream cout("triangles.out");
    ll n;
    cin >> n;
    ll x[n];
    ll y[n];
    for(ll i = 0; i < n; i++){
        cin >> x[i] >> y[i];
    }
    ll area = 0;
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < n; j++){
            for(ll k = 0; k < n; k++){
                if(x[j] == x[i] && y[k] == y[i]){
                    if(x[j] - x[i] * y[k] - y[i] < 0){
                        area += (x[j] - x[i] * y[k] - y[i]) * -1;
                    }else{
                        area += x[j] - x[i] * y[k] - y[i];
                    }
                }
            }
        }
    }
    cout << area % 1000000007 << "\n";
    return 0;
}