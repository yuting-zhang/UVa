#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <bitset>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> adjList;
vector<vector<int>> residue;

int s, t;
int intended;
vector<int> parent;
int flow, max_flow;

void augment(int node, int min_edge){
    if (node == s){
        flow = min_edge;
        return;
    }
    else if (parent[node] != -1){
        augment(parent[node], min(min_edge, residue[parent[node]][node]));
        residue[parent[node]][node] -= flow;
        residue[node][parent[node]] += flow;
    }
}

int main(){
    string line;
    while (cin){
        adjList.assign(38, vector<int>());
        residue.assign(38, vector<int>(38, 0));

        s = 0, t = 37;
        intended = 0;

        for (int i = 0; i < 26; i++){
            adjList[0].push_back(1 + i);
            adjList[1 + i].push_back(0);
        }

        for (int i = 0; i < 10; i++){
            adjList[i + 27].push_back(t);
            residue[i + 27][t] = 1;
            adjList[t].push_back(i + 27);
        }

        while (getline(cin, line) && !line.empty()){
            char app = line[0];
            int num = line[1] - '0';
            residue[s][app - 'A' + 1] = num;

            intended += num;

            int index = 3;
            while (line[index] != ';'){
                adjList[app - 'A' + 1].push_back(27 + line[index] - '0');
                adjList[27 + line[index] - '0'].push_back(app - 'A' + 1);
                residue[app - 'A' + 1][27 + line[index] - '0'] = 1000;
                index++;
            }
        }

        max_flow = 0;
        while (true){
            parent.assign(38, -1);
            bitset<38> bset;
            bset[s] = true;
            queue<int> q;
            q.push(s);
            while (!q.empty()){
                int u = q.front();
                q.pop();
                if (u == t)
                    break;
                for (int v: adjList[u]){
                    if (!bset[v] && residue[u][v] > 0){
                        q.push(v);
                        parent[v] = u;
                        bset[v] = true;
                    }
                }
            }
            int new_flow = 0;
            for (int u: adjList[t]){
                if (residue[u][t] <= 0)
                    continue;
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
        if (max_flow != intended)
            printf("!\n");
        else{
            for (int i = 0; i < 10; i++){
                bool allocated = false;
                for (int j = 0; j < 26; j++)
                    if (residue[i + 27][j + 1] == 1){
                        printf("%c", (char)(j + 'A'));
                        allocated = true;
                        break;
                    }
                if (!allocated)
                    printf("_");
                        
            }
            printf("\n");
        }
    }
}
