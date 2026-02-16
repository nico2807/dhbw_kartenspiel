#include <stdio.h>
#include "spiel_mechanik.h"
#include "spieler_und_com.h"


int zug = 1;
int gewinner = 2;  // 1 = Spieler      2 = COM      0 = unentschieden
int starter;

void starte_runde(struct Entitaet *spieler, struct Entitaet *com) {
    printf("========================================\n"
           ">>> Das Spiel beginnt! <<<\n"
           "========================================\n\n");

    while (zug < 11) {
        if (gewinner == 1) {
            zug_spieler(spieler, com);
        }
        else if (gewinner == 2) {
            zug_com(spieler, com);
        }
    }
    gesamtsieger(spieler, com);
}

void zug_com(struct Entitaet *spieler, struct Entitaet *com) {
    int wahl;
    int com_wahl;
    starter = 2;
    printf("\n[Zug %d]\n",zug);

    com_wahl = com_legt(com);
    zeige_karten(spieler);
    wahl = kartenwahl(spieler);
    zug += 1;
    ermittle_sieger(wahl, com_wahl, spieler, com);
}

void zug_spieler(struct Entitaet *spieler, struct Entitaet *com) {
    int wahl;
    int com_wahl;
    starter = 1;
    printf("\n[Zug %d]",zug);
    zeige_karten(spieler);
    wahl = kartenwahl(spieler);
    com_wahl = com_legt(com);
    zug += 1;
    ermittle_sieger(wahl, com_wahl, spieler, com);
}

int kartenwahl(struct Entitaet *spieler) {
    int wahl;
    printf("Wähle eine Karte: ");
    scanf("%d", &wahl);
    spieler->handkarten[wahl-1].status = 0;
    printf("Spieler legt: %s%s\n",
        spieler->handkarten[wahl-1].farbe,
        spieler->handkarten[wahl-1].zahl);
    return wahl-1;
}


int com_legt(struct Entitaet *com) {
    return com->strategie(com);
}


int ermittle_sieger(int wahl, int com_wahl, struct Entitaet *spieler, struct Entitaet *com) {
    if (spieler->handkarten[wahl].wert > com->handkarten[com_wahl].wert) {
        gewinner = 1;
        spieler->punkte += (spieler->handkarten[wahl].wert + com->handkarten[com_wahl].wert);
        printf("\n%s Gewinnt den Stich!\n", spieler->name);
    }
    else if (spieler->handkarten[wahl].wert < com->handkarten[com_wahl].wert) {
        gewinner = 2;
        com->punkte += (spieler->handkarten[wahl].wert + com->handkarten[com_wahl].wert);
        printf("\n%s Gewinnt den Stich!\n", com->name);
    }
    else {
        gewinner = starter;
        if (starter == 1) {
            spieler->punkte += (spieler->handkarten[wahl].wert + com->handkarten[com_wahl].wert);
            printf("\nUnentschieden – %s bleibt dran!\n",spieler->name);
        }
        else {
            com->punkte += (spieler->handkarten[wahl].wert + com->handkarten[com_wahl].wert);
            printf("\nUnentschieden – %s bleibt dran!\n",com->name);
        }
    }
    return gewinner;
}

void gesamtsieger(struct Entitaet *spieler, struct Entitaet *com) {
    if (com->punkte > spieler->punkte) {
        printf("\n%s Gewinnt mit %d Punkten", com->name, com-> punkte);
    }
    else if (com->punkte < spieler->punkte) {
        printf("\n%s Gewinnt mit %d Punkten", spieler->name, spieler->punkte);
    }
    else {
        printf("\n Gleichstand, %s Gewinnt mit %d Punkten", spieler->name, spieler->punkte);
    }
}



//evtl nochmal spielen funktion