#ifndef KARTEN_H
#define KARTEN_H

struct Karte {
    char *zahl;
    char *farbe;
    int wert;
};




void karten_generieren(struct Karte deck[52]);
void karten_mischen(struct Karte deck[52]);

#endif