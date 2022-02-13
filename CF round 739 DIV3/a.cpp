#include <iostream>

using namespace std;

int main(void){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int a;
        cin >> a;
        int j = 1;
        int number = 1;
        while(j != a){
            number++;
            if(number % 3 != 0 && number % 10 != 3){
                j++;
            }
        }
        cout << number << "\n";
    }
}