#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main(void){
    // ifstream cin("swap.in");
    // ofstream cout("swap.out");
    int n, m, k;
    cin >> n >> m >> k;
    int arr[n];
    int original[n];
    for(int i = 0; i < n; i++){
        arr[i] = i + 1;
        original[i] = i + 1; 
    }
    pair<int, int> swaps[m];
    for(int i = 0; i < m; i++){
        cin >> swaps[i].first >> swaps[i].second;
    }
    for(int i = 0; i < m; i++){
        reverse(arr + swaps[i].first - 1, arr + swaps[i].second);
    }
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
        for(int i = 0; i < m; i++){
            reverse(arr + swaps[i].first - 1, arr + swaps[i].second);
        }
        count++;
    }   
    for(int i = 0; i < k % count; i++){
        for(int j = 0; j < m; j++){
            reverse(original + swaps[j].first - 1, original + swaps[j].second);
        }
    }
    for(int i = 0; i < n; i++){
        cout << original[i] << "\n";
    }
    return 0;
}