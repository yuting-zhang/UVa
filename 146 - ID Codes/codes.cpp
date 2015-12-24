#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main(){
	string line;
	while (getline(cin, line) && line != "#"){
		if (next_permutation(line.begin(), line.end()))
			cout << line << "\n";
		else
			cout << "No Successor\n";
	}
	return 0;
}
