#include <iostream>
#include <fstream>

using namespace std;

#define ll long long

int main(void){
    ifstream cin("cow.in");
    ofstream cout("cow.out");
    int n;
    cin >> n;
    string a;
    cin >> a;
    int c = 0;
    int co = 0;
    int cow = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 'C') {
            c++;
        } else if(a[i] == 'O'){
            co += c;
        }else if(a[i] == 'W'){
            cow += co;
        }
    }

    cout << cow << "\n";
    return 0;
}
// #include <iostream>

// using namespace std;

// int main(void){
//     int n;
//     cin >> n;
//     string a;
//     cin >> a;
//     for(int i = 0; i < a.length(); i++){

//     }
//     return 0;
// }