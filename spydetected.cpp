#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
    int t;
    cin >> t;
    int output[t];
    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        int arr[n];
        int count[100];
        fill(count, count + 100, 0);
        for(int j = 0; j < n; j++){
            cin >> arr[j];
        }
        for(int j = 0; j < n; j++){
            count[arr[j] - 1]++;
        }
        int pos;
        for(int j = 0; j < 100; j++){
            if(count[j] == 1){
                pos = j + 1;
                break;
            }
        }
        for(int j = 0; j < n; j++){
            if(arr[j] == pos){
                output[i] = j + 1;
                break;
            }
        }

    }
    for(int i = 0; i < t; i++){
        cout << output[i] << "\n";
    }
    
    return 0;
}