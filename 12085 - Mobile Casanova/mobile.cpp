#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

long long pow(int base, int power){
	long long ret = 1;
	for (int i = 0; i < power; i++)
		ret *= base;
	return ret;
}

long long toll(string line){
	long long ret = 0;
	for (int i = line.size() - 1; i >= 0; i--){
		ret += ((line[i] - '0') * pow(10, line.size() - i - 1));
	}
	return ret;
}

string to_s(long long num){
	string ret = "";
	while (num > 0){
		ret = (char)((num % 10) + '0') + ret;
		num /= 10;
	}
	return ret;
}

void print_num(long long b, long long e, int size){
	if (b == e){
		printf("0%lld\n", b);
		return;
	}
	string begin = to_s(b),
		   end = to_s(e);
	int index = 0;
	while (begin[index] == end[index])
		index++;
	printf("0");
	for (int i = 0; i < index; i++)
		printf("%c", begin[i]);
	for (int i = index; i < begin.size(); i++)
		printf("%c", begin[i]);
	printf("-");
	for (int i = index; i < end.size(); i++)
		printf("%c", end[i]);
	printf("\n");
}

int main(){
	int N, case_no = 0;
	while (scanf("%d\n", &N) && N){
		case_no++;
		printf("Case %d:\n", case_no);
		string line;
		long long begin = 0, end = 0;
		for (int i = 0; i < N; i++){
			getline(cin, line);
			long long number = toll(line);
			if (begin == 0)
				begin = end = number;
			else if (number != end + 1){
				print_num(begin, end, line.size() - 1);
				begin = end = number;
			}
			else 
				end = number;

			if (i == N - 1)
				print_num(begin, end, line.size() - 1);
		}
		printf("\n");
	}
	return 0;
}
