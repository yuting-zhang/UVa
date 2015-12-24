#include <iostream>
#include <cstdio>
#include <stack>
#include <queue>

using namespace std;

int main(){
	int n;
	while (scanf("%d", &n) > 0){
		int cmd, value;
		bool q = true, pq = true, s = true;
		stack<int> istack;
		queue<int> iqueue;
		priority_queue<int> ip_queue;
		while (n--){
			scanf("%d %d", &cmd, &value);
			if (cmd == 1){
				istack.push(value);
				iqueue.push(value);
				ip_queue.push(value);
			}
			else{
				if (istack.empty()){
					s = false;
					q = false;
					pq = false;
					continue;
				}

				int val = istack.top();
				istack.pop();
				if (val != value)
					s = false;

				val = iqueue.front();
				iqueue.pop();
				if (val != value)
					q = false;

				val = ip_queue.top();
				ip_queue.pop();
				if (val != value)
					pq = false;
			}
		}
		if (s && !q && !pq)
			printf("stack\n");
		else if (q && !s && !pq)
			printf("queue\n");
		else if (pq && !s && !q)
			printf("priority queue\n");
		else if (!s && !q && !pq)
			printf("impossible\n");
		else
			printf("not sure\n");
	}
	return 0;
}
