#include <iostream>

using namespace std;

int main(void){
    int t;
    cin >> t;
    while(t--){
        int l, r;
        cin >> l >> r;
        if((2*l-r)%3 == 0 && (2*r-l)%3 == 0 && (2*r-l) >= 0 && (2*l-r) >= 0){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
    return 0;
}