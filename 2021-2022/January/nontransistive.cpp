#include <iostream>

using namespace std;


struct Die{
	int face1;
	int face2;
	int face3;
	int face4;
};

int m(Die a, int i){
	if(i == 0){
		return a.face1;
	}else if(i == 1){
		return a.face2;
	}else if(i == 2){
		return a.face3;
	}else{
		return a.face4;
	}
}
bool beats(Die a, Die b){
	int win, loss;
	win = loss = 0;
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			int face1x = m(a, i);
			int face2x = m(b, j);
			if(face1x > face2x){
				win++;
			}else if(face1x < face2x){
				loss++;
			}
		}
	}
	return win > loss;
}
int main(void){
	int testcases;
	cin >> testcases;
	for(int t = 0; t < testcases; t++){
		bool ans = false;
		Die a, b;
		cin >> a.face1 >> a.face2 >> a.face3 >> a.face4 >> b.face1 >> b.face2 >> b.face3 >> b.face4;
		for(int face1c = 1; face1c <= 10; face1c++){
			for(int face2c = 1; face2c <= 10; face2c++){
				for(int face3c = 1; face3c <= 10; face3c++){
					for(int face4c = 1; face4c <= 10; face4c++){
						Die c;
						c.face1 = face1c;
						c.face2 = face2c;
						c.face3 = face3c;
						c.face4 = face4c;
						
						if(beats(a, b) && beats(b, c) && beats(c, a)){
							ans = true;
							break;
						}
						if(beats(b, a) && beats(a, c) && beats(c, b)){
							ans = true;
							break;
						}
					}
					if(ans){
						break;
					}
				}
				if(ans){
					break;
				}
			}
			if(ans){
				break;
			}
		}
		if(ans){
			cout << "yes\n";
		}else{
			cout << "no\n";
		}
	}
	return 0;
}