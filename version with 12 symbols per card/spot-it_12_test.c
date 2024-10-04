#include <stdio.h>

#define P 11    // Prime number for grid
#define S 12    // Symbols per card. Here we have 12 symbols per card instead of the original 8 on Spot-It.
#define C 133   // Total cards

void verify(int cards[C][S]) {
    printf("\nVerification (1=match, 0=wrong, -=same):\n");
    
    for (int i = 0; i < C; i++) {
        printf("%3d:", i + 1);
        for (int j = 0; j < C; j++) {
            if (i == j) { printf("-"); continue; }
            int shared = 0;
            for (int x = 0; x < S && !shared; x++)
                for (int y = 0; y < S; y++)
                    if (cards[i][x] == cards[j][y]) shared++;
            printf("%d", shared == 1); }
        printf("\n"); }
}

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
        printf("Card %3d:", i + 1);
        for (int j = 0; j < S; j++) printf(" %3d", cards[i][j]); 
        printf("\n"); }

    verify(cards);
}
