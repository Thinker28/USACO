// #include <iostream>

// using namespace std;

// int binarySearch(int arr[], int size, int SearchValue){
//     int low = 0;
//     int high = size - 1;
//     int mid;
//     while(low <= high){
//         mid = (low + high) / 2;
//         if (SearchValue == arr[mid]){
//             return mid;
//         } else if (SearchValue < arr[mid]){
//             high = mid - 1;

//         }else{
//             low = mid + 1;
//         } 
//     }
//     return -1;
// }
// int main(void){
//     int arr[10] = {1, 2, 3, 4, 7, 8, 9, 10};
//     int b;
//     cin >> b;
//     cout << binarySearch(arr, 10, b) << "\n";
    
//     return 0;
// }

// #include <iostream>
// #include <algorithm>
// using namespace std;


// int main(void){
//     int n;
//     cin >> n;
//     int arr[n];
//     for(int i = 0; i < n; i++){
//         cin >> arr[i];
//     }
//     int *upper1 = upper_bound(arr, arr + n, 30);
//     cout << *upper1 << "\n";

//     return 0;
// }

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int search(vector<int> &a, int size, int searchVal){
    int low = 0, high = size - 1, mid;
    while(low < high){
        mid = (low + high) / 2;
        if(searchVal < a[mid]){
            high = mid;
        }else{
            low = mid + 1;
        }
    }
    return low;
}


int main(void){
    int n, q;
    cin >> n >> q;
    vector<int> arr;
    for(int i = 0; i < n; i++){
        int d;
        cin >> d;
        arr.push_back(d);
    }
    for(int i = 0; i < q; i++){
        int d;
        cin >> d;
        int d1 = search(arr, n, d);
        cout << d1 << "\n";
        if(arr[d1] == d){
            cout << d1 << "\n";
        }else{
            cout << -1 << "\n";
        }
    }
    
    return 0;
}