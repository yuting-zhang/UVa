#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<int, int> ii;

int n, m;

vector<vector<int>> residue;
vector<vector<int>> adjList;
vector<int> interval;
vector<pair<int, ii>> monkeys;
vector<ii> theEnds;

int goal;
int max_flow, flow, s, t, V;
vector<int> parent;
int counter;

void buildGraph(){
    sort(interval.begin(), interval.end());
    auto it = unique(interval.begin(), interval.end());
    interval.erase(it, interval.end());

    vector<int> image(interval.size());
    theEnds.clear();
    counter = 0;
    for (int i = 0; i < interval.size(); i++){
        if (i != 0){
            if (interval[i] - 1 > interval[i - 1]){
                theEnds.push_back({interval[i - 1] + 1, interval[i] - 1});
                counter++;
            }
        }
        theEnds.push_back({interval[i], interval[i]});
        image[i] = counter++;
    }

    residue.assign(2 + n + counter, vector<int>(2 + n + counter, 0));
    adjList.assign(2 + n + counter, vector<int>());

    for (int i = 0; i < monkeys.size(); i++){
        adjList[0].push_back(i + 1);
        adjList[i + 1].push_back(0);
        residue[0][i + 1] = monkeys[i].first;
        int lower = image[lower_bound(interval.begin(), interval.end(), monkeys[i].second.first) - interval.begin()],
            upper = image[lower_bound(interval.begin(), interval.end(), monkeys[i].second.second) - interval.begin()];
        
        for (int j = lower; j <= upper; j++){
            adjList[i + 1].push_back(j + n + 1);
            adjList[j + n + 1].push_back(i + 1);
            residue[i + 1][j + n + 1] = theEnds[j].second - theEnds[j].first + 1;
        }
    }

    for (int i = 0; i < interval.size(); i++){
        if (i != 0 && interval[i] - 1 > interval[i - 1]){
            adjList[n + 1 + image[i - 1] + 1].push_back(1 + n + counter);
            adjList[1 + n + counter].push_back(n + 1 + image[i - 1] + 1);
            residue[n + 1 + image[i - 1] + 1][1 + n + counter] = (interval[i] - interval[i - 1] - 1) * m;
        }
        adjList[n + 1 + image[i]].push_back(1 + n + counter);
        adjList[1 + n + counter].push_back(n + 1 + image[i]);
        residue[n + 1 + image[i]][1 + n + counter] = m;
    }
    s = 0, t = 1 + n + counter, V = 2 + n + counter;
}

void augment(int v, int min_edge){
    if (v == s){
        flow = min_edge;
        return;
    }
    else if (parent[v] != -1){
        int u = parent[v];
        augment(u, min(min_edge, residue[u][v]));
        residue[u][v] -= flow;
        residue[v][u] += flow;
    }
}

void Dinic(){
    max_flow = 0;
    while (true){
        parent.assign(V, -1);
        vector<bool> visited(V, false);
        queue<int> q;
        q.push(s);
        visited[s] = true;
        while (!q.empty()){
            int u = q.front();
            q.pop();
            if (u == t)
                break;
            for (int v : adjList[u])
                if (!visited[v] && residue[u][v] > 0){
                    parent[v] = u;
                    visited[v] = true;
                    q.push(v);
                }
        }

        int new_flow = 0;
        for (int u : adjList[t]){
            flow = 0;
            augment(u, residue[u][t]);
            residue[u][t] -= flow;
            residue[t][u] += flow;
            new_flow += flow;
        }
        if (new_flow == 0)
            break;
        max_flow += new_flow; 
    }
}

int main(){
    int test_case = 0;
    while (scanf("%d", &n) && n){
        test_case++;
        scanf("%d", &m);
        monkeys.assign(n, pair<int, ii>());
        goal = 0;
        interval.clear();
        for (int i = 0; i < n; i++){
            scanf("%d %d %d", &monkeys[i].first, &monkeys[i].second.first, &monkeys[i].second.second); 
            monkeys[i].second.second--;
            interval.push_back(monkeys[i].second.first);
            interval.push_back(monkeys[i].second.second);
            goal += monkeys[i].first;
        }
        buildGraph();
        Dinic();
        printf("Case %d: ", test_case);
        if (max_flow == goal){
            printf("Yes\n");
            vector<int> remain(interval.back() + 1, m);

            for (int i = 0; i < n; i++){
                vector<bool> drink(interval.back() + 1, false);
                vector<ii> answer;
                int to_drink;
                for (int j = 0; j < counter; j++)
                    if (residue[1 + n + j][1 + i] > 0){
                        to_drink = residue[1 + n + j][1 + i];
                        int lower = theEnds[j].first, upper = theEnds[j].second;
                        for (int k = lower; to_drink > 0 && k <= upper; k++)
                            if (remain[k] > 0){
                                remain[k]--;
                                drink[k] = true;
                                to_drink--;
                            }
                                
                    }
                int lower = -1, upper = -1;
                for (int j = 0; j < drink.size(); j++)
                    if (drink[j]){
                        if (lower == -1)
                            lower = upper = j;
                        else
                            upper = j;
                    }
                    else{
                        if (lower != -1)
                            answer.push_back({lower, upper + 1});
                        lower = upper = -1;
                    }
                if (lower != -1)
                    answer.push_back({lower, upper + 1});
                printf("%lu", answer.size());
                for (auto it: answer)
                    printf(" (%d,%d)", it.first, it.second);
                printf("\n");
            }
        }
        else
            printf("No\n");
    }
}
