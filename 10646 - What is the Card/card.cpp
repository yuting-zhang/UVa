#include <iostream>
#include <cstring>

using namespace std;

struct card_t{
    char suit;
    char rank;
    int value() const{
        if (rank >= '2' && rank <= '9')
            return rank - '0';
        else
            return 10;
    }
};

int main(){
    int case_no, N;
    scanf("%d", &N);
    for (int case_no = 1; case_no <= N; ++case_no){
        card_t cards[52], cards_in_hand[25];
        int top = 26;
        for (int i = 0; i < 27; ++i)
            scanf(" %c%c", &cards[i].rank, &cards[i].suit);
        for (int i = 0; i < 25; ++i)
            scanf(" %c%c", &cards_in_hand[i].rank, &cards_in_hand[i].suit);

        int Y = 0;
        for (int i = 0; i < 3; ++i){
            int X = cards[top].value();
            Y += X;
            top -= 1 + (10 - X);
        }

        for (int i = 0; i < 25; ++i)
            cards[++top] = cards_in_hand[i];

        printf("Case %d: %c%c\n", case_no, cards[Y - 1].rank, cards[Y - 1].suit);
    }
    return 0;
}
