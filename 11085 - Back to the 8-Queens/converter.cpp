#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main(){
	ifstream fin("precalc.out");
	ofstream fout("queen.cpp");
	string line;
	fout << "const int[92][8] solution = {{";
	while (getline(fin, line)){
		istringstream sin(line);
		int sol[8];
		for (int i = 0; i < 8; i++)
			sin >> sol[i];
		fout << sol[0];
		for (int i = 1; i < 8; i++)
			fout << ", " << sol[i];
		fout << "},\n";
		fout << "                             {";
	}
	fout << "}\n";
}
