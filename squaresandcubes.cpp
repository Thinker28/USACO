#include <iostream>
#include <set>

using namespace std;

int main(void){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        set<int> a;
        for(int i = 1; i*i <= n; i++){
            a.insert(i*i);
        }
        for(int i = 1; i*i*i <= n; i++){
            a.insert(i*i*i);
        }
        cout << a.size() << "\n";
    }
    return 0;
}