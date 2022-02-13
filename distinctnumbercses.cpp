#include <iostream>
#include <set>

using namespace std;

int main(void){
    int n;
    cin >> n;
    set<int> a;
    for(int i = 0; i < n; i++){
        int b;
        cin >> b;
        a.insert(b);
    }
    cout << a.size();
    return 0;
}