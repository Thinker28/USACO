#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int open[26];
int close[26];

int main() {
    ifstream fin("circlecross.in");
    ofstream fout("circlecross.out");
    string s;
    fin >> s;
    
    for (int i = 0; i < 26; i++) {
        open[i] = close[i] = -1;
    }
    
    for (int i = 0; i < s.length(); i++) {
        if (open[s[i] - 'A'] == -1) {
            open[s[i] - 'A'] = i;
        } else {
            close[s[i] - 'A'] = i;
        }
        
    }
    
    int num_cross_pairs = 0;
    for (int i = 0; i < 26; i++) {
        // cout << (char) ('A' + i) << ": " << open[i] << ", " << close[i] << "\n";
        for (int j = i + 1; j < 26; j++) {
            if (open[i] < open[j] && open[j] < close[i] && close[i] < close[j]) {
                num_cross_pairs++;
            }
            else if (open[j] < open[i] && open[i] < close[j] && close[j] < close[i]) {
                num_cross_pairs++;                
            }
        }
    }
    
    fout << num_cross_pairs << "\n";
    return 0;
}