#include <iostream>

using namespace std;

const int mod = 1e9+7;
int main(void){
    int n;
    cin >> n;
    int ans = 1;
    for(int i = 0; i < n; i++){
        ans = ans * 2%mod;
    }
    cout << ans << "\n";
    return 0;
}