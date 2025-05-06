#include "region.h"

void print_region(const Region* region) {
    printf("Region ID: %d\n", region->id);
    printf("Name: %s\n", region->name);
    printf("Capital: %s\n", region->capital);
    printf("Population: %d\n", region->population);
    printf("Square: %.2f\n", region->square);
    printf("Country ID: %d\n", region->country_id);
}
