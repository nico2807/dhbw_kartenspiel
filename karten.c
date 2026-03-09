#include "karten.h"
#include <stdlib.h>

//Hier wird die Kartengenerierung und das Mischen vorgenommen.


void karten_generieren(struct Karte deck[52]) {
    char *farben[4] = {"♠", "\x1b[31m♥\x1b[0m", "\x1b[31m♦\x1b[0m", "♣"};  //\x1b[31m  \x1b[0m Sorg für Rote Farbe
    char *zahlen[13] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "B", "D", "K", "A"};
    int werte[13] = {2,3,4,5,6,7,8,9,10,11,12,13,14};

    int pos = 0;

    //für alle zahlen/symbole werden jeweils 4 Karten erstellt
    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 4; j++) {
            deck[pos].zahl = zahlen[i];
            deck[pos].farbe = farben[j];
            deck[pos].wert = werte[i];
            deck[pos].status = 1;
            pos++;
        }
    }
}

void karten_mischen(struct Karte deck[52]) {

    struct Karte temp;

    for (int i = 0; i < 100; i++) {   //einfach 100mal zwei zufällige Karten miteinander tauschen
        int r = rand() % 52;
        int c = rand() % 52;
        temp = deck[r];
        deck[r] = deck[c];
        deck[c] = temp;
    }
}