#include <iostream>

using namespace std;

int main(void){
    string a, b;
    cin >> a >> b;
    int ans = 0;
    for(int i = a.length(); i < b.length(); ++i){
        int arr[i];
        for(int j = 0; j < 10; j++){
            for(int k = 0; k < i; k++){
                arr[k] = j;
            }
            for(int j2 = 0; j2 < i; j2++){
                int a = arr[j2];x
                for(int k = 0; k < 10; k++){
                    arr[j2] = k;
                    string a2 = "";
                    for(int k2 = 0; k2 < i; k2++){
                        a2 += to_string(arr[i]);
                    }
                    if(stoi(a2) < stoi(b) && a2[0] != 0){
                        ans++;
                    }
                }
                arr[j2] = a;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}