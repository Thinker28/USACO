#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    int n, k;
    cin >> n >> k;
    int arr[n];
    vector<int> slidingwin;
    vector<int> original;
    vector<int> medians;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(int i = 0; i < k; i++){
        slidingwin[i] = arr[i];
        original[i] = arr[i];
    }
    for(int i = k; i < n; i++){
        sort(slidingwin.begin(), slidingwin.end());
        if(k % 2 == 0){
            medians.push_back(slidingwin[(k / 2) - 1]);
        }else if(k % 2 == 1){
            medians.push_back(slidingwin[n / 2]);
        }
        slidingwin.erase(slidingwin.begin() + 1);
        slidingwin.push_back(arr[i]);
    }
    for(int i = 0; i < medians.size(); i++){
        cout << medians[i] << " ";
    }

    return 0;
}