#include <iostream>

using namespace std;

bool visited[200000];
int main(void){
    int n;
    cin >> n;
    int cntrmvd = 0;
    int cur = 2;
    while(cntrmvd != n){
        if(!visited[cur]){
            cout << cur << " ";
            visited[cur] = true;
            cntrmvd++;
        }
        if(cur + 2 == n){
            cur += 2;
            continue;
        }
        cur = (cur+2)%n;
        
    }
    return 0;
}