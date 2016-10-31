#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAXLEN 20010

int n;
int RA[MAXLEN], SA[MAXLEN], tempRA[MAXLEN], tempSA[MAXLEN], counting[MAXLEN];
char st[MAXLEN];

void countingSort(int k){
    int maxRange = max(260, n);
    memset(counting, 0, sizeof(counting));
    for (int i = 0; i < n; i++)
        counting[i + k < n ? RA[i + k] : 0]++;
    int sum = 0;

    for (int i = 0; i < maxRange; i++){
        int temp = counting[i];
        counting[i] = sum;
        sum += temp;
    }
        
    for (int i = 0; i < n; i++)
        tempSA[counting[SA[i] + k < n ? RA[SA[i] + k] : 0]++] = SA[i];
    for (int i = 0; i < n; i++)
        SA[i] = tempSA[i];
}
void constructSA(){
    for (int i = 0; i < n; i++){
        RA[i] = st[i];
        SA[i] = i;
    }
    for (int k = 1; k < n; k <<= 1){
        countingSort(k);
        countingSort(0);
        int rank = 0;
        tempRA[SA[0]] = rank = 0;
        for (int i = 1; i < n; i++)
            tempRA[SA[i]] = (RA[SA[i]] == RA[SA[i - 1]] && RA[SA[i] + k] == RA[SA[i - 1] + k]) ? rank : ++rank;
        for (int i = 0; i < n; i++)
            RA[i] = tempRA[i];
        if (RA[SA[n - 1]] == n - 1)
            break;
    }
}

int Phi[MAXLEN], PLCP[MAXLEN], LCP[MAXLEN];

void computeLCP(){
    Phi[SA[0]] = -1;
    for (int i = 1; i < n; i++)
        Phi[SA[i]] = SA[i - 1];
    int L = 0;
    for (int i = 0; i < n; i++){
        if (Phi[i] == -1){
            PLCP[i] = 0;
            continue;
        }
        while (st[i + L] == st[Phi[i] + L])
            L++;
        PLCP[i] = L;
        L = max(L - 1, 0);
    }
    for (int i = 0; i < n; i++)
        LCP[i] = PLCP[SA[i]];
}

int main(){
    int T;
    scanf("%d", &T);
    while (T--){
        scanf(" %s", st);
        n = strlen(st);
        for (int i = 0; i < n - 1; i++)
            st[i + n] = st[i];
        n = n * 2 - 1;
        st[n++] = '$';
        st[n] = 0;
        constructSA();
        computeLCP();
        for (int i = 0; i < n; i++)
            if (SA[i] < (n >> 1)){
                if (i + 1 < n && SA[i + 1] < (n >> 1) && LCP[i + 1] == n - 1 - SA[i])
                    continue;
                printf("%d\n", SA[i] + 1);
                break;
            }
    }
}
