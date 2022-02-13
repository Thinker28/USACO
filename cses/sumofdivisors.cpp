#include <iostream>
#include <vector>
using namespace std;

int main(void){
    int n;
    cin >> n;   
    vector<int> divisors;
    for(int i = 1; i*i <= n; i++){
        if(n % i == 0){
            divisors.push_back(i);
        }
    }
    int sum = 0;
    for(auto divisor: divisors){
        sum += divisor;
    }
    cout << sum << "\n";
    return 0;
}