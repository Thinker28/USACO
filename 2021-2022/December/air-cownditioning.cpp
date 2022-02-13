
#include <iostream>

using namespace std;

int main(void){
    int n;
    cin >> n;
    int target[n];
    int init[n];
    int ans = 0;
    for(int i = 0; i < n; i++){
        cin >> target[i];
    }
    for(int i = 0; i < n; i++){
        cin >> init[i];
    }
    while(true){
        int start = 0;
        int end = 0;
        int change = 0;
        bool lessthan = false;
        for(int i = 0; i < n; i++){
            if(init[i] < target[i] && !lessthan){
                start = i;
                lessthan = true;
            }else if(init[i] >= target[i] && lessthan){
                end = i;
                break;
            }
        }
        if(lessthan && end == 0){
            change++;
            for(int i = start; i < n; i++){
                init[i]++;
            }
        }else if(lessthan){
            change++;
            for(int i = start; i < end; i++){
                init[i]++;
            }
        }
        start = 0;
        end = 0;
        bool greaterthan = false;
        for(int i = 0; i < n; i++){
            if(init[i] > target[i] && !greaterthan){
                start = i;
                greaterthan = true;
            }else if(init[i] <= target[i] && greaterthan){
                end = i;
                break;
            }
        }
        if(greaterthan && end == 0){
            change++;
            for(int i = start; i < n; i++){
                init[i]--;
            }
        }else if(greaterthan){
            change++;
            for(int i = start; i < end; i++){
                init[i]--;
            }
        }
        int count = 0;
        for(int i = 0; i < n; i++){
            if(init[i] == target[i]){
                count++;
            }
        }
        ans+=change;
         
        if(count == n){
            break;
        }
    }
    cout << ans << "\n";
    return 0;
}