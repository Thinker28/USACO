#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b){
    return a.first < b.first;
}
int main(void){
    int n, m;
    cin >> n >> m;
    vector<pair<int, int> > num_idx;
    int arr[n];
    for(int i = 1; i <= n; i++){
        int a;
        cin >> arr[i];
        
    }
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        swap(arr[a - 1], arr[b - 1]);
    }
    for(int i = 0; i < n; i++){
        num_idx.push_back(make_pair(arr[i], i));
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