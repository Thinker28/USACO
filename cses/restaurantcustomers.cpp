#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    int n;
    cin >> n;
    vector<pair<int, int> > lr;
    for(int i = 0; i < n; i++){
        int l, r;
        cin >> l >> r;
        lr.push_back(make_pair(l, 1));
        lr.push_back(make_pair(r, -1));
    }
    sort(lr.begin(), lr.end());
    //sort by first element
    int sum = 0;
    int ans = 0;
    for(pair<int, int> p: lr){
        sum += p.second;
        ans = max(ans, sum);
    }
    cout << ans << "\n";
    return 0;
}