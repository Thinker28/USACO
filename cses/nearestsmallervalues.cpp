#include <iostream>
#include <stack>

using namespace std;

int main(void){
    int n;
    cin >> n;
    stack<pair<int, int> > s;
    s.push(make_pair(0, 0));
    for(int i = 1; i <= n; i++){
        int a;
        cin >> a;
        while(!s.empty() && s.top().first >= a){
            s.pop();
        }
        cout << s.top().second << " ";
        s.push(make_pair(a, i));
    }
    return 0;
}
