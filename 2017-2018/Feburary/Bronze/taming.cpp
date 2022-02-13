#include <iostream>
#include <fstream>

using namespace std;

int main(void){
    ifstream cin("taming.in");
    ofstream cout("taming.out");
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    if(arr[0] > 0){
        cout << -1 << "\n";
    }else{
    int min = 1;
    int max = 1;
    bool logs[n];
    for(int i = 1; i <= n; i++){
        logs[i] = false;
    }
    logs[0] = true;
    for(int i = 0; i < n; i++){
        if((i != 0 && ((arr[i] * -1)) < 0)){
            if(!logs[i - arr[i]]) logs[i - arr[i]] = true;
        }
    }
    // for(int i = 0; i < n; i++){
    //     cout << logs[i] << "\n";
    // }
 
    for(int i = 0; i < n; i++){
        // cout << logs[i] << "\n";
        if(i != 0 && logs[i] == true){
            min++;
            max++;
        }
        if(i != 0 && arr[i] == -1 && logs[i] != true){
            max++;
            }
        }
        cout << min << " " << max << "\n";
    } 
    return 0;
}
//     int min = 1;
//     int max = 1;
//     bool logs[n];
//     for(int i = 1; i <= n; i++){
//         logs[i] = false;
//     }
//     logs[0] = true;
//     for(int i = 0; i < n; i++){
//         if((i != 0 && ((arr[i] * -1)) < 0)){
//             if(!logs[i - arr[i]]) logs[i - arr[i]] = true;
//         }
//     }
//     // for(int i = 0; i < n; i++){
//     //     cout << logs[i] << "\n";
//     // }
 
//     for(int i = 0; i < n; i++){
//         // cout << logs[i] << "\n";
//         if(i != 0 && logs[i] == true){
//             min++;
//             max++;
//         }
//         if(i != 0 && arr[i] == -1 && logs[i] != true){
//             max++;
//         }
//     }
//     cout << min << " " << max << "\n";
//     return 0;
// }
// // 10
// // counter: 3
// // 0 1 2 3 4 5 6 -1 -1 1
// // logs: t f f f f f f f f t f
