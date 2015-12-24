#include <iostream>
#include <cstdio>
#include <vector>
#include <functional>
#include <queue>
#include <string>
#include <map>
#include <utility>
#include <algorithm>
#include <climits>

using namespace std;

typedef pair<int, int> ii;
int main(){
	int n, r, scenario = 0;
	while (scanf("%d %d", &n, &r) && n && r){
		scenario++;
		printf("Scenario #%d\n", scenario);
		map<string, int> nameMap;
		int count = 0;
		vector<vector<ii>> adjList(n);
		for (int i = 0; i < r; i++){
			string name1, name2;
			int cap;
			cin >> name1 >> name2 >> cap;
			if (nameMap.find(name1) == nameMap.end())
				nameMap[name1] = count++;
			if (nameMap.find(name2) == nameMap.end())
				nameMap[name2] = count++;
			adjList[nameMap[name1]].push_back({nameMap[name2], cap});
			adjList[nameMap[name2]].push_back({nameMap[name1], cap});
		}
		string startName, endName;
		cin >> startName >> endName;
		if (nameMap.find(startName) == nameMap.end() ||
			nameMap.find(endName) == nameMap.end()){
			printf("0 tons\n\n");
			continue;
		}
		int start = nameMap[startName], end = nameMap[endName];
		vector<int> load(n, 0);
		load[start] = INT_MAX;
		priority_queue<ii, vector<ii>, greater<ii>> pq;
		pq.push({INT_MAX, start});

		while (!pq.empty()){
			ii front = pq.top();
			pq.pop();
			int cap = front.first, u =front.second;
			if (cap < load[u]) continue;
			for (int j = 0; j < (int)adjList[u].size(); j++){
				ii v = adjList[u][j];
				if (min(load[u], v.second) > load[v.first]){
					load[v.first] = min(load[u], v.second);
					pq.push({load[v.first], v.first});
				}
			}
		}

		printf("%d tons\n\n", load[end]);
	}
}
