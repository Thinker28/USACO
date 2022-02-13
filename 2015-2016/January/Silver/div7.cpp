#include <fstream>
#include <iostream>
using namespace std;

int main(void){
    cin.tie(0)->sync_with_stdio;
    cout.tie(0);
    ifstream cin("div7.in");
    ofstream cout("div7.out");
    long long n;
    cin >> n;
    long long prefix[n];
    cin >> prefix[0];
    for(long long i = 1; i < n; i++){
        cin >> prefix[i];
        prefix[i] = (prefix[i-1] + prefix[i]) % 7;
    }

    long long ans = 0;
    for(long long i = n - 1; i >= 0; i--){
        for(long long j = 0; j < i; j++){
            if(!(prefix[i] - prefix[j])){
                ans = max(i - j, ans);
                break;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}


// #include <iostream>

// using namespace std;

// int main(void){
//     ifstream cin("div7.in");
//     ofstream cout("div7.out");
//     int n;
//     cin >> n;
//     int prefix[n];
//     for(int i = 0; i < n; i++){
//         cin >> prefix[i];
//         if (i != 0) {
//             prefix[i] = (prefix[i] + prefix[i-1]) % 7;
//         }
//     }

//     int min_idx_seen[7] = {-1, -1, -1, -1, -1, -1, -1};
//     int max_range = 0;
//     for (int i = 0; i < n; i++) {
//         if (min_idx_seen[prefix[i]] == -1) {
//             min_idx_seen[prefix[i]] = i;
//         } else {
//             max_range = max(max_range, i - min_idx_seen[prefix[i]]);
//         }
//     }

//     cout << max_range << "\n";
//     return 0;
// }