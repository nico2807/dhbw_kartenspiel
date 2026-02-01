#include <stdio.h>
#include "karten.h"

#include <stdlib.h>
#include <time.h>
#include "spieler_und_com.h"



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

    struct Karte deck[52];
    struct Spieler spieler;

    // Kartendeck vorbereiten
    karten_generieren(deck);
    karten_mischen(deck);

    // Spieler erstellen
    spieler_erstellen(&spieler);

    // Karten austeilen
    karten_austeilen(deck, &spieler);

    // Test-Ausgabe
    printf("\nSpieler: %s\n", spieler.name);
    for (int i = 0; i < 10; i++) {
        printf("%s %s (Wert %d)\n",
               spieler.handkarten[i].zahl,
               spieler.handkarten[i].farbe,
               spieler.handkarten[i].wert);
    }

    return 0;
}

