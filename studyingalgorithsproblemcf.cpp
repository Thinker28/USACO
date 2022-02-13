#include <iostream>
#include <algorithm> 
using namespace std;
 
int main(void){
    int sum = 0;
    int n, x;
    cin >> n >> x;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int count = 0;
    for(int i = 0; i < n; i++){
        if(sum + arr[i] > x){
            break;
        }else{
            sum += arr[i];
            count++;
        }
    }
    cout << count << "\n";
    return 0;
}