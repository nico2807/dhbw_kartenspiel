#ifndef KARTEN_H
#define KARTEN_H

enum Status { //ist die Karte aktiv oder nicht? (wie Booleans)
    FALSE,
    TRUE
};

struct Karte {
    char *zahl;
    char *farbe;
    int wert;
    enum Status status; //aktivv oder nicht
};


void karten_generieren(struct Karte deck[52]);
void karten_mischen(struct Karte deck[52]);

#endif