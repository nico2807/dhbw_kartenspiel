#include <stdio.h>
#include "spieler_und_com.h"
#include "spiel_mechanik.h"



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

    com->strategie_status = 0;

    if (comzahl == 1)
        com->strategie = strategie1;
    else if (comzahl == 2)
        com->strategie = strategie2;
    else
        com->strategie = strategie3;
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

    printf("\nDie Karten von %s sind:\n", e->name);

    for (int i = 0; i < 10; i++) {
        if (e->handkarten[i].status == 1) {
            printf("%s%-3s",
                e->handkarten[i].farbe,
                e->handkarten[i].zahl);
        }
    }
    printf("\n");

    // Nummerierung nur für aktive Karten
    for (int i = 0; i < 10; i++) {
        if (e->handkarten[i].status == 1) {
            printf("%-4d", i + 1);
        }
    }
    printf("\n");
}

int strategie1(struct Entitaet *com) {
    printf("COM legt (Strategie 1): %s%s\n",
           com->handkarten[zug-1].farbe,
           com->handkarten[zug-1].zahl);
    return zug-1;
}

int strategie2(struct Entitaet *com) {

    int max_index = -1;

    //Erste aktive Karte finden
    for (int i = 0; i < 10; i++) {
        if (com->handkarten[i].status == 1) {
            max_index = i;
            break;
        }
    }

    //Höchste aktive Karte suchen
    for (int i = 0; i < 10; i++) {
        if (com->handkarten[i].status == 1 &&
            com->handkarten[i].wert >
            com->handkarten[max_index].wert) {

            max_index = i;
            }
    }

    // Karte als gespielt markieren
    com->handkarten[max_index].status = 0;

    printf("COM spielt höchste Karte: %s%s\n",
           com->handkarten[max_index].farbe,
           com->handkarten[max_index].zahl);

    return max_index;
}


int strategie3(struct Entitaet *com) {

    int index = -1;

    // Erste aktive Karte finden
    for (int i = 0; i < 10; i++) {
        if (com->handkarten[i].status == 1) {
            index = i;
            break;
        }
    }

    if (index == -1)
        return 0;   // Sicherheit

    // Wenn state gerade ist → größte spielen
    if (com->strategie_status % 2 == 0) {

        for (int i = 0; i < 10; i++) {
            if (com->handkarten[i].status == 1 &&
                com->handkarten[i].wert >
                com->handkarten[index].wert) {

                index = i;
                }
        }

        printf("COM spielt größte Karte: ");

    }
    else {  // ungerade → kleinste spielen

        for (int i = 0; i < 10; i++) {
            if (com->handkarten[i].status == 1 &&
                com->handkarten[i].wert <
                com->handkarten[index].wert) {

                index = i;
                }
        }

        printf("COM spielt kleinste Karte: ");
    }

    printf("%s%s\n",
           com->handkarten[index].farbe,
           com->handkarten[index].zahl);

    com->handkarten[index].status = 0;

    com->strategie_status++;   // 👈 wechseln

    return index;
}


int strategie4(struct Entitaet *com) {
    printf("Strategie 4 spielt immer letzte Karte\n");
    return 9;
}


