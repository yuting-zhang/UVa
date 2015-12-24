#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

using namespace std;

int row[8];

bool placeable(int r, int c){
	for (int prev = 0; prev < c; prev++){
		if (row[prev] == r)
			return false;
		if (abs(r - row[prev]) == abs(c - prev))
			return false;
	}
	return true;
}

void backtrack(int col){
	if (col == 8){
		for (int i = 0; i < 8; i++)
			cout << row[i] << " ";
		cout << "\n";
	}

	for (int i = 0; i < 8; i++)
		if (placeable(i, col)){
			row[col] = i;
			backtrack(col + 1);
		}
}

int main(){
	memset(row, 0, sizeof row);
	backtrack(0);
}
