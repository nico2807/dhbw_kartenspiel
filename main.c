#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "karten.h"
#include "spieler_und_com.h"
#include "spiel_mechanik.h"

int main(void) {
    srand(time(NULL));

    struct Karte deck[52];
    struct Entitaet spieler;
    struct Entitaet com;

    //Karten, Spieler, COM erstellen und austeilen
    karten_generieren(deck);
    karten_mischen(deck);
    spieler_erstellen(&spieler);
    com_erstellen(&com);

    karten_austeilen(deck, &spieler, &com);

    starte_runde();


    zeige_karten(&spieler);
    zeige_karten(&com);




    return 0;
}
