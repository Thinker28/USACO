#include <iostream> 
#include <fstream>
#include <string>
using namespace std;

int main(void){
    ifstream cin("censor.in");
    ofstream cout("censor.out");
    string a, b;
    cin >> a >> b;
    string tmp = "";
    for(int i = 0; i < a.length(); i++){
        tmp += a[i];
        if(tmp.size() > b.size() && tmp.substr(tmp.length() - b.length()) == b){
            tmp.resize(tmp.length() - b.length());
        }
    }
    cout << tmp << "\n";
    return 0;
}