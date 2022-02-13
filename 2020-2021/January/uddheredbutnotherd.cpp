#include <iostream>
#include <string>
using namespace std;

int main(void){
    string a;
    string b;
    cin >> a >> b;
    int count = 0;
    while(b != ""){
        for(int i = 0; i < 26; i++){
            if(b[0] == a[i]){
                b.erase(0, 1);
            }
        }
        count++;



    }
    cout << count;
    return 0;
}