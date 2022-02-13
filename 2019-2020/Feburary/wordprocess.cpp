#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(void){
    ifstream cin("word.in");
    ofstream cout("word.out");
    int n, k;
    cin >> n >> k;
    int count = 0;
    bool wordInline = false;
    for(int i = 0; i < n; i++){
        string a;
        cin >> a;
        if(count + a.length() > k){
            cout << "\n" << a;
            wordInline = true;
            count = a.length();
        }else if(!wordInline && count + a.length() <= k){
            cout << a;
            wordInline = true;
            count += a.length();
        }else if(wordInline && count + a.length() <= k){
            cout << " " << a;
            count += a.length();
        }
    }
    return 0;
}