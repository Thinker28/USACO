#include <iostream>

using namespace std;

int main(void){
    int n, q;
    cin >> n >> q;
    int prefix[n];
    int b;
    cin >> b;
    prefix[0] = b;
    for(int i = 1; i < n; i++){
        int a;
        cin >> a;
        prefix[i] = min(prefix[i - 1], a);
    }
    while(q--){
        int a, b;
        cin >> a >> b;
        max()
    }
    
    return 0;
}