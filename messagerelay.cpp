#include <iostream>
#include <fstream>
using namespace std;

const int MAXN = 4000;
bool loopy[MAXN + 1];
int main(void){
    ifstream cin("relay.in");
    ofstream cout("relay.out");
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(int i = 0; i < n; i++){
        if(arr[i] != 0 && arr[arr[i]] == i + 1){
            loopy[i + 1] = true;
            loopy[arr[i]] = true;
        }
    }
    for(int i = 0; i < n; i++){
        loopy[arr[i]] = true;
        loopy[i +  1] = true;
    }
    int counter = 0;
    for(int i = 0; i <= n; i++){
        if(!loopy[i]){
            counter++;
        }
    }
    cout << counter << "\n";
    return 0;
}