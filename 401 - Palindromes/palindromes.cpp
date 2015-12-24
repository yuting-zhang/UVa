#include <iostream>
#include <cstring>
#include <string>

using namespace std;

char table[35];

bool is_mirrored(const string& line){
	string mirror;
	for (int i = 0; i < line.size(); i++){
		int index;
		if ('A' <= line[i] && line[i] <= 'Z')
			index = line[i] - 'A';
		if ('1' <= line[i] && line[i] <= '9')
			index = line[i] - '1' + 26;
		if (table[index] == ' ')
			return false;
		else
			mirror += table[index];
	}

	for (int i = 0; i < line.size(); i++)
		if (line[i] != mirror[mirror.size() - 1 - i])
			return false;
	return true;
}

bool is_palindrome(const string& line){
	for (int i = 0; i < line.size() / 2; i++)
		if (line[i] != line[line.size() - 1 - i])
			return false;
	return true;
}

int main()
{
	memset(table, ' ', sizeof(table));
	table['A' - 'A'] = 'A';
	table['E' - 'A'] = '3';
	table['H' - 'A'] = 'H';
	table['I' - 'A'] = 'I';
	table['J' - 'A'] = 'L';
	table['L' - 'A'] = 'J';
	table['M' - 'A'] = 'M';
	table['O' - 'A'] = 'O';
	table['S' - 'A'] = '2';
	table['T' - 'A'] = 'T';
	table['U' - 'A'] = 'U';
	table['V' - 'A'] = 'V';
	table['W' - 'A'] = 'W';
	table['X' - 'A'] = 'X';
	table['Y' - 'A'] = 'Y';
	table['Z' - 'A'] = '5';
	table['1' - '1' + 26] = '1';
	table['2' - '1' + 26] = 'S';
	table['3' - '1' + 26] = 'E';
	table['5' - '1' + 26] = 'Z';
	table['8' - '1' + 26] = '8';	
	string line;
	while (getline(cin, line)){
		bool mirrored = is_mirrored(line),
			 palindrome = is_palindrome(line);
		if (!mirrored && !palindrome)
			cout << line << " -- is not a palindrome.\n\n";
		else if (!mirrored && palindrome)
			cout << line << " -- is a regular palindrome.\n\n";
		else if (mirrored && !palindrome)
			cout << line << " -- is a mirrored string.\n\n";
		else if (mirrored && palindrome)
			cout << line << " -- is a mirrored palindrome.\n\n";

	}
	return 0;
}
