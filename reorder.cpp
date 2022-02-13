#include <iostream>

using namespace std;

int a[105];
int b[105];
int n;
int count = 0;
void swaps(void){
    for(int i = 0; i < n; i++){
        if(a[0] == b[i]){
            swap(a[0], a[i]);
            break;
        }

    }

    for(int i = 0; i < n; i++){
        if(a[i] == b[i]){
            count++;
        }
    }
    if(count == n - 1){
        return;
    }else{
        count = 0;
    }
    swaps();
}
int main(void){
    int n;
    cin >> n;
    int a[n];
    int b[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    for(int i = 0; i < n; i++){
        
    }
    return 0;
}