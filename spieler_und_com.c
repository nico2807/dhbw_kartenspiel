#include <stdio.h>
#include "spieler_und_com.h"

void spieler_erstellen(struct Spieler *s) {
    printf("Geben Sie Ihren Namen ein: ");
    scanf("%49s", s->name);

    s->id = 0;
    s->punkte = 0;
}

void karten_austeilen(struct Karte deck[52], struct Spieler *s) {
    for (int i = 0; i < 10; i++) {
        s->handkarten[i] = deck[i];
    }
}