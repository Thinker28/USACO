/*
ID: amogh.d1
TASK: dualpal
LANG: C++ 
*/
#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

int main(void){
    ifstream cin("dualpal.in");
    ofstream cout("dualpal.out");
    int n, s;
    cin >> n >> s;
    int count = 0;
    for(int i = s + 1; count < n; i++){
        int num = i;
        int backUp = num;
        int count2 = 0;
        for(int base = 2; base <= 10; base++){
            string ans = "";
            while(num){
                ans += to_string (num % base);
                num /= base;
            }
            num = backUp;
            bool palindrome2 = true;
            for(int j = 0; j < ans.length(); j++){
                char a = (ans[j]);
                char b = ans[ans.length() - j - 1];
                if(a == b){
                    palindrome2 = true;
                }else{
                    palindrome2 = false;
                    break;
                }
            }
            if(palindrome2){
                count2++;
            }
        }
        if(count2 >= 2){
            count++;
            cout << i << "\n";
        }
    }
    return 0;
}