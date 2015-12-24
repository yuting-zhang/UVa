#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

bool is_char(char ch){
	return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}

char to_uppercase(char ch){
	if (ch >= 'A' && ch <= 'Z')
		return ch;
	return ch - ('a' - 'A');
}

int main(){
	string line;
	while (getline(cin, line) && line != "DONE"){
		int head = 0, rear = line.size();
		bool palindrome = true;
		while (head < rear){
			while (head < rear && !is_char(line[head]))
				head++;
			while (head < rear && !is_char(line[rear]))
				rear--;
			if (to_uppercase(line[head]) != to_uppercase(line[rear])){
				palindrome = false;
				break;
			}
			head++;
			rear--;
		}

		if (palindrome)
			printf("You won't be eaten!\n");
		else
			printf("Uh oh..\n");
	}
}
