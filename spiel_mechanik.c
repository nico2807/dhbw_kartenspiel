#include <stdio.h>
#include "spiel_mechanik.h"

int zug = 1;

void starte_runde() {
    printf("========================================\n"
           ">>> Das Spiel beginnt! <<<\n"
           "========================================\n");

    zug_com();
}


void zug_com() {
    printf("[Zug %d]\n",zug);
    zug += 1;

}

int kartenwahl() {

}