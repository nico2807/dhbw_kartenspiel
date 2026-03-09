#ifndef SPIEL_H
#define SPIEL_H


#include "spieler_und_com.h"


void starte_runde(struct Entitaet *spieler, struct Entitaet *com);
void zug_com(struct Entitaet *spieler, struct Entitaet *com);


int kartenwahl(struct Entitaet *spieler);
int com_legt(struct Entitaet *com);
int ermittle_sieger(int wahl, int com_wahl, struct Entitaet *spieler, struct Entitaet *com);
void zug_spieler(struct Entitaet *spieler, struct Entitaet *com);
void gesamtsieger(struct Entitaet *spieler, struct Entitaet *com);


#endif