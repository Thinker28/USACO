
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main() {
    ofstream fout("lineup.out");
    ifstream fin("lineup.in");

    int n;
    fin >> n;

    unordered_map<string, int> cow_to_idx;
    unordered_map<int, string> idx_to_cow;

    cow_to_idx["Beatrice"] = 0;
    cow_to_idx["Belinda"] = 1;
    cow_to_idx["Bella"] = 2;
    cow_to_idx["Bessie"] = 3;
    cow_to_idx["Betsy"] = 4;
    cow_to_idx["Blue"] = 5;
    cow_to_idx["Buttercup"] = 6;
    cow_to_idx["Sue"] = 7;

    idx_to_cow[0] = "Beatrice";
    idx_to_cow[1] = "Belinda";
    idx_to_cow[2] = "Bella";
    idx_to_cow[3] = "Bessie";
    idx_to_cow[4] = "Betsy";
    idx_to_cow[5] = "Blue";
    idx_to_cow[6] = "Buttercup";
    idx_to_cow[7] = "Sue";

    vector<pair<int, int> > relations;
    vector<int> ordering(8);
    for (int i = 0; i < 8; i++) {
        ordering[i] = i;
    }

    for (int i = 0; i < n; i++) {
        string cow1, trash, cow2;
        fin >> cow1 >> trash >> trash >> trash >> trash >> cow2;
        relations.push_back(make_pair(cow_to_idx[cow1], cow_to_idx[cow2]));
    }

    do {
        bool good = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 8; j++) {
                if (ordering[j] == relations[i].first) {
                    if ((j == 0 && ordering[j+1] != relations[i].second) ||
                        (j == 7 && ordering[j-1] != relations[i].second) ||
                        (ordering[j-1] != relations[i].second && ordering[j+1] != relations[i].second)) {
                        good = false;
                    }
                }
            }
        }

        if (good) {
            for (int j = 0; j < 8; j++) {
                fout << idx_to_cow[ordering[j]] << "\n";
            }
            break;
        }
    } while(next_permutation(ordering.begin(), ordering.end()));

    return 0;
}
