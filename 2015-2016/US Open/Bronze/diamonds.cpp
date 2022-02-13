#include <iostream>
#include <fstream>


using namespace std;

int main(void){
  ifstream fin("diamond.in");
  ofstream fout("diamond.out");
    int n, k;
    fin >> n >> k;
    int arr[n];

    for (int i = 0; i < n; i++){
        //inputing into array
        fin >> arr[i];
    }

    int maxCounter = 0;
    for (int ref = 0; ref < n; ref++){
        int counter = 0;
        for (int scan = 0; scan < n; scan++){
            if (arr[scan] >= arr[ref] && arr[scan] - arr[ref] <= k){
                counter++;
            }
        }
        if (counter > maxCounter){
            maxCounter = counter;
        }
    }
    fout << maxCounter;
}
