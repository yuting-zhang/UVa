#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <string>
#include <sstream>
#include <functional>
#include <map>

using namespace std;

typedef pair<int, int> ii;

int n, k;
vector<int> travelTime;
vector<vector<int>> floorStops;
vector<vector<vector<pair<ii, int>>>> adjList;

int main(){
    while (scanf("%d %d", &n, &k) == 2){
        travelTime.assign(n + 1, 0);
        for (int i = 1; i <= n; i++)
            scanf("%d", &travelTime[i]);
        string line;
        getline(cin, line);
        floorStops.assign(105, vector<int>());
        floorStops[0].push_back(0);
        adjList.assign(105, vector<vector<pair<ii, int>>>(n + 1, vector<pair<ii, int>>()));

        for (int i = 1; i <= n; i++){
            getline(cin, line);
            istringstream sin(line);
            vector<int> floors;
            int num;
            while (sin >> num){
                floors.push_back(num);
                floorStops[num].push_back(i);
            }

            for (int j = 0; j < floors.size(); j++)
                for (int k = j + 1; k < floors.size(); k++){
                    int weight = (floors[k] - floors[j]) * travelTime[i];
                    adjList[floors[j]][i].push_back({{floors[k], i}, weight});
                    adjList[floors[k]][i].push_back({{floors[j], i}, weight});
                }
           
        }

        for (int i = 0; i <= 100; i++)
            for (int j = 0; j < floorStops[i].size(); j++)
                for (int k = j + 1; k < floorStops[i].size(); k++){
                    int time = 60;
                    if (i == 0 && j == 0)
                        time = 0;
                    adjList[i][floorStops[i][j]].push_back({{i, floorStops[i][k]}, time});
                    adjList[i][floorStops[i][k]].push_back({{i, floorStops[i][j]}, time});
                }
        

        vector<vector<int>> dist(105, vector<int>(n + 1, (1 << 30)));
        dist[0][0] = 0;
        priority_queue<pair<int, ii>, vector<pair<int, ii>>, greater<pair<int, ii>>> pq;
        bool found = false;
        pq.push({0, {0, 0}});
        while (!pq.empty()){
            auto front = pq.top();
            pq.pop();
            int time = front.first, u = front.second.first, elevator = front.second.second;
            if (time > dist[u][elevator])
                continue;
            for (auto it : adjList[u][elevator]){
                int v = it.first.first, w = it.second, lift = it.first.second;
                int new_time = time + w;
                if (new_time < dist[v][lift]){
                    dist[v][lift] = new_time;
                    if (v == k)
                        found = true;
                    pq.push({dist[v][lift], {v, lift}});
                }
            }
        }
        int answer = (1 << 30);
        for (int i = 1; i <= n; i++){
            int local = dist[k][i];
            if (local < answer) 
                answer = local;
        }

        if (found)
            printf("%d\n", answer);
        else
            printf("IMPOSSIBLE\n");
    }
    return 0;
}
