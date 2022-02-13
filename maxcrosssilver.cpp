#include <iostream>

using namespace std;

int main(void){
    int n, k, b;
    cin >> n >> k >> b;
    bool broken[n];
    fill(broken, broken+n, false);
    for(int i = 0; i < b; i++){
        int a;
        cin >> a;
        broken[a] = true;
    }
    //build prefix sums
    pair<int, int> prefix[n];
    //val, pos
    for(int i = 0; i < n; i++){
        if(broken[i]){
            prefix[i] = make_pair(0,i) ; 
        }else{
            if(i == 0){
                prefix[i].first = 1;
                prefix[i].second = i;
            }else{
                prefix[i].first = prefix[i - 1].first + 1;
                prefix[i].second = i;
            }
        }
    }

    sort(prefix, prefix + n);
    int amt = prefix[n - 1].first;
    while(true){
        if(amt >= k){
            break;
        }
        pair<int, int> a = prefix[n - 1];
        int val1 = prefix[a.second - 1].first;
        int val2 = prefix[a.second + 1].first;
        if(val1  )
    }
    return 0;
}