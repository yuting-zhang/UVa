#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>

using namespace std;

string trim(const string& line){
	int beg = 0, end = line.size() - 1;
	while (beg < line.size() && line[beg] == ' ')
		beg++;
	while (end >= 0 && line[end] == ' ')
		end--;
	if (end < beg)
		return "";
	return line.substr(beg, end - beg + 1);
}

bool isVerb(const string& line){
	if (line.empty())
		return false;
	if (line == "hate" || line =="love" || line == "know" || line == "like")
		return true;
	if (line.back() == 's' && isVerb(line.substr(0, line.size() - 1)))
		return true;
	return false;
}

bool isArticle(const string& line){
	return line == "a" || line == "the";
}
bool isActor(const string& line){
	if (line.empty())
		return false;
	if (line == "tom" || line == "jerry" || line == "goofy" || line == "mickey" 
			|| line == "jimmy" || line == "dog" || line == "cat" || line == "mouse")
		return true;
	int space = line.find(" ");
	if (space == string::npos)
		return false;

	return isArticle(trim(line.substr(0, space))) && isActor(trim(line.substr(space + 1)));
}

bool isActiveList(const string& line){
	if (line.empty())
		return false;
	if (isActor(trim(line)))
		return true;
	int pos = line.rfind("and");
	if (pos == string::npos || pos == line.size() - 3)
		return false;

	return isActiveList(trim(line.substr(0, pos))) && isActor(trim(line.substr(pos + 3)));
}

bool isAction(const string& line){
	if (line.empty())
		return false;
	istringstream sin(line);
	string part1, verb, part2;
	bool found = false;
	while (sin >> verb){
		if (isVerb(trim(verb))){
			found = true;
			string word;
			while (sin >> word)
				part2 += word + " ";
			break;
		}
		part1 += verb + " ";
	}

	if (found && isActiveList(trim(part1)) && isActiveList(trim(part2)))
		return true;
	return false;
}

bool isStatement(const string& line){
	if (line.empty())
		return false;
	int comma = line.find_last_of(',');
	if (comma == string::npos)
		return isAction(trim(line));
	if (comma == line.size() - 1)
		return false;
	return (isStatement(trim(line.substr(0, comma))) && isAction(trim(line.substr(comma + 1))));	
}

int main(){
	string line;
	while (getline(cin, line))
		if (isStatement(trim(line)))
			printf("YES I WILL\n");
		else
			printf("NO I WON\'T\n");
	return 0;
}
