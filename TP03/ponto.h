#ifndef PONTO_H
#define PONTO_H

typedef struct {
    float X;
    float Y;
    float X2;
    float Y2;
    float X3;
    float Y3;
} Ponto;

double calcularArea(Ponto p1, Ponto p2, Ponto p3);

#endif
