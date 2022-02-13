#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void){
    int n;
    cin >> n;
    vector<pair<int, int> > v;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        v.push_back(make_pair(x, 1));
        v.push_back(make_pair(y, -1));
    }
    int m;
    cin >> m;
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        v.push_back(make_pair(x, 1));
        v.push_back(make_pair(y, -1)); 
    }
    sort(v.begin(), v.end());
    int ans = 0;
    int open = 0;
    int last = -1;
    for(auto p: v){
        if(open == 2){
            ans += p.first - last;
        }
        if(p.second == 1){
            open++;
        }else{
            open--;
        }
        last = p.first;
    }
    cout << ans << "\n";
    return 0;
}