#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

int P, R;
vector<vector<int>> adjMat;

int main(){
    int network = 0;
    while (scanf("%d %d", &P, &R) && P){
        network++;
        adjMat.assign(P, vector<int>(P, (1 << 29)));
        int nameCount = 0;
        map<string, int> nameMap;
        for (int i = 0; i < P; i++)
            adjMat[i][i] = 0;
        for (int i = 0; i < R; i++){
            string name1, name2;
            cin >> name1 >> name2;
            if (nameMap.find(name1) == nameMap.end())
                nameMap[name1] = nameCount++;
            if (nameMap.find(name2) == nameMap.end())
                nameMap[name2] = nameCount++;
            int index1 = nameMap[name1], index2 = nameMap[name2];
            
            adjMat[index1][index2] = adjMat[index2][index1] = 1;
        }

        for (int k = 0; k < P; k++)
            for (int i = 0; i < P; i++)
                for (int j = 0; j < P; j++)
                    adjMat[i][j] = min(adjMat[i][j], adjMat[i][k] + adjMat[k][j]);

        bool connected = true;
        int diameter = 0;
        for (int i = 0; i < P; i++)
            for (int j = 0; j < P; j++)
                if (adjMat[i][j] == (1 << 29))
                    connected = false;
                else
                    diameter = max(diameter, adjMat[i][j]);
                    
        printf("Network %d: ", network);
        if (connected)
            printf("%d\n\n", diameter);
        else
            printf("DISCONNECTED\n\n");
    }
}
