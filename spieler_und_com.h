#ifndef SPIELER_UND_COM_H
#define SPIELER_UND_COM_H

#include "karten.h"   // <-- GANZ WICHTIG

struct Spieler {
    int id;
    char name[50];
    struct Karte handkarten[10];
    int punkte;
};

// Funktionsdeklarationen
void spieler_erstellen(struct Spieler *s);
void karten_austeilen(struct Karte deck[52], struct Spieler *s);

#endif
