#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int main(void){
    int n;
    cin >> n;
    vector<string> vec;
    vector<int> count2;
    int count[1000];
    fill(count, count + 1000, 0);
    for(int i = 0; i < n; i++){
        string a, b, c;
        cin >> a >> b >> c;
        vector<string> str;
        str.push_back(a);
        str.push_back(b);
        str.push_back(c);
        do{
            string str2 = vec[0] + vec[1] + vec[2];
            auto it = find(vec.begin(), vec.end(), str2);
            if(it != vec.end()){c
                count[count2[it - vec.begin()]]++;
            }else{
                vec.push_back(vec[0] + vec[1] + vec[2]);
                count2.push_back(i);
            }

        }while(next_permutation(str.begin(), str.end()));
        str.clear();
    }
    int ans = -1;
    for(int i = 0; i < 1000; i++){
        ans = max(ans, count[i] + 1);
    }
    cout << ans << "\n";
    return 0;
}