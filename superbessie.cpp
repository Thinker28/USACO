#include <iostream>

using namespace std;


int main(void){
    string map;
    cin >> map;
    int b, f;
    for(int i = 0; i < map.length(); i++){
        if(map[i] == 'B'){
            b = i;
        }else if(map[i] == 'F'){
            f = i;
        }
    }
    int i = max(b, f);
    int steps = 0;
    while(true){
        if(map[i-2] == 'B' || map[i-2] == 'F'){
            steps++;
            break;
        }
        if(map[i-1] == 'B' || map[i-1] == 'F'){
            steps++;
            break;
        }
        if(map[i-2] != '*'){
            i-=2;
            steps++;
        }else{
            i--;
            steps++;
        }
        cout << "ho\n";
        
    }
    cout << steps << "\n";
    return 0;
}