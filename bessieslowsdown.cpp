#include <iostream>

using namespace std;

int main(void){
    int n;
    cin >> n;
    char symbol[n];
    int num[n];
    for(int i = 0; i < n; i++){
        cin >> symbol[i] >> num[i];
    }
    int time = 0;
    int seconds = 0;
    double distance = 0;
    int speed = 1;
    while(true){
        if(distance == 1000){
            break;
        }
        for(int i = 0; i < n; i++){
            if(time == num[i] && symbol[i] == 'T'){
                speed++;
            }else if(distance == num[i] && symbol[i] == 'D'){
                speed++;
            }
        }
        cout << 1 / speed << "\n";
        distance += 1 / speed;
        seconds++;
    }
    cout << seconds << "\n";
    return 0;
}