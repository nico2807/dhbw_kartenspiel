#ifndef KARTEN_H
#define KARTEN_H

enum Status {
    FALSE,
    TRUE
};

struct Karte {
    char *zahl;
    char *farbe;
    int wert;
    enum Status status;
};





void karten_generieren(struct Karte deck[52]);
void karten_mischen(struct Karte deck[52]);

#endif