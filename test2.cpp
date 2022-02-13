#include <iostream>
#include <vector>
using namespace std;

int main(void){
	string a;
	getline(cin, a);
	string newstring = "";
	bool space = false;
	for(int i = 0; i < a.length(); i++){
		if(a[i] == ' '){
			space = true;
		}
		if(!space){
			newstring += a[i];
		}
		space = false;
	}

	string newstring2 = "";
	bool visited[newstring.length()];
	fill(visited, visited+newstring.length(), false);
	for(int i = 0; i < newstring.length(); i++){
		if(i+1 < newstring.length() && newstring[i+1] == '+' && !visited[newstring[i]]){
			newstring2 += to_string(stoi(string(1, newstring[i])) + stoi(string(1, newstring[i+2])));
			visited[i+1] = true;
			visited[i+2] = true;
			continue;
		}
		if(!visited[i]){
			newstring2+=newstring[i];
		}
	}
	cout << newstring2 << "\n";
	string newstring3 = "";
	fill(visited, visited+newstring2.length(), false);
	for(int i = 0; i < newstring2.length(); i++){
		if(i+1 < newstring2.length() && newstring[i+1] == '*' && !visited[newstring[i]] && isdigit(newstring[i])){
			newstring3 += to_string(stoi(string(1, newstring2[i])) * stoi(string(1, newstring[i+2])));
			visited[i+1] = true;
			visited[i+2] = true;
			continue;
		}
		if(!visited[i]){
			newstring3 += newstring2[i];
		}
	}
	cout << newstring3 << "\n";

	return 0;
}