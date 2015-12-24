#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

char to_upper(char ch){
	if (ch >= 'A' && ch <= 'Z')
		return ch;
	return ch - ('a' - 'A');
}

bool comp(char lhs, char rhs){
	if (to_upper(lhs) < to_upper(rhs))
		return true;
	if (to_upper(lhs) > to_upper(rhs))
		return false;
	return lhs < rhs;	
}

int main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		string word;
		cin >> word;
		sort(word.begin(), word.end(), comp);
		do{
			cout << word << "\n";
		}while (next_permutation(word.begin(), word.end(), comp));
	} 
	return 0;
}
