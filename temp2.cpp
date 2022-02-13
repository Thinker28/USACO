#include <iostream>

using namespace std;

int main(void){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int counter = 0;
    while(true){
        bool sorted = true;
        for(int k = 0; k < n; k++){
            if(arr[k] != k + 1){
                sorted = false;
            }
        }
        if(sorted){
            break;
        }
        int a = arr[0];
        int i;
        int r;
        for(r = n - 1; r > 0; r--){
            if(arr[r - 1] > arr[r]){
                break;
            }
        }
        // cout << "r: " << r << "\n";
        for(i = r; i < n; i++){
            if(a < arr[i]){
                break;
            }
        }
        // cout << i << "\n";
        for(int j = 1; j < i; j++){
            arr[j - 1] = arr[j];
        }
        arr[i - 1] = a;
        counter++;
    }
    cout << counter << "\n";
    return 0;
}