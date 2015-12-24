#include <iostream>
#include <algorithm>

using namespace std;

int game_test(int a1, int a2, int a3, int b1, int b2){
    if (a1 > b1 && a2 > b2)
        return 999;

    int card;
    if (a1 < b1 && a2 < b2)
        card = 1;
    else
        card = a3 + 1;

    while (card == a1 || card == a2 || card == a3 || card == b1 || card == b2)
            ++card;

    if (card > 52)
        return 999;
    else
        return card;
}

int main(){
    int A, B, C, X, Y;
    while (scanf("%d %d %d %d %d", &A, &B, &C, &X, &Y) && A){
        int card = 0;
        card = max(card, game_test(A, B, C, X, Y));
        card = max(card, game_test(A, C, B, X, Y));
        card = max(card, game_test(B, A, C, X, Y));
        card = max(card, game_test(B, C, A, X, Y));
        card = max(card, game_test(C, A, B, X, Y));
        card = max(card, game_test(C, B, A, X, Y));
        if (card == 999)
            printf("-1\n");
        else
            printf("%d\n", card);
    }
    return 0;
}
