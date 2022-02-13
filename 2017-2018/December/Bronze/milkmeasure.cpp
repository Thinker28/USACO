#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

struct measure{
    int day;
    char name;
    int change;
};

bool cmp(measure a, measure b){
    return a.day < b.day;
}

int getIdx(char name) {
    switch (name) {
        case 'B':
            return 0;
        case 'E':
            return 1;
        default: // 'M' case
            return 2;
    }
}

int main(void){
  ifstream fin("measurement.in");
  ofstream fout("measurement.out");
    int n;
    int totalM[3] = {7, 7, 7};
    bool wasMax[3] = {true, true, true};

    fin >> n;
    measure arr[n];

    for(int i = 0; i < n; i++){
        string cow;
        fin >> arr[i].day;
        fin >> cow;
        fin >> arr[i].change;
        arr[i].name = cow[0];
    }

    sort(arr, arr + n, cmp);

    int numChanges = 0;
    for(int i = 0; i < n; i++){
        // cout << arr[i].day << "\n";
        // apply each measurement
        int idx = getIdx(arr[i].name);
        totalM[idx] += arr[i].change;

        // compute the current maximum value
        int nextMaxVal = max(totalM[0], max(totalM[1], totalM[2]));
        // find out which indices are maximums in this round
        // bool changed = false;
        bool found = true;
        for (int j = 0; j < 3; j++) {
            bool isamax = (totalM[j] == nextMaxVal);
            found = found && wasMax[j] == isamax;
            // cout << "j: " << j << ", wasMax[j]: " << wasMax[j] << ", isamax: " << isamax << "\n";
            wasMax[j] = isamax;

        }

        if (!found) {
            numChanges++;
        }
    }

    fout << numChanges << "\n";
}
