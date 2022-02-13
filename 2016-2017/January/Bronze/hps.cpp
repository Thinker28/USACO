#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("hps.in");
ofstream fout("hps.out");

const int MAXN = 105;

int P1[MAXN];
int P2[MAXN];

int cases[6][3] = {{1,2,3}, {1,3,2}, {2,1,3}, {2,3,1}, {3,1,2}, {3,2,1}};

int who_wins(int h, int s, int p, int p1, int p2) {
    if (p1 == p2) {
        return 0; // a tie
    } else if ((p1 == h && p2 == s) || (p1 == p && p2 == h) || (p1 == s && p2 == p)) {
        return 1; // player 1 wins case
    } else {
        return 2; // player 2 wins case
    }
}

int main(void){
    int N;
    fin >> N;
    for(int i = 0; i < N; i++){
        fin >> P1[i] >> P2[i];
    }

    int max_win_count = 0;
    for (int case_num = 0; case_num < 6; case_num++) {
        int win1, win2;
        win1 = win2 = 0;
        for (int j = 0; j < N; j++) {
            int win = who_wins(cases[case_num][0], cases[case_num][1],
                    cases[case_num][2], P1[j], P2[j]);
            if (win == 1) {
                win1++;
            } else if (win == 2) {
                win2++;
            }
        }
        max_win_count = max(max_win_count, max(win1, win2));
    }

    fout << max_win_count << "\n";
}
