#include <iostream>
#include <vector>
using namespace std;

int main(void){
    int n;
    cin >> n;
    vector<int> vec;
    if(n == 1){
        cout << "1\n";
    }else if(n != 1 && n <= 3){
        cout << "NO SOLUTION\n";
    }else{
    for(int i = 2; i <= n; i += 2){
        vec.push_back(i);
    }
    for(int i = 1; i <= n; i += 2){
        vec.push_back(i);
    }
    for(int i = 0; i < (int)vec.size(); i++){
        cout << vec[i] << " ";
        }
    }
    return 0;
}