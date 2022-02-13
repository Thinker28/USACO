/*
ID: amogh.d1
TASK: palsquare
LANG: C++ 
*/
#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

bool convertNeeded(int n){
    if(n >= 0 && n <= 9){
        return false;
    }else{
        return true;
    }
}
char convert(int n){
    return 'A' + (n - 10);
}

int main(void){
    ifstream cin("palsquare.in");
    ofstream cout("palsquare.out");
    int base;
    cin >> base;
    for(int i = 1; i <= 300; i++){
        string ans = "";
        int num = i * i;
        while(num){
            if(convertNeeded(num % base)){
                ans += convert(num % base);
            }else{
                ans += to_string (num % base);
            }
            num /= base;
        }
        bool works = true;
        for(int j = 0; j < ans.length(); j++){
            if(ans[j] != ans[ans.length() - j - 1]){
                works = false;
            }
        }
        int num2 = i;
        string ans2 = "";
        while(num2){
            if(convertNeeded(num2 % base)){
                ans2 += convert(num2 % base);
            }else{
                ans2 += to_string (num2 % base);
            }
            num2 /= base;
        }
        reverse(ans2.begin(), ans2.end());
        if(works){
            cout << ans2 << " " << ans << "\n";
        }
    }
    return 0;
}