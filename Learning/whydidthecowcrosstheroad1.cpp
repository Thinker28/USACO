#include <iostream>
#include <fstream>
using namespace std;

int main(void){
    // ifstream cin("crossroad.in");
    // ofstream cout("crossroad.out");
    int n;
    cin >> n;
    bool arr[n];
    int counter = 0;
    pair<int, int> a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i].first >> a[i].second;
        arr[i] = false;
    }
    
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            cout << "arr[i]"  << arr[i] << " " << arr[j] << "\n";
            cout << "a[i]: " << a[i].first << " " << a[j].first << "\n";
            cout << "a[i].second: " << a[i].second << " " << a[j].second << "\n";
            if((!arr[i]) && (!arr[j]) && (a[i].first == a[j].first) && (a[i].second != a[j].second)){
                counter++;
                arr[i] = true;
                arr[j] = true;
            }
            arr[j] = true;
        }
        arr[i] = true;
    }
    cout << counter << "\n";
    return 0;
}