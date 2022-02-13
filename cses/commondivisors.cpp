#include <iostream>
#include <unordered_map>
#include <cmath>
using namespace std;

int divisors[1000001];

int main(void){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int number;
        cin >> number;
        int sqrt2 = (int)sqrt(number); 
        for(int i = 1; i <= sqrt2; i++){
            if(number % i == 0){
                divisors[number / i]++;
                if(i != number / i){
                    divisors[i]++;
                }
            }
        }
    }
    for(int i = 1e6; i >= 1; i--){
        if(divisors[i] >= 2){
            cout << i << "\n";
            break;
        }
    }
    return 0;
}