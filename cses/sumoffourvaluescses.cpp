#include <iostream>
#include <unordered_map>
#include <vector>
#include <random>
#include <chrono>
 
using namespace std;
using ll = long long;
 
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
 
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
struct chash { /// use most bits rather than just the lowest ones
    const uint64_t C = ll(2e18*acos((long double)-1))+71; // large odd number
    const int RANDOM = rng();
    ll operator()(ll x) const { /// https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html
        return __builtin_bswap64((x^RANDOM)*C); }
};
 
template<class K,class V> using ht = gp_hash_table<K,V,chash>;
 
int main(void){
    int n, x;
    cin >> n >> x;
    vector<int> l(n);
    for(int i = 0; i < n; i++){
        cin >> l[i];
    }
    ht<int, pair<int, int> > m;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            m[l[i] + l[j]] = make_pair(i, j);
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            int sum = l[i] + l[j];
            if(m.find(x - sum) != m.end()){
                pair<int, int> p = m[x - sum];
                if(p.first != i && p.first != j && p.second != i && p.second != j){
                    cout << p.first + 1 << " " << p.second + 1 << " " << i + 1 << " " << j + 1 << "\n";
                    return 0;
                }
            }
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}
