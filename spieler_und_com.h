#ifndef SPIELER_UND_COM_H
#define SPIELER_UND_COM_H

#include "karten.h"

struct Entitaet {
    int id;
    char name[50];
    struct Karte handkarten[10];
    int handkartenanzahl;
    int punkte;
    int (*strategie)(struct Entitaet *);
    int strategie_status;                   //für com3 der abwechselnd größte und kleinste Karte spielt
};


extern int zug;


void spieler_erstellen(struct Entitaet *s);
void com_erstellen(struct Entitaet *com);


void karten_austeilen(struct Karte deck[52],
                      struct Entitaet *spieler,
                      struct Entitaet *bot);

void zeige_karten(struct Entitaet *e);

int strategie1(struct Entitaet *com);
int strategie2(struct Entitaet *com);
int strategie3(struct Entitaet *com);
int strategie4(struct Entitaet *com);


#endif