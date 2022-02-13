#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;
#define ll long long
int main(void){
    std::ios_base::sync_with_stdio(false);
    cin.tie(0)->sync_with_stdio;
    ifstream cin("herding.in");
    ofstream cout("herding.out");
    ll arr[3];
    cin >> arr[0] >> arr[1] >> arr[2];
    if(arr[0] > arr[1]){
        swap(arr[0], arr[1]);
    }
    if(arr[1] > arr[2]){
       swap(arr[2], arr[1]);
    }
    if(arr[0] > arr[1]){
       swap(arr[0], arr[1]);
    }
    if(arr[1] > arr[2]){
        swap(arr[2], arr[1]);
    }
    if((arr[1] - arr[0] == 2) || (arr[2] - arr[1] == 2)){
        cout << 1 << "\n";
    }else if(arr[2] - arr[1] == 1 && arr[1] - arr[0] == 1){
        cout << 0 << "\n" << 0 << "\n";
        return 0;
    }else{
        cout << 2 << "\n";
    }
    ll steps = 0;
    while(true){
        if(arr[0] > arr[1]){
            swap(arr[0], arr[1]);
        }
        if(arr[1] > arr[2]){
            swap(arr[2], arr[1]);
        }
        if(arr[0] > arr[1]){
            swap(arr[0], arr[1]);
        }
        if(arr[1] > arr[2]){
            swap(arr[2], arr[1]);
        }
        if((arr[1] - arr[0] == 1) && (arr[2] - arr[1] == 1)){
            break;
        }
        if(arr[1] - arr[0] > arr[2] - arr[1]){
            arr[2] = arr[1] - 1;
        }else{
            arr[0] = arr[1] + 1;
        }
        steps++;
    }
    cout << steps << "\n";
    return 0;
}