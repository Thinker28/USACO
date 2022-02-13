#include <iostream>
#include <algorithm>
using namespace std;

struct toy{
    int id;
    int joy;
    int price;
};

bool cmp(toy a, toy b){
    return a.joy * b.price > a.price * b.joy;
}
int main(void){
    int n;
    cin >> n;
    toy toys[n];
    for(int i = 0; i < n; i++){
       cin >> toys[i].joy >> toys[i].price;
       toys[i].id = i + 1;
    }

    sort(toys, toys + n, cmp);

    int totalP = 0;
    for(int i = 0; i < 3; i++){
        totalP += toys[i].price;
    }

    cout << totalP << "\n";
    for(int i = 0; i < 3; i++){
        cout << toys[i].id << "\n";
    }

    return 0;
}
