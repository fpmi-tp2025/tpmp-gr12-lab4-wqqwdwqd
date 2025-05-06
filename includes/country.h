#ifndef COUNTRY_H
#define COUNTRY_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[100];
    char capital[100];
    char language[50];
    int population;
    double square;
    char currency[3];
    char head[100];
} Country;

void print_country(const Country* country);

#endif // COUNTRY_H
