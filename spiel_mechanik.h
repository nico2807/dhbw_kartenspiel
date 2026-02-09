#ifndef SPIEL_H
#define SPIEL_H


#include "spieler_und_com.h"   // CHANGED: damit struct Entitaet bekannt ist

/* CHANGED: Spieler/Com als Parameter übergeben */
void starte_runde(struct Entitaet *spieler, struct Entitaet *com);
void zug_com(struct Entitaet *spieler, struct Entitaet *com);

/* kartenwahl liest nur Eingabe, braucht keine Parameter */
int kartenwahl(struct Entitaet *spieler);
int com_legt(struct Entitaet *com);
void ermittle_sieger(wahl, com_wahl);

#endif