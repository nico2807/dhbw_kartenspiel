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

int spieler_waehlt_bot() {
    int wahl;
    printf("Gegen welchen der Bots willst du spielen");
    scanf("%d", &wahl);
    return wahl;
}

// bot id wird anhand dieser funktion gewählt


void com_erstellen(struct Entitaet *s) {

}

void karten_austeilen(struct Karte deck[52], struct Entitaet *s) {
    for (int i = 0; i < 10; i++) {
        s->handkarten[i] = deck[i];
    }
}

//TO-DO: Eigenen struct für spieler und com