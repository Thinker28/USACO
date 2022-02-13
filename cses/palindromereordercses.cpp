#include <iostream>
#include <vector>

using namespace std;


int main(void){
    string pal;
    cin >> pal;
    vector<int> a(26);
    for(int i = 0; i < pal.length(); i++){
        a[pal[i] - 'A']++;
    } 
    int check = 0; 
    for(int i = 0; i < 26; i++){
        check += (a[i]%2);
    }
    if(check > 1){
        cout << "NO SOLUTION\n";
        return 0;
    }
    string result = "";        
    for(int i = 0; i < 26; i++){
        if(a[i]%2 == 0){
            for(int j = 0; j < a[i]/2; j++){
                result += (i+'A');
            }
        }
    }
    for(int i = 0; i < 26; i++){
        if(a[i]%2==1){
            for(int j = 0; j < a[i]; j++){
                result += (i+'A');
            }
        }
    }
    for(int i = 25; i >= 0; i--){
        if(a[i]%2 == 0){
            for(int j = 0; j < a[i]/2; j++){
                result += (i+'A');
            }
        }
    }           
    cout << result << "\n"; 
    return 0;
}