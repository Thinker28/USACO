#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main(void){
    ifstream cin("angry.in");
    ofstream cout("angry.out");
    int n, k;
    cin >> n >> k;
    int cows[n];
    for(int i = 0; i < n; i++){
        cin >> cows[i];
    }
    sort(cows, cows + n);
    int low = 0;
    int high = 1e9;
    int ans = 1e9;
    while(low <= high){
        int mid = (low + high) / 2;
        int last = 0;
        int used = 0;
        while(last < n){
            used++;
            int cur = last + 1;
            while(cur < n && cows[cur] - cows[last] <= 2 * mid){
                cur++;
            }
            last = cur;
        }
        if(used <= k){
            ans = min(ans, mid);
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    cout << ans << "\n";
    return 0;
}