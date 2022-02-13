#include <iostream>

using namespace std;

const int MAXN = 1005;

int ratings[MAXN];

int main(void) {
    int N, T;

    // input N and T
    cin >> N >> T;

    // input the rating for each of the N songs
    for(int i = 0; i < N; i++){
        cin >> ratings[i];
    }

    // showing the first T songs selected
    for(int i = 0; i < T; i++){
        // select the max rated song
        int maxJ, maxR;
        maxJ = maxR = -1;

        for (int j = 0; j < N; j++) {
            cout << "j: " << j << ", ratings[j]: " << ratings[j] << "\n";
            if(ratings[j] > maxR){
                maxR = ratings[j]; // set the max rating
                maxJ = j + 1; // set the song index with max rating
            }
        }

        // distribute maxI's rating evenly across the other N-1 songs
        int amt = maxR / (N-1);
        for(int j = 0; j < N; j++){
            if(j + 1 == maxJ){
                ratings[j] = 0;
            }else{
                ratings[j] += amt;
            }
        }
        // distribute any extra amount
        int extra = maxR % (N-1);  
        for(int j = 0; extra > 0; j++){
            // don't add to the rating of the song you just played
            if (j + 1 != maxJ) {
                ratings[j]++;
                extra--;
            }
        }

        cout << "maxJ: " << maxJ << ", maxR: " << maxR << "\n";
    }


    return 0;
}
