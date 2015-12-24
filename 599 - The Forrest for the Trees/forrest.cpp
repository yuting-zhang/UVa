#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <sstream>

using namespace std;

int visit(int node, bool (*graph)[26], bool* visited){
	int ret = 1;
	visited[node] = true;
	for (int i = 0; i < 26; i++)
		if (graph[node][i] && !visited[i])
			ret += visit(i, graph, visited);
	return ret;
}	

int main(){
	int test_case;
	scanf("%d\n", &test_case);
	while (test_case--){
		bool graph[26][26];
		memset(graph, false, sizeof(graph));
		string line;
		while (getline(cin, line) && line[0] != '*'){
			char x, y, ch;
			istringstream sin(line);
			sin >> ch >> x >> ch >> y >> ch;
			graph[x - 'A'][y - 'A'] = true;
			graph[y - 'A'][x - 'A'] = true;
		}
		getline(cin, line);
		bool points[26];
		memset(points, false, sizeof(points));
		for (int i = 0; i < line.size(); i++)
			if (line[i] >= 'A' && line[i] <= 'Z')
				points[line[i] - 'A'] = true;

		bool visited[26];
		memset(visited, false, sizeof(visited));
		int tree = 0, acorn = 0;
		for (int i = 0; i < 26; i++)
			if (points[i] && !visited[i]){
				if (visit(i, graph, visited) == 1)
					acorn++;
				else
					tree++;
			}	
		printf("There are %d tree(s) and %d acorn(s).\n", tree, acorn);
	}
	return 0;
}
