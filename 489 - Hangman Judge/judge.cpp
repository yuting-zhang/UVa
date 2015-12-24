#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main(){
    int round;
    while (scanf("%d\n", &round) && round != -1){
        string line;
        getline(cin, line);
        /*
        0: not guessed, also not present in answer
        1: not guessed, present in answer
        2: guessed, present in answer
        3: guessed, not present in answer
        */
        int status[26], characters = 0;
        memset(status, 0, sizeof(status));
        for (int i = 0; i < line.size(); ++i)
            if (status[line[i] - 'a'] == 0){
                status[line[i] - 'a'] = 1;
                characters++;
            }

        int hang = 0;
        getline(cin, line);
        for (int i = 0; i < line.size(); ++i){
            if (status[line[i] - 'a'] == 0){
                hang++;
                status[line[i] - 'a'] = 3;
                if (hang == 7)
                    break;
            }
            else if (status[line[i] - 'a'] == 1){
                status[line[i] - 'a'] = 2;
                characters--;
                if (characters == 0)
                    break;
            }
        }
        printf("Round %d\n", round);
        if (hang == 7)
            printf("You lose.\n");
        else if (characters == 0)
            printf("You win.\n");
        else
            printf("You chickened out.\n");
    }
    return 0;
}
