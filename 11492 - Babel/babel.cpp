#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <utility>
#include <map>
#include <queue>
#include <functional>

using namespace std;

typedef pair<int, int> ii;

int main(){
    int M;
    while (scanf("%d", &M) && M){
        string O, D;
        cin >> O >> D;
        map<string, int> langIndex;
        int langCount = 0, start, end;
        start = langIndex[O] = langCount++;
        end = langIndex[D] = langCount++;

        vector<vector<vector<pair<ii, int>>>> adjList;
        adjList.push_back(vector<vector<pair<ii, int>>>(26, vector<pair<ii, int>>()));
        adjList.push_back(vector<vector<pair<ii, int>>>(26, vector<pair<ii, int>>()));

        for (int i = 0; i < M; i++){
            string lang1, lang2, word;
            cin >> lang1 >> lang2 >> word;
            if (langIndex.find(lang1) == langIndex.end()){
                langIndex[lang1] = langCount++;
                adjList.push_back(vector<vector<pair<ii, int>>>(26, vector<pair<ii, int>>()));
            }
            if (langIndex.find(lang2) == langIndex.end()){
                langIndex[lang2] = langCount++;
                adjList.push_back(vector<vector<pair<ii, int>>>(26, vector<pair<ii, int>>()));
            }
            int index1 = langIndex[lang1], index2 = langIndex[lang2];
            for (int i = 0; i < 26; i++)
                if (i != word[0] - 'a'){
                    adjList[index1][i].push_back({{index2, word[0] - 'a'}, word.size()});
                    adjList[index2][i].push_back({{index1, word[0] - 'a'}, word.size()});
                }
        }

        priority_queue<pair<int, ii>, vector<pair<int, ii>>, greater<pair<int, ii>>> pq;
        vector<vector<int>> dist(langCount, vector<int>(26, (1 << 30)));

        for (int i = 0; i < 26; i++){
            dist[start][i] = 0;
            pq.push({0, {start, i}});
        }

        while (!pq.empty()){
            auto front = pq.top();
            pq.pop();
            int length = front.first, lang = front.second.first, initial = front.second.second;
            for (auto it: adjList[lang][initial]){
                int dest = it.first.first, destInitial = it.first.second, wordLength = it.second;
                if (it.second + length < dist[dest][destInitial]){
                    dist[dest][destInitial] = it.second + length;
                    pq.push({dist[dest][destInitial], {dest, destInitial}});
                }
            }
        }

        int answer = (1 << 30);
        for (int i = 0; i < 26; i++)
            if (dist[end][i] < answer)
                answer = dist[end][i];
        if (answer == (1 << 30))
            printf("impossivel\n");
        else
            printf("%d\n", answer);
    }
    return 0;
}
