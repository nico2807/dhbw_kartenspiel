#include <stdio.h>
#include "spiel_mechanik.h"
#include "spieler_und_com.h"

int zug = 1;
int gewinner = 2;  // 1 = Spieler      2 = COM      0 = unentschieden

void starte_runde(struct Entitaet *spieler, struct Entitaet *com) {
    printf("========================================\n"
           ">>> Das Spiel beginnt! <<<\n"
           "========================================\n");

    zug_com(spieler, com);       //Ermittle Starter anhand zug oder letztem gewinner
}


void zug_com(struct Entitaet *spieler, struct Entitaet *com) {
    int wahl;
    int com_wahl;
    printf("[Zug %d]\n",zug);

    //zeige_karten(com);

    com_wahl = com_legt(com);
    zeige_karten(spieler);
    wahl = kartenwahl(spieler);
    zug += 1;
    ermittle_sieger(wahl, com_wahl);
}

int kartenwahl(struct Entitaet *spieler) {
    int wahl;
    printf("Wähle eine Karte: ");
    scanf("%d", &wahl);
    printf("Spieler legt: %s%s",
        spieler->handkarten[wahl-1].farbe,
        spieler->handkarten[wahl-1].zahl);
    return wahl;
}

int com_legt(struct Entitaet *com) {
    if (com->id == 1) {
        printf("COM legt die Karte: %s%s",
            com->handkarten[zug-1].farbe,
            com->handkarten[zug-1].zahl);
        return zug+1;
    }
}

void ermittle_sieger(int wahl, int com_wahl, struct Entitaet *spieler, struct Entitaet *com) {
    if (spieler->handkarten[wahl].wert > com->handkarten[com_wahl].wert) {
        gewinner = 1;
    }
    else if (spieler->handkarten[wahl].wert < com->handkarten[com_wahl].wert) {
        gewinner = 2;
    }
    else {
        gewinner = 0;
    }
}

