#include <iostream>

using namespace std;

#define ll long long
int main(void){
    int t;
    cin >> t;
    while(t--){
        ll row, col;
        cin >> row >> col;
        ll ans;
        if(row > col){
            if(row % 2 == 1){
                ans = (row - 1)*(row - 1)+1+(col - 1);
            }else{
                ans = (row*row)-(col - 1);
            }
        }else{
            if(col%2 == 1){
                ans = (col*col)-(row - 1);
            }else{
                ans = (col-1)*(col-1)+1+(row - 1);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}