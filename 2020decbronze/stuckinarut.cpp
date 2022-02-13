#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


bool ncmp(pair<int, pair<int, int> >  &x, pair<int, pair<int, int> > &y){
    return x.second.first < y.second.first;
}
bool ecmp(pair<int, pair<int, int> > &x, pair<int, pair<int, int> > &y){
    return x.second.second < y.second.second;
}
int main(void){
    int n;
    cin >> n;
    vector<pair<int, pair<int, int> > > ec;
    vector<pair<int, pair<int, int> > > nc;
    for(int i = 0; i < n; i++){
        char c;
        int x, y;
        cin >> c >> x >> y;
        if(c == 'E'){
            ec.push_back(make_pair(i, make_pair(x, y)));
        }else if(c == 'N'){
            nc.push_back(make_pair(i, make_pair(x, y)));
        }
    }
    int mintime[n];
    fill(mintime, mintime + n, -1);
    sort(ec.begin(), ec.end(), ecmp);
    sort(nc.begin(), nc.end(), ncmp);
    for(int i = 0; i < ec.size(); i++){
        for(int j = 0; j < nc.size(); j++){
            if((mintime[ec[i].first] == -1) && (mintime[nc[j].first] == -1) && (ec[i].second.second > nc[j].second.second) && (ec[i].second.first < nc[j].second.first) && (nc[j].second.first - ec[i].second.first <  ec[i].second.second - nc[j].second.second)){
                mintime[nc[j].first] = ec[i].second.second - nc[j].second.second;
            }else if((mintime[ec[i].first] == -1) && (mintime[nc[j].first] == -1) && (ec[i].second.second > nc[j].second.second) && (ec[i].second.first < nc[j].second.first) && (nc[j].second.first - ec[i].second.first > ec[i].second.second - nc[j].second.second)){
                mintime[ec[i].first] = nc[j].second.first - ec[i].second.first;
                break;
            }
        }
    }
    for(int i = 0; i < n; i++){
        if(i == n - 1){
            if(mintime[i] == -1){
                cout << "Infinity";
            }else{
                cout << mintime[i];
            }
        }else{
            if(mintime[i] == -1){
                cout << "Infinity\n";
            }else{
                cout << mintime[i] << "\n";
            }
        }
    }
    return 0;
}
