#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b){
    return a.first > b.first;
}
int main(void){
    int n;
    cin >> n;
    pair<int, int> d[n];
    for(int i = 0; i < n; i++){
        cin >> d[i].first >> d[i].second;
    }
    sort(d, d + n);
    long long ans = 0;
    long long time = 0;
    for(int i = 0; i < n; i++){
        time += d[i].first;
        ans += (d[i].second - time);
    }
    cout << ans << "\n";
    return 0;
}