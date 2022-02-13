#include <iostream>

using namespace std;

int main(void){
    int n;
    cin >> n;
    int arr[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }
    int diag1 = 0;
    int diag2 = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j){
                diag1 += arr[i][j];
            }else if(i == n - j - 1){
                diag2 += arr[i][j];
            }
        }
    }

    if(n%2==0){
        diag2+=arr[(n/2)-1][(n/2)-1];
    }else{
        diag2+=arr[n/2][n/2];
    }
    cout << abs(diag1-diag2) << "\n";
    return 0;
}