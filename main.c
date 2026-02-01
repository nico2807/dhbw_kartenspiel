#include <stdio.h>
#include "karten.h"

#include <stdlib.h>
#include <time.h>

void test(struct Karte deck[52]) {
    for (int i = 0; i < 52; i++) {
        printf("%s %s (Wert %d)\n",
               deck[i].zahl,
               deck[i].farbe,
               deck[i].wert);
    }
}




int main(void) {

    srand(time(NULL));

    struct Karte deck[52];                          // speicher reservieren für Kartendeck

    karten_generieren(deck);
    test(deck);
    karten_mischen(deck);
    printf("Jetst die gemischten:::::----------------------\n");
    test(deck);

    //TO-DO: Spieler erstellen und 1 COM Gegner
    //To_DO: Hadkarten austeilen

    struct Spieler {
        int id;
        char handkarten[9];

    };





    return 0;
}
