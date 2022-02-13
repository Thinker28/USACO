/*
ID: amogh.d1
TASK: pprime
LANG: C++ 
*/
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int a, b;

bool check(int x){
    if(x < a || x > b){
        return false;
    }
    for(int i = 3; i*i <= x; i+=2){
        if(x % i == 0){
            return false;
        }
    }
    return true;
}
int main(void){
    ifstream cin("pprime.in");
    ofstream cout("pprime.out");
    cin >> a >> b;
    //one digit
    vector<int> ans;
    vector<int> odd;
    for(int i = 1; i <= 9; i++){
        if(i % 2 == 1){
            odd.push_back(i);
        }
    }
    for(int i = 2; i < 10; i++){
        if(check(i) && i % 2 == 1){
            ans.push_back(i);
        }
    }
    //two digit
    if(check(11)){
        ans.push_back(11);
    }
    //three digit
    for(int i: odd){
        for(int j = 0; j <= 9; j++){
            int num = 100*i+10*j+i;
            if(check(num)){
                ans.push_back(num);
            }
        }
    }
    //four digit
    for(int i: odd){
        for(int j = 0; j <= 9; j++){
            int num = 1000*i+100*j+10*j+i;
            if(check(num)){
                ans.push_back(num);
            }
        }
    }
    //five digit
    for(int i: odd){
        for(int j = 0; j <= 9; j++){
            for(int k = 0; k <= 9; k++){
                int num = 10000*i+1000*j+100*k+10*j+i;
                if(check(num)){
                    ans.push_back(num);
                }
            }
        }
    }
    //six digit
    for(int i: odd){
        for(int j = 0; j <= 9; j++){
            for(int k = 0; k <= 9; k++){
                int num = 100000*i+10000*j+1000*k+100*k+10*j+i;
                if(check(num)){
                    ans.push_back(num);
                }
            }
        }
    }

    //seven digit
    for(int i: odd){
        for(int j = 0; j <= 9; j++){
            for(int k = 0; k <= 9; k++){
                for(int l = 0; l <= 9; l++){
                    int num = 1000000*i+100000*j+10000*k+1000*l+100*k+10*j+i;
                    if(check(num)){
                        ans.push_back(num);
                    }
                }
            }
        }
    }
    //eight digit
    for(int i: odd){
        for(int j = 0; j <= 9; j++){
            for(int k = 0; k <= 9; k++){
                for(int l = 0; l <= 9; l++){
                    int num = 10000000*i+1000000*j+100000*k+10000*l+1000*l+100*k+10*j+i;
                    if(check(num)){
                        ans.push_back(num);
                    }
                }
            }
        }
    }
    for(int v: ans){
        cout << v << "\n";
    }
    return 0;
}