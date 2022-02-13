#include <iostream>
#include <fstream>
#include <set>
using namespace std;

int main(void){
    freopen("citystate.in", "r", stdin);
    freopen("citystate.out", "w", stdout);
    int n;
    cin >> n;
    multiset<pair<string, string> > us;
    for(int i = 0; i < n; i++){
        string a, b;
        cin >> a >> b;
        us.insert(make_pair(a.substr(0, 2), b));
    }
    long long ans = 0;
    while(!us.empty()) {
        auto it = us.begin();
        if (it->first != it->second) {
            ans += us.count(make_pair(it->second, it->first));
        }
        us.erase(it);
    }
    cout << ans << "\n";
    return 0;
}