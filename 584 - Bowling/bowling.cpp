#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>

using namespace std;

int getScore(char ch, char prev_ch = '0'){
	if (ch == '/')
	   return 10 - (prev_ch - '0');
	else if ( ch == 'X')
		return 10;
	else 
		return ch - '0';
}

int main(){
	string line;
	while (getline(cin, line) && line != "Game Over"){
		istringstream sin(line);
		char ch;
		char rolls[50];
		int count = 0;
		while (sin >> ch)
			rolls[count++] = ch;
		int frame = 1, score = 0;
		bool first = false;

		for (int i = 0; i < count; i++){
			if (rolls[i] == '/'){
				frame++;
				score += getScore(rolls[i], rolls[i - 1]) + getScore(rolls[i + 1]);
				first = false;
			}
			else if (rolls[i] == 'X'){
				frame++;
				score += getScore(rolls[i]) + getScore(rolls[i + 1]) + getScore(rolls[i + 2], rolls[i + 1]);
				first = false;
			}
			else{
				if (first){
					frame++;
					first = false;
				}
				else 
					first = true;
				score += getScore(rolls[i]);
			}
			if (frame > 10)
				break;	
		}	
		printf("%d\n", score);
	}
	return 0;
}
