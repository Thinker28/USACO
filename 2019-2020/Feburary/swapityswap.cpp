// #include <iostream>
// #include <algorithm>
// #include <fstream>

// using namespace std;

// int main(void){
//     ifstream cin("swap.in");
//     ofstream cout("swap.out");
//     int n, k;
//     cin >> n >> k;
//     int a, b, c, d;
//     cin >> a >> b >> c >> d;
//     int arr[n];
//     for(int i = 0; i < n; i++){
//         arr[i] = i + 1;
//     }
//     for(int i = 0; i < k; i++){
//         reverse(arr + a - 1, arr + b);
//         // for(int j = 0; j < n; j++){
//         //     if(j == n - 1){
//         //         cout << arr[j] << "\n";
//         //     }else{
//         //         cout << arr[j] << " ";
//         //     }
            
//         // }
//         reverse(arr + c - 1, arr + d);
//         // for(int j = 0; j < n; j++){
//         //     cout << arr[j] << " ";
//         // }
//     }
//     for(int i = 0; i < n; i++){
//         cout << arr[i] << "\n";
//     }
//     return 0;
// }
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main(void){
    ifstream cin("swap.in");
    ofstream cout("swap.out");
    int n, k;
    cin >> n >> k;
    int arr[n];
    int original[n];
    for(int i = 0; i < n; i++){
        arr[i] = i + 1;
        original[i] = i + 1; 
    }
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    reverse(arr + a - 1, arr + b);
    reverse(arr + c - 1, arr + d);
    int count = 1;
    while(true){
        int counter = 0;
        for(int i = 0; i < n; i++){
            if(arr[i] == i + 1){
                counter++;
            }
        }
        if(counter == n){
            break;
        }
        reverse(arr + a - 1, arr + b);
        reverse(arr + c - 1, arr + d);
        count++;
    }   
    for(int i = 0; i < k % count; i++){
        reverse(original + a - 1, original + b);
        reverse(original + c - 1, original + d);
    }
    for(int i = 0; i < n; i++){
        cout << original[i] << "\n";
    }
    return 0;
}