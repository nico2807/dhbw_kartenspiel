#include <stdio.h>
#include "karten.h"

#include <stdlib.h>
#include <time.h>





int main(void) {

    srand(time(NULL));

    struct Karte deck[52];                          // speicher reservieren für Kartendeck

    karten_generieren(deck);
    karten_mischen(deck);

    for (int i = 0; i < 52; i++) {
        printf("%s %s (Wert %d)\n",
               deck[i].zahl,
               deck[i].farbe,
               deck[i].wert);
    }

    return 0;
}
