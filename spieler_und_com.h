#ifndef SPIELER_UND_COM_H
#define SPIELER_UND_COM_H

#include "karten.h"

struct Entitaet {
    int id;
    char name[50];
    struct Karte handkarten[10];
    int handkartenanzahl;
    int punkte;
};




void spieler_erstellen(struct Entitaet *s);
void com_erstellen(struct Entitaet *com);


void karten_austeilen(struct Karte deck[52],
                      struct Entitaet *spieler,
                      struct Entitaet *bot);

void zeige_karten(struct Entitaet *e);


#endif