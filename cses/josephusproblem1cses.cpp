#include <iostream>
#include <vector>
using namespace std;

int main(void){
    int n;
    cin >> n; 
    bool elim[n];
    vector<int> people2;
    fill(elim, elim + n, false);
    int numPeopleelim = n;
    if(n == 1){
        cout << n << "\n";
        return 0;
    }
    while(numPeopleelim > 1){
        int cur_pos = 2;
        int ithperson = 0;
        if(!elim[ithperson]){
            ithperson = (ithperson % n) + 1;
        }
        if(ithperson == cur_pos){
            people2.push_back(ithperson);
            elim[ithperson] = true;
            numPeopleelim--;
        }
        cur_pos = (cur_pos % n) + 2;
    }
    for(int i = 0; i < people2.size(); i++){
        cout << people2[i] << " ";
    }
    return 0;
}