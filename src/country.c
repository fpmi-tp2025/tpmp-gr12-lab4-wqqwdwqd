#include "country.h"

void print_country(const Country* country) {
    printf("Country ID: %d\n", country->id);
    printf("Name: %s\n", country->name);
    printf("Capital: %s\n", country->capital);
    printf("Language: %s\n", country->language);
    printf("Population: %d\n", country->population);
    printf("Square: %.2f\n", country->square);
    printf("Currency: %s\n", country->currency);
    printf("Head of State: %s\n", country->head);
}
