#include <iostream>
#include <fstream>

using namespace std;

int main(void){
    ifstream fin("badmilk.in");
    ofstream fout("badmilk.out");
    int n, m, d, s;
    fin >> n >> m >> d >> s;
    int record[d][3];
    int sick[s][2];
    bool badmilk[m];
    bool people[n];
    for(int i = 0; i < d; i++){
        for(int j = 0; j < 3; j++){
            fin >> record[i][j];
        }
    }
    for(int i = 0; i < s; i++){
        for(int j = 0; j < 2; j++){
            fin >> sick[i][j];
        }
    }
    for(int i = 0; i < m; i++){
        badmilk[i] = false;
    }
    for(int i = 0; i < n; i++){
        people[i] = false;
    }
    for(int i = 0; i < m; i++){
        int milkNum = i + 1;
        int counter = 0;
        for(int si = 0; si < s; si++){
            int sickPerson = sick[si][0];
            int sickTime = sick[si][1];
            for(int di = 0; di < d; di++){
                if(record[di][0] == sickPerson && record[di][1] == milkNum && record[di][2] < sickTime){
                    counter++;
                    break;
                }
            }
        }
        if(counter == s){
            badmilk[milkNum] = true;
        }


    }
    int counter = 0;
    for(int i = 0; i < n; i++){
        int personNum = i + 1;
        for(int di = 0; di < d; di++){
            if(record[di][0] == personNum && badmilk[record[di][1]] == true){
                people[i] = true;
            }
        }
    }
    for(int i = 0; i < n; i++){
        if(people[i]){
            counter++;
        }
    }
    fout << counter << "\n";
    
    
    return 0;
}