#include <iostream>
#include <cstring>

int main(){
    while (true){
        char suit, rank;
        int cards[4][14];
        memset(cards, 0, sizeof(cards));
        for (int i = 0; i < 13; ++i){
            if (scanf("%c%c ", &rank, &suit) == 2){
                int suit_index, rank_index;
                if (suit == 'S')
                    suit_index = 0;
                else if (suit == 'H')
                    suit_index = 1;
                else if (suit == 'D')
                    suit_index = 2;
                else
                    suit_index = 3;
                if (rank == 'A')
                    rank_index = 1;
                else if (rank == 'T')
                    rank_index = 10;
                else if (rank == 'J')
                    rank_index = 11;
                else if (rank == 'Q')
                    rank_index = 12;
                else if (rank == 'K')
                    rank_index = 13;
                else
                    rank_index = rank - '0' + 1;
                cards[suit_index][rank_index]++;
                cards[suit_index][0]++;
            }
            else
                return 0;
        }

        int points = 0, no_trump_points = 0;
        for (int i = 0; i < 4; ++i){
            points += cards[i][1] * 4;
            points += cards[i][13] * 3;
            points += cards[i][12] * 2;
            points += cards[i][11];
            if (cards[i][13] == 1 && cards[i][0] == 1)
                points--;
            if (cards[i][12] >= 1 && cards[i][0] <= 2)
                points -= cards[i][12];
            if (cards[i][11] >= 1 && cards[i][0] <= 3)
                points -= cards[i][11];
        }

        no_trump_points = points;
        for (int i = 0; i < 4; ++i){
            if (cards[i][0] == 2)
                ++points;
            if (cards[i][0] <= 1)
                points += 2;
        }

        bool stopped[4];
        memset(stopped, false, sizeof(stopped));
        for (int i = 0; i < 4; ++i){
            if (cards[i][1] >= 1 || cards[i][13] >= 1 && cards[i][0] >= 2||
                cards[i][12] >= 1 && cards[i][0] >= 3)
                stopped[i] = true;
        }

        if (points < 14)
            printf("PASS\n");
        else if (no_trump_points >= 16 && stopped[0] && stopped[1] && stopped[2] && stopped[3])
            printf("BID NO-TRUMP\n");
        else {
            int bid = 0;
            for (int i = 1; i < 4; ++i)
                if (cards[i][0] > cards[bid][0])
                    bid = i;
            char bid_suit;
            if (bid == 0)
                bid_suit = 'S';
            else if (bid == 1)
                bid_suit = 'H';
            else if (bid == 2)
                bid_suit = 'D';
            else
                bid_suit = 'C';
            printf("BID %c\n", bid_suit);
        }
    }
    return 0;
}
