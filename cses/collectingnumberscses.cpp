#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b){
    return a.first < b.first;
}
int main(void){
    int n;
    cin >> n;
    vector<pair<int, int> > num_idx;
    for(int i = 1; i <= n; i++){
        int a;
        cin >> a;
        num_idx.push_back(make_pair(a, i));
    }
    sort(num_idx.begin(), num_idx.end(), cmp);
    int ans = 1;
    for(int i = 0; i < n - 1; i++){
        if(num_idx[i + 1].second < num_idx[i].second){
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}