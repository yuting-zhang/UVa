#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main(){
	int N;
	while (scanf("%d", &N) == 1){
		vector<int> books(N);
		for (int i = 0; i < N; i++)
			scanf("%d", &books[i]);
		sort(books.begin(), books.end());
		int M;
		scanf("%d", &M);
		int book1 = -1000001, book2 = 1000001;
		for (int i = 0; i < N - 1; i++){
			int price = M - books[i];
			auto it = lower_bound(books.begin() + i + 1, books.end(), price);
			if (*it == price && abs(price - books[i]) < abs(book1 - book2)){
				book1 = books[i];
				book2 = *it;
			}
		}
		printf("Peter should buy books whose prices are %d and %d.\n\n", book1, book2);
	}
}
