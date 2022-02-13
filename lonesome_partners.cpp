/*LANGUAGE: multi-language
Lonesome Partners
=================

Bessie and the rest of the herd totaling N (2 <= N <= 5,000) cows
have gone to the dance. For the cows-only part of the dance, two
cows are chosen as the "Belles of the Ball". Farmer John records
the X,Y coordinates (0 <= X_i <= 10,000; 0 <= Y_i <= 10,000) of all
the cows in the dance hall and then asks you to determine the indices
of the two cows who are farthest apart (which, happily, is guaranteed
to be unique). Distance is the normal cartesian distance calculated
as the square root of the sum of the squares of the differences in the
row and column coordinates.

In a dance with just eight cows:

 8 | . C . . . . . . . .
 7 | . . . . . . . . . .
 6 | . C . . . . . . . .
 5 | . . . C C . C . . .
 4 | . . . . C . . . . .
 3 | . . C . . . . . . .
 2 | . . . . . . . . . .
 1 | . . . . . . . . . C
 0 +--------------------
   0 1 2 3 4 5 6 7 8 8 9

Farmer John hopes you would choose the cows at 2,8 and 9,1 as
farthest apart.

PROBLEM NAME: lonesome

INPUT FORMAT:

* Line 1: A single integer: N

* Lines 2..N+1: Line i+1 contains the integer coordinate location of
        cow i: X_i and Y_i

SAMPLE INPUT:

8
2 6
3 3
2 8
4 5
7 5
5 5
9 1
5 4

OUTPUT FORMAT:

* Line 1: Two sorted integers that are the indices of the two cows
        that are located farthest apart.

SAMPLE OUTPUT:

3 7

OUTPUT DETAILS:

Cow #3 and Cow #7 are the cow numbers of the cows from the example in the text. */

#include <iostream>

using namespace std;

int X[5000];
int Y[5000];

int main(void){
    int N;
    int maxD = -1;
    int maxi;
    int maxj;

    cin >> N;
    for(int i=0; i < N; i++){
       cin >> X[i] >> Y[i];
    }


    for(int i=0; i < N; i++) {
        for(int j = i+1; j < N; j++) {
            int d = (X[i] - X[j])*(X[i] - X[j])+(Y[i] - Y[j])*(Y[i] - Y[j]);
            // cout << i << " " << j << ": " << d << "\n";
            if (d > maxD){
                maxD = d;
                maxi = i;
                maxj = j;
            }
        }

    }

    // cout << maxD << "\n";
    cout << maxi + 1 << " " << maxj + 1 << "\n";
}
