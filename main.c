#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "karten.h"
#include "spieler_und_com.h"

int main(void) {
    srand(time(NULL));

    struct Karte deck[52];
    struct Entitaet spieler;
    struct Entitaet com;

    karten_generieren(deck);
    karten_mischen(deck);

    spieler_erstellen(&spieler);
    com_erstellen(&com);

    karten_austeilen(deck, &spieler, &com);

    printf("\nSpieler %s:\n", spieler.name);
    for (int i = 0; i < 10; i++) {
        printf("%s %s (%d)\n",
               spieler.handkarten[i].zahl,
               spieler.handkarten[i].farbe,
               spieler.handkarten[i].wert);
    }

    printf("\n%s:\n", com.name);
    for (int i = 0; i < 10; i++) {
        printf("%s %s (%d)\n",
               com.handkarten[i].zahl,
               com.handkarten[i].farbe,
               com.handkarten[i].wert);
    }

    return 0;
}
