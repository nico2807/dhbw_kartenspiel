#include "karten.h"
#include <stdlib.h>




void karten_generieren(struct Karte deck[52]) {
    char *farben[4] = {"♠", "♥", "♦", "♣"};
    char *zahlen[13] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "B", "D", "K", "A"};
    int werte[13] = {2,3,4,5,6,7,8,9,10,11,12,13,14};

    int pos = 0;

    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 4; j++) {
            deck[pos].zahl = zahlen[i];
            deck[pos].farbe = farben[j];
            deck[pos].wert = werte[i];
            pos++;
        }
    }
}

void karten_mischen(struct Karte deck[52]) {

    struct Karte temp;

    for (int i = 0; i < 100; i++) {
        int r = rand() % 52;
        int c = rand() % 52;
        temp = deck[r];
        deck[r] = deck[c];
        deck[c] = temp;
    }
}