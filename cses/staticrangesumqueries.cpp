#include <iostream>

using namespace std;

#define ll long long
int main(void){
    ll n, q;
    cin >> n >> q;
    ll prefix[n];
    ll past = 0;
    for(int i = 0; i < n; i++){
        ll a;
        cin >> a;
        prefix[i] = a + past;
        past += a;
    }
    for(int i = 0; i < q; i++){
        ll a, b;
        cin >> a >> b;
        a--, b--;
        if(a - 1 < 0){
            cout << prefix[b] << "\n";
        }else{
            cout << prefix[b] - prefix[a - 1] << "\n";
        }
    }

    return 0;
}