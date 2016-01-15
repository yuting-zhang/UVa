#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <vector>
#include <utility>

using namespace std;

int main(){
    int NC;
    int test_case = 0;
    while (scanf("%d", &NC) && NC){
        test_case++;
        map<string, int> events;
        vector<string> eventNames;
        int event_count = 0;
        vector<vector<int>> CompEvents(NC);
        for (int i = 0; i < NC; i++){
            int NE;
            scanf("%d", &NE);
            for (int j = 0; j < NE; j++){
                string name;
                cin >> name;
                events[name] = event_count;
                CompEvents[i].push_back(event_count++);
                eventNames.push_back(name);
            }
        }

        vector<vector<int>> adjMat(event_count, vector<int>(event_count, 0));
        for (int i = 0; i < NC; i++)
            for (int j = 0; j < CompEvents[i].size() - 1; j++)
                adjMat[CompEvents[i][j]][CompEvents[i][j + 1]] = 1;

        int NM;
        scanf("%d", &NM);
        for (int i = 0; i < NM; i++){
            string e1, e2;
            cin >> e1 >> e2;
            adjMat[events[e1]][events[e2]] = 1;
        }

        for (int k = 0; k < event_count; k++)
            for (int i = 0; i < event_count; i++)
                for (int j = 0; j < event_count; j++)
                    adjMat[i][j] |= (adjMat[i][k] & adjMat[k][j]);

        vector<pair<int, int>> answer;
        int answer_count = 0;
        for (int i = 0; i < event_count; i++)
            for (int j = i + 1; j < event_count; j++)
                if (!adjMat[i][j] && !adjMat[j][i]){
                    answer_count++;
                    if (answer.size() < 2)
                        answer.push_back({i, j});
                }
        if (answer_count > 0){
            printf("Case %d, %d concurrent events:\n", test_case, answer_count);
            printf("(%s,%s) ", eventNames[answer[0].first].c_str(), eventNames[answer[0].second].c_str());
            if (answer_count > 1){
                printf("(%s,%s) ", eventNames[answer[1].first].c_str(), eventNames[answer[1].second].c_str());
            }
            printf("\n");
        }
        else
            printf("Case %d, no concurrent events.\n", test_case);
    }
    return 0;
}

