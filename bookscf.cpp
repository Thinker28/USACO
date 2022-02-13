#include <iostream>

using namespace std;

int main(void){
    int n, x;
    cin >> n >> x;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int left = 0;
    int right = left + 1;
    int sum = arr[left];
    int ans = 0;
    while(left < right && right < n){
        if(sum > x){
            break;
        }
        sum += arr[right];
        ans++;
    }
    cout << ans << "\n";
    return 0;
}