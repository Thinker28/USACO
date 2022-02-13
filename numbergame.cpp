#include <iostream>

using namespace std;

#define ll long long
int maxlen[10];
bool visited[10];
int length2(int a){
    int i = 0;
    while(a != 0){
        i++;
        a /= 10;
    }
    return i;
}
ll max2 = -1;
void dfs(string a){
    if(a.length() == 9){
        max2 = max(max2, (ll)stoi(a));
        return;
    }
    for(int i = 0; i < 10; i++){
        if(a.length() + i <= 9 && !visited[i] && maxlen[i] != 0){
            visited[i] = true;
            dfs(a+to_string(maxlen[i]));
            visited[i] = false;
        }
    }
}
int main(void){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        maxlen[length2(a)] = max(maxlen[length2(a)], a); 
    }
    dfs("");
    if(max2 == -1){
        cout << "IMPOSSIBLE\n";
    }else{
        cout << max2 << "\n";
    }
    return 0;
}