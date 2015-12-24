#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int gcd(int a, int b){
	return b == 0 ? a : gcd(b, a % b);
}

int get_length(int a){
	int cnt = 0;
	while (a > 0){
		a /= 10;
		cnt++;
	}
	return cnt;
}

int main(){
	int n, case_no = 0;
	while (scanf("%d", &n) && n){
		case_no++;
		printf("Case %d:\n", case_no); 
		int sum = 0;
		for (int i = 0; i < n; i++){
			int temp;
			scanf("%d", &temp);
			sum += temp;
		}

		bool negative = false;
		if (sum < 0){
			negative = true;
			sum = abs(sum);
		}
		
		int whole = sum / n;
		sum %= n;

		if (sum != 0){
			int temp = gcd(sum, n);
			sum /= temp;
			n /= temp;
		}

		if (sum == 0){
			if (negative)
				printf("- %d\n", whole);
			else
				printf("%d\n", whole);
		}
		else{
			int length_1 = get_length(sum),
				length_2 = (whole == 0 ? 0 : get_length(whole)),
				length_3 = get_length(n),
				length;
			if (negative)
				length_2 += 2;
			length_2 += max(length_1, length_3);
			length = length_2;
			printf("%*d\n", length, sum);
			if (negative)
				printf("- ");
			if (whole != 0)
				printf("%d", whole);
			for (int i = 0; i < length_3; i++)
				printf("-");
			printf("\n");
			printf("%*d\n", length, n);
		}
	}
	return 0;
}
