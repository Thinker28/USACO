// #include <iostream>
// #include <fstream>
// using namespace std;

// #define ll long long
// int main(void){
//     ifstream cin("sort.in");
//     ofstream cout("sort.out");
//     int n;
//     cin >> n;
//     ll arr[n];
//     for(int i = 0; i < n; i++){
//         cin >> arr[i];
//     }
//     bool sorted = false;
//     int moo = 0;
//     while(!sorted){
//         sorted = true;
//         moo++;
//         for(int i = 0; i < n - 1; i++){
//             if(arr[i + 1] < arr[i]){
//                 swap(arr[i + 1], arr[i]);
//                 sorted = false;
//             }
//         }
//     }
//     cout << moo << "\n";
//     return 0;
// }
