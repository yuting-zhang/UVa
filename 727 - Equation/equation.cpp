#include <iostream>
#include <stack>
#include <cstdio>

using namespace std;

int priority(char ch){
	if (ch == '+' || ch == '-')
		return 1;
	else if (ch == '*' || ch == '/')
		return 2;
	else if (ch == '(')
		return 0;
	else
		return -1;
}

int main(){
	int T;
	scanf("%d\n\n", &T);

	for (int case_no = 0; case_no < T; case_no++){
		if (case_no != 0)
			printf("\n");
		stack<char> stk;

		string line;
		while (getline(cin, line) && !line.empty()){
			char ch = line.front();			
			if (ch >= '0' && ch <= '9')
				printf("%c", ch);
			else if (ch == '(')
				stk.push(ch);
			else if (ch == ')'){
				while (stk.top() != '('){
					printf("%c", stk.top());
					stk.pop();
				}
				stk.pop();
			}
			else{
				while (!stk.empty() && priority(stk.top()) >= priority(ch)){
					printf("%c", stk.top());
					stk.pop();
				}	
				stk.push(ch);
			}
		}
		while (!stk.empty()){
			printf("%c", stk.top());
			stk.pop();
		}
		printf("\n");
	}
	return 0;
}
