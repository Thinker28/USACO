#include <iostream>

using namespace std;

int main(void){
    int n, l;
    cin >> n >> l;
    int elim[l];
    int nums[n];
    for(int i = 0; i < n; i++){
        nums[i] = i;
    }
    for(int i = 0; i < l; i++){
        cin >> elim[i];
    }
    bool visited[n];
    for(int i = 0; i < n; i++){
        visited[i] = false;
    }
    while(true){
        int cur_pos = 0;
        for(int i = 0; i < l; i++){
            if(visited[cur_pos + elim[i]] == true){
                int x = cur_pos + 1;
                while(true){
                    x += (x % n) +  1;
                    if(!visited[x]){
                        break;
                    }
                }
                visited[(x + elim[i]) % n] = true;
            }else{
                visited[(cur_pos + elim[i]) % n] = true;
            }
        }
        int counter = 0;
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                counter++;
            }
        }
        if(counter == n - 1){
            cout << cur_pos + 1;
            break;
        }
    }
    return 0;
}