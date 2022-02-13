#include <iostream>

using namespace std;

#define ll long long
ll X[100000];
ll Y[100000];

int main(void){
    ll N; 
    cin >> N;
    for(int i=0; i < N; i++){
       cin >> X[i] >> Y[i]; 
    }
    ll minD = 1e9;
    for(int i=0; i < N; i++) {
        for(int j = i+1; j < N; j++) {
            ll d = (X[i] - X[j])*(X[i] - X[j])+(Y[i] - Y[j])*(Y[i] - Y[j]);
            // cout << i << " " << j << ": " << d << "\n";
            if (d < minD){
                minD = d;
            }
        }
        
    } 

    // cout << maxD << "\n";
    cout << minD << "\n";
}