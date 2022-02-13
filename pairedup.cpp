#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(pair<int )
int main(void){
    ifstream cin("pairup.in");
    ofstream cout("pairup.out");
    int n;
    cin >> n;
    vector<pair<int, int> > cows;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        cows.push_back(make_pair(a, b));
    }
    sort(cows.begin(),cows.end(),[](pair<int, int> &x, pair<int, int> &y){return x.second < y.second;});
    int left = 0;
    int right = n - 1;
    int ans = -1;
    while(left <= right){
        int x = min(cows[left].first, cows[right].first);
        ans = max(ans, cows[left].second + cows[right].second);
        if(left == right){
            x /= 2;
        }
        cows[left].first -= x;
        cows[right].first -= x;
        if(cows[left].first == 0){
            left++;
        }
        if(cows[right].first == 0){
            right--;
        }
    }
    cout << ans << "\n"; 
    return 0;
}