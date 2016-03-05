#include <string>
#include <iostream>

using namespace std;

int main(){
	string line;
	while (getline(cin, line) && !line.empty())
		cout << line << "\n";
}
