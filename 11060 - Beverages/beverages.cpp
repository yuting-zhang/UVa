#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;

int N, M;
map<string, int> drinks;
vector<vector<int>> adjList;
vector<string> names;
vector<bool> visited;
vector<int> answer;
vector<int> id;

int main(){
    int test_case = 0;
    while (scanf("%d\n", &N) == 1){
        test_case++;

        int count = 0;
        drinks.clear();

        names.assign(N, "");
        for (int i = 0; i < N; i++){
            string word;
            cin >> word;
            drinks[word] = count++;
            names[i] = word;
        }

        scanf("%d\n", &M);
        adjList.assign(N, vector<int>());
        id.assign(N, 0);
        for (int i = 0; i < M; i++){
            string word1, word2;
            cin >> word1 >> word2;
            adjList[drinks[word1]].push_back(drinks[word2]);
            id[drinks[word2]]++;
        }
        
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < N; i++)
            if (id[i] == 0)
                pq.push(i);
        
        cout << "Case #" << test_case << ": Dilbert should drink beverages in this order:";
        while (!pq.empty()){
            int u = pq.top();
            pq.pop();
            cout << " " << names[u];
            for (int dest: adjList[u]){
                id[dest]--;
                if (id[dest] == 0)
                    pq.push(dest);
            }
        }
        cout << ".\n\n";    
    }
}
