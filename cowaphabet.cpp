#include <iostream>
#include <string>
using namespace std;

int main(void){
    string a;
    string b;
    cin >> a;
    cin >> b;
    int count = 0;
    int count2 = 0;
    while(b != ""){
    for(int i = 0; i < a.length(); i++){
        if(b[count] == a[i]){
            b.erase(0, 1);
            }
        }
        count2++;
    }
    cout << count2 << "\n";
    
    
    return 0;
}