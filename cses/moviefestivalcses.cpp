#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}
int main(void){
    int n;
    cin >> n;
    pair<int, int> movies[n];
    for(int i = 0; i < n; i++){
        cin >> movies[i].first >> movies[i].second;
    }
    sort(movies, movies + n, cmp);
    int curEnd = movies[0].second;
    int ans = 1;
    for(int i = 1; i < n; i++){
        if(movies[i].first >= curEnd){
            ans++;
            curEnd = movies[i].second;
        }
    }
    cout << ans << "\n";
    return 0;
}