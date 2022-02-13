#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void){
    ifstream cin("haybales.in");
    ofstream cout("haybales.out");
    int n, q;
    cin >> n >> q;
    vector<int> vec;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        vec.push_back(a);
    }
    sort(vec.begin(), vec.end());
    for(int i = 0; i < q; i++){
        int a, b;
        cin >> a >> b;
        cout << (upper_bound(vec.begin(), vec.end(), b) - vec.begin() - 1) - (lower_bound(vec.begin(), vec.end(), a) - vec.begin()) + 1 << "\n";
    }
    return 0;
}