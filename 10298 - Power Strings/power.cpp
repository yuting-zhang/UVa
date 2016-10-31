#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

int main(){
    char line[1000001];
    while (scanf(" %s ", line) == 1 && strcmp(line, ".")){
        int length = strlen(line);
        vector<int> pi(length + 1, 0);
        for (int i = 2; i <= length; i++){
            int k = pi[i - 1];
            while (k > 0 && line[k] != line[i - 1])
                k = pi[k];
            if (line[k] == line[i - 1])
                pi[i] = k + 1;
            else
                pi[i] = 0;
        }

        int period = 0;
        for (int i = 1; i <= length; i++)
            if (i - pi[i] > period)
                period = i - pi[i];

        if (length % period != 0)
            period = length;
        printf("%d\n", length / period);
    }
}
