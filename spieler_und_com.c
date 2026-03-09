#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "spieler_und_com.h"



void spieler_erstellen(struct Entitaet *s) {
    printf("Geben Sie Ihren Namen ein: ");
    scanf("%49s", s->name);
    s->id = 0;
    s->punkte = 0;
}




void com_erstellen(struct Entitaet *com) {

    int comzahl = rand() % 4 + 1; //zufällige COM Strategie wird gewählt
    com->id = comzahl;

    snprintf(com->name, sizeof(com->name), "COM%d", comzahl);
    com->punkte = 0;

    com->strategie_status = 0;   //wichtig für com3 dass er abwechselnd spielen kann

    //basierend auf gewählten COM die strategie bestimmen
    switch (comzahl) {
        case 1:
            com->strategie = strategie1;
            break;
        case 2:
            com->strategie = strategie2;
            break;
        case 3:
            com->strategie = strategie3;
            break;
        case 4:
            com->strategie = strategie4;
            break;
        default:
            printf("Fehler diesen Bot gibt es nicht\n");
            com_erstellen(com);
            break;
    }
}

//jeder bekommt 10 Handkarten
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
        if (e->handkarten[i].status == TRUE) {
            printf("%s%-3s",
                e->handkarten[i].farbe,
                e->handkarten[i].zahl);
        }
    }
    printf("\n");

    // Nummerierung nur für aktive Karten
    for (int i = 0; i < 10; i++) {
        if (e->handkarten[i].status == TRUE) {
            printf("%-4d", i + 1);
        }
    }
    printf("\n");
}

int strategie1(struct Entitaet *com) {
    //COM Spielt Karten der Reihe nach
    printf("COM1 legt: %s%s\n",
           com->handkarten[zug-1].farbe,
           com->handkarten[zug-1].zahl);
    return zug-1;
}

int strategie2(struct Entitaet *com) {
    //Com Spielt immer höchstmögliche Karte

    int max_index = -1;

    //Erste aktive Karte finden
    for (int i = 0; i < 10; i++) {
        if (com->handkarten[i].status == TRUE) {
            max_index = i;
            break;
        }
    }

    //Höchste aktive Karte suchen
    for (int i = 0; i < 10; i++) {
        if (com->handkarten[i].status == TRUE &&
            com->handkarten[i].wert >
            com->handkarten[max_index].wert) {

            max_index = i;
            }
    }

    // Karte als gespielt markieren
    com->handkarten[max_index].status = FALSE;

    printf("COM2 legt: %s%s\n",
           com->handkarten[max_index].farbe,
           com->handkarten[max_index].zahl);

    return max_index;
}


int strategie3(struct Entitaet *com) {
    //COM spielt abwechseln höchste un niedrigste Karte
    int index = -1;

    //Erste aktive Karte finden
    for (int i = 0; i < 10; i++) {
        if (com->handkarten[i].status == TRUE) {
            index = i;
            break;
        }
    }

    if (index == -1)
        return 0;

    //Wenn status gerade ist soll er die größte spielen
    if (com->strategie_status % 2 == 0) {

        for (int i = 0; i < 10; i++) {
            if (com->handkarten[i].status == TRUE &&
                com->handkarten[i].wert >
                com->handkarten[index].wert) {

                index = i;
                }
        }

        printf("COM3 legt: ");

    }
    else {  //wenn ungerade dann die kleinste spielen

        for (int i = 0; i < 10; i++) {
            if (com->handkarten[i].status == TRUE &&
                com->handkarten[i].wert <
                com->handkarten[index].wert) {

                index = i;
                }
        }

        printf("COM3 legt: ");
    }

    printf("%s%s\n",
           com->handkarten[index].farbe,
           com->handkarten[index].zahl);

    com->handkarten[index].status = FALSE;

    com->strategie_status++;   //status wechseln

    return index;
}


int strategie4(struct Entitaet *com) {
    int kleinste_index = -1;
    int trumpf_index = -1;
    int index = -1;
    int i;

    //kleinsten index finden der aktiven karte
    for (i = 0; i < 10; i++) {
        if (com->handkarten[i].status == TRUE) {
            kleinste_index = i;
            break;
        }
    }

    for (i = 0; i < 10; i++) {
        if (com->handkarten[i].status == TRUE &&
            com->handkarten[i].wert < com->handkarten[kleinste_index].wert) {
            kleinste_index = i;
            }
    }

    for (i = 0; i < 10; i++) {
        if (com->handkarten[i].status == TRUE &&
            com->handkarten[i].wert > letzter_spieler_wert) {

            if (trumpf_index == -1) {
                trumpf_index = i;
            }
            else if (com->handkarten[i].wert < com->handkarten[trumpf_index].wert) {
                trumpf_index = i;
            }
            }
    }

    if (trumpf_index != -1) {
        index = trumpf_index;
        printf("COM4 legt: %s%s", com->handkarten[index].farbe,com->handkarten[index].zahl);
    } else {
        index = kleinste_index;
        printf("COM4 legt: %s%s", com->handkarten[index].farbe,com->handkarten[index].zahl);
    }


    com->handkarten[index].status = FALSE;

    return index;
}
