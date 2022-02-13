#include <iostream>
#include <fstream>
using namespace std;

int main(void){
    ifstream cin("lifeguards.in");
    ofstream cout("lifeguards.out");
    int n;
    cin >> n;
    int x[n];
    int y[n];
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
    }

    bool intreval[1000000];
    for(int i = 0; i < 1000000; i++){
        intreval[i] = false;
    }
    int max = -1;
    for(int fired = 0; fired < n; fired++){
        int a = x[fired];
        int b = y[fired];
        x[fired] = 0;
        y[fired] = 0;
        for(int i = 0; i < n; i++){
            for(int j = x[i]; j < y[i]; j++){
                intreval[j] = true;
            }
        }
        x[fired] = a;
        y[fired] = b;
        int counter = 0;
        for(int j = 0; j < 1000000; j++){
            if(intreval[j]){
                counter++;
            }
        }
        
        if(counter > max){
            max = counter;
        }
        for(int i = 0; i < 1000000; i++){
            intreval[i] = false;
        }


    }
    cout << max << "\n";
    return 0;
}