// #include <iostream>
// #include <algorithm>
// #include <fstream>

// using namespace std;

// #define ll long long

// int main(void){
//     ll n;
//     cin >> n;
//     ll arr1[n];
//     ll arr2[n];
//     for(ll i = 0; i < n; i++){
//         cin >> arr1[i];
//     }
//     for(int i = 0; i < n; i++){
//         cin >> arr2[i];
//     }
//     sort(arr1, arr1 + n);
//     ll counter2 = 0;
//     do{
//         int counter = 0;
//         for(ll i = 0; i < n; i++){
//             if(arr1[i] <= arr2[i]){
//                 counter++;
//             }
//         }
//         if(counter == n){
//             counter2++;
//         }
//     }while(next_permutation(arr1, arr1 + n));
    
//     cout << counter2 << "\n";
//     return 0;
// }
#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

#define ll long long

int main(void){
    ll n;
    cin >> n;
    ll arr1[n];
    ll arr2[n];
    for(ll i = 0; i < n; i++){
        cin >> arr1[i];
    }
    for(ll i = 0; i < n; i++){
        cin >> arr2[i];
    }
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + n);
    int ans[n];
    fill(ans, ans + n, 0);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(arr1[j] <= arr2[i]){
                ans[i]++;
            }
        }
    }
    for(int i = 0; i < n; i++){
        ans[i] -= i;
    }
    ll ans2 = 1;
    for(int i = 0; i < n; i++){
        ans2 *= ans[i];
    }
    cout << ans2 << "\n";
    return 0;
}