#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void){
    long long int n;
    cin >> n;
    string a;
    cin >> a;
    long long int ans = 0;
    for(long long int i = 0; i < n; i++){
        long long int j = i;
        long long int counth = 0;
        long long int countg = 0;
        while(j < n && ((counth <= 1) || (countg <= 1))){
            if(a[j] == 'H'){
                counth++;
            }else{
                countg++;
            }   
            j++;
            if((counth == 1 || countg == 1) && (j - i) >= 3){
                ans++;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}