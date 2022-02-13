#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(void){
    int n, x;
    cin >> n >> x;
    vector<int> t(n);
    for(int i = 0; i < n; i++){
        cin >> t[i];
    }
    map<long long, int> m;
    m[0] = 1;
    long long prefix = 0;
    long long ans = 0;
    for(int i = 0; i < n; i++){
        prefix += t[i];
        ans += m[prefix - x];
        m[prefix]++;
    }
    cout << ans << "\n";
    return 0;
}