#include <iostream>

using namespace std;
int origLen;
char f(int length, string s, long long pos){
    if(length > pos){
        return s[length - pos];
    }
    char a = s[origLen - 1];
    s.erase(s.begin()+1);
    s = a + s;
    return f(length * 2, s, pos);
}
int main(void){
    string a;
    long long pos;
    cin >> a >> pos;
    origLen = a.length();
    cout << f(a.length(), a, pos) << "\n";
    return 0;
}