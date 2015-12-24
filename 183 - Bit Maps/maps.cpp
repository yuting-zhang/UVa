#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

bool bitmap[210][210];
int row, column;
int count;

void processB(int r, int c, int height, int width){
	if (height == 0 || width == 0)
		return;

	bool initial = bitmap[r][c];
	bool divide = false;
	for (int i = r; !divide && i < r + height; i++)
		for (int j = c; !divide && j < c + width; j++)
			if (bitmap[i][j] != initial)
				divide = true;
	
	if (divide){
		printf("D");
		count++;
		if (count % 50 == 0)
			printf("\n");
		int lower_height = height / 2,
			upper_height = height - lower_height;
		int right_width = width / 2,
			left_width = width - right_width;
		processB(r, c, upper_height, left_width);
		processB(r, c + left_width, upper_height, right_width);
		processB(r + upper_height, c, lower_height, left_width);
		processB(r + upper_height, c + left_width, lower_height, right_width);
	}
	else{
		printf("%c", initial ? '1' : '0');
		count++;
		if (count % 50 == 0)
			printf("\n");
	}
			
}

void processBMap(){
	printf("D%4d%4d\n", row, column);
	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++){
			char ch;
			scanf(" %c ", &ch);
			if (ch == '1')
				bitmap[i][j] = true;
		}
	count = 0;
	processB(0, 0, row, column);	
	if (count % 50 != 0)
		printf("\n");
}

void processD(int r, int c, int height, int width){
	if (height == 0 || width == 0)
		return;
	char ch;
	scanf(" %c ", &ch);
	if (ch == 'D'){
		int lower_height = height / 2,
			upper_height = height - lower_height;
		int right_width = width / 2,
			left_width = width - right_width;
		processD(r, c, upper_height, left_width);
		processD(r, c + left_width, upper_height, right_width);
		processD(r + upper_height, c, lower_height, left_width);
		processD(r + upper_height, c + left_width, lower_height, right_width);
	}
	else
		for (int i = r; i < r + height; i++)
			for (int j = c; j < c + width; j++)
				bitmap[i][j] = (ch == '1');
}

void processDMap(){
	printf("B%4d%4d\n", row, column);
	processD(0, 0, row, column);
	count = 0;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++){
			printf("%c", bitmap[i][j] ? '1' : '0');
			count++;
			if (count % 50 == 0)
				printf("\n");
		}
	if (count % 50 != 0)
		printf("\n");
}
int main(){
	char ch;
	while (scanf(" %c ", &ch) && ch != '#'){
		scanf("%d %d", &row, &column);
		memset(bitmap, false, sizeof bitmap);
		if (ch == 'B')	
			processBMap();
		if (ch == 'D')
			processDMap();
	}
}
