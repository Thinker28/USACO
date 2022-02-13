#include <iostream>

using namespace std;

int main(void){
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    for(int i = 0; i < q; i++){
        int a, b;
        cin >> a >> b;
        int ans = 0;
        for(int j = a - 1; j < b; j++){
            ans += (((int) s[j]) - 96);
        }
        cout << ans << "\n";

    }
    return 0;
}