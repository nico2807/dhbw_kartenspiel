#include <stdio.h>
#include "spieler_und_com.h"

//Idee: alle entitäten erstellen, es sind ja genug karten da und anschliessend kann der spieler den gegner wählen

// Erstellung spieler
void spieler_erstellen(struct Entitaet *s) {
    printf("Geben Sie Ihren Namen ein: ");
    scanf("%49s", s->name);
    s->id = 0;
    s->punkte = 0;
}

int spieler_waehlt_com() {
    int wahl;
    printf("Waehle einen COM (1, 2 oder 3): ");
    scanf("%d", &wahl);
    return wahl;
}

// bot id wird anhand dieser funktion gewählt


void com_erstellen(struct Entitaet *com) {
    com->id = spieler_waehlt_com();
    com->punkte = 0;
}

void karten_austeilen(struct Karte deck[52],
                      struct Entitaet *spieler,
                      struct Entitaet *bot) {
    for (int i = 0; i < 10; i++) {
        spieler->handkarten[i] = deck[i];
        bot->handkarten[i]     = deck[i + 10];
    }
}


