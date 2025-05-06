#include <stdio.h>
#include "auth.h"
#include "database.h"

int main() {
    sqlite3* db;
    if (init_database(&db, "countries.db") != SQLITE_OK) {
        fprintf(stderr, "Failed to initialize database.\n");
        return 1;
    }

    // Аутентификация пользователя
    printf("Enter username: ");
    char username[50];
    scanf("%s", username);
    printf("Enter password: ");
    char password[50];
    scanf("%s", password);

    if (!authenticate_user(username, password)) {
        printf("Authentication failed.\n");
        close_database(db);
        return 1;
    }

    printf("Authentication successful.\n");

    // Пример добавления страны
    add_country(db, "Russia", "Moscow", "Russian", 146000000, 17098246.0, "RUB", "Vladimir Putin");

    // Пример добавления региона
    add_region(db, "Moscow", 1, "Moscow", 12000000, 2511.0);
    add_region(db, "Saint Petersburg", 1, "Saint Petersburg", 5400000, 1439.0);
    add_region(db, "Novosibirsk", 1, "Novosibirsk", 1600000, 317.0);

    // Пример получения информации
    get_regions_by_country(db, 1);
    printf("Average population of Russia: %.2f\n", get_average_population_by_country(db, 1));
    printf("Total population in the database: %d\n", get_total_population(db));

    close_database(db);
    return 0;
}