#include <iostream>
#include <string>
using namespace std;

int main(void){
    string a, b;
    cin >> a >> b;
    int counter = 0;
    for(int i = 0; i < a.length(); i++){
        string d = a.substr(i, b.length());
        if(d == b){
            counter++;
        }
    }
    cout << counter << "\n";
    return 0;
}