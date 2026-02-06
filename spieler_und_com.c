#include <stdio.h>
#include "spieler_und_com.h"



void spieler_erstellen(struct Entitaet *s) {
    printf("Geben Sie Ihren Namen ein: ");
    scanf("%49s", s->name);
    s->id = 0;
    s->punkte = 0;
}

//da hier Random machen
int spieler_waehlt_com() {
    int wahl;
    printf("Waehle einen COM (1, 2 oder 3): ");
    scanf("%d", &wahl);
    return wahl;
}


void com_erstellen(struct Entitaet *com) {
    int comzahl = spieler_waehlt_com();
    com->id = comzahl;
    snprintf(com->name, sizeof(com->name), "COM%d", comzahl);
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

void zeige_karten(struct Entitaet *e) {
    //Eigentlich nur karten von spieler wichtig, aber zum testen auch COM Karten möglich
    printf("\nDie Karten von %s sind:\n", e->name);

    for (int i = 0; i < 10; i++) {
        printf("%s%-3s",               //-=linksbündig, 3=feldbreite,s=string
            e->handkarten[i].farbe,
            e->handkarten[i].zahl);
    }
    printf(" \n");
    for (int i = 0; i < 10; i++) {
        printf("%-4d", i + 1);
    }
    printf("\n");
}


