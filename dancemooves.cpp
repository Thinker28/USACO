#include <iostream>
#include <vector>
using namespace std;

int main(void){
    int n, k;
    cin >> n >> k;
    int arr[n];
    int arr2[n];
    for(int i = 1; i <= n; i++){
        arr[i - 1] = i;
        arr2[i - 1] = arr[i];
    }
    pair<int, int> swaps[k];
    for(int i = 0; i < k; i++){
        cin >> swaps[i].first >> swaps[i].second;
        swaps[i].first--;
        swaps[i].second--;
    }
    vector<int> v[n];
    int count2[n];
    int j = 0;
    while(true){
        int count = 0;
        for(int i = 0; i < n; i++){
            if(arr2[i] == arr[i]){
                count++;
            }
        }
        cout << count << "\n";
        if(count == n){
            break;
        }
        bool flag = false;
        for(int u: v[swaps[j % k].first]){
            if(u == swaps[j % k].second){
                flag = true;
                break;
            }
        }
        if(!flag){
            count2[swaps[j%k].first]++;
            v[swaps[j % k].first].push_back(swaps[j % k].second);
        }
        swap(arr2[swaps[j % k].first], arr2[swaps[j % k].second]);
        j++;
        
    }

    for(int i = 0; i < n; i++){
        cout << count2[i] + 1 << "\n";
    }
    return 0;
}