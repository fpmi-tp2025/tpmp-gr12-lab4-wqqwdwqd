#ifndef REGION_H
#define REGION_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[100];
    char capital[100];
    int population;
    double square;
    int country_id;
} Region;

void print_region(const Region* region);

#endif // REGION_H
