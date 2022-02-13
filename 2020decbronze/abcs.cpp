#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
    int arr[7];
    for(int i = 0; i < 7; i++){
        cin >> arr[i];
    }
    sort(arr, arr + 7);
    if(arr[0]+ arr[1] == arr[2]){
        cout << arr[0] << " " << arr[1] << " " << arr[3]; 
    }else{
        cout << arr[0] << " " << arr[1] << " " << arr[2] << "\n";
    }
    return 0;
}