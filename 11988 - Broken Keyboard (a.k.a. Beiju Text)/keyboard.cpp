#include <iostream>
#include <string>
#include <list>
#include <cstdio>

using namespace std;

int main(){
	string line;
	while (getline(cin, line)){
		list<char> output;
		auto it = output.begin();
		for (auto ch: line){
			if (ch == '[')
				it = output.begin();
			else if (ch == ']')
				it = output.end();
			else
				output.insert(it, ch);
		}
		for (auto ch: output)
			printf("%c", ch);
		printf("\n");
	}
	return 0;
}
