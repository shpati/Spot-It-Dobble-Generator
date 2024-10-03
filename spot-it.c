#include <stdio.h>

#define P 7  // Prime number for grid
#define S 8  // Symbols per card
#define C 57 // Total cards

int main() {
    int cards[C][S] = {0};
    
    for (int i = 0; i < S; i++) cards[0][i] = i + 1;    // First card: 1 to 8
    
    for (int i = 0; i < P; i++)                         // Grid cards
        for (int j = 0; j < P; j++) {
            int* card = cards[i * P + j + 1];
            card[0] = i + 2;
            for (int k = 0; k < P; k++)
                card[k + 1] = ((i * k + j) % P) + P * k + P + 2; }

    for (int i = 0; i < P; i++) {                       // Infinity cards
        int* card = cards[P * P + 1 + i];
        card[0] = 1;
        for (int j = 0; j < P; j++)
            card[j + 1] = P + 2 + j + i * P; }

    for (int i = 0; i < C; i++) {                       // Print cards
        printf("Card %2d:", i + 1);
        for (int j = 0; j < S; j++) printf(" %2d", cards[i][j]); 
        printf("\n"); }
}
