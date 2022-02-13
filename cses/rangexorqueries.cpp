#include <iostream>

using namespace std;

int main(void){
    int n, q;
    cin >> n >> q;
    int prefix[n + 1];
    prefix[0] = 0;
    for(int i = 1; i <= n; ++i){
        int a;
        cin >> a;
        prefix[i] = a;
        prefix[i] ^= prefix[i - 1];
    }
    while(q--){
        int a, b;
        cin >> a >> b;
        if(a - 1 < 0){
            cout << (prefix[b] ^ prefix[a]) << "\n";
            continue;
        }
        cout << (prefix[b] ^ prefix[a - 1]) << "\n";
    }
    return 0;
}