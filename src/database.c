#include "database.h"
#include <stdio.h>

int init_database(sqlite3** db, const char* db_path) {
    return sqlite3_open(db_path, db);
}

void close_database(sqlite3* db) {
    sqlite3_close(db);
}

int add_country(sqlite3* db, const char* name, const char* capital, const char* language,
                int population, double square, const char* currency, const char* head) {
    const char* sql = "INSERT INTO country (name, capital, language, population_country, square_country, currency, head_country) VALUES (?, ?, ?, ?, ?, ?, ?);";
    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Failed to prepare statement: %s\n", sqlite3_errmsg(db));
        return rc;
    }

    sqlite3_bind_text(stmt, 1, name, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, capital, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, language, -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 4, population);
    sqlite3_bind_double(stmt, 5, square);
    sqlite3_bind_text(stmt, 6, currency, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 7, head, -1, SQLITE_STATIC);

    rc = sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    return rc;
}

int add_region(sqlite3* db, const char* name, int country_id, const char* capital,
               int population, double square) {
    const char* sql = "INSERT INTO region (name, country_id, capital_region, population_region, square_region) VALUES (?, ?, ?, ?, ?);";
    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Failed to prepare statement: %s\n", sqlite3_errmsg(db));
        return rc;
    }

    sqlite3_bind_text(stmt, 1, name, -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 2, country_id);
    sqlite3_bind_text(stmt, 3, capital, -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 4, population);
    sqlite3_bind_double(stmt, 5, square);

    rc = sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    return rc;
}

int delete_country(sqlite3* db, int country_id) {
    // Удаление связанного региона автоматически выполняется через ON DELETE CASCADE

    const char* sql = "DELETE FROM country WHERE id = ?;";
    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Failed to prepare statement: %s\n", sqlite3_errmsg(db));
        return rc;
    }

    sqlite3_bind_int(stmt, 1, country_id);
    rc = sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    return rc;
}

int delete_region(sqlite3* db, int region_id) {
    const char* sql = "DELETE FROM region WHERE id = ?;";
    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Failed to prepare statement: %s\n", sqlite3_errmsg(db));
        return rc;
    }

    sqlite3_bind_int(stmt, 1, region_id);
    rc = sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    return rc;
}

int get_regions_by_country(sqlite3* db, int country_id) {
    const char* sql = "SELECT id, name, capital_region, population_region, square_region FROM region WHERE country_id = ?;";
    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Failed to prepare statement: %s\n", sqlite3_errmsg(db));
        return rc;
    }

    sqlite3_bind_int(stmt, 1, country_id);

    printf("Regions in country ID %d:\n", country_id);
    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        const char* name = (const char*)sqlite3_column_text(stmt, 1);
        const char* capital = (const char*)sqlite3_column_text(stmt, 2);
        int population = sqlite3_column_int(stmt, 3);
        double square = sqlite3_column_double(stmt, 4);

        printf("ID: %d | Name: %s | Capital: %s | Population: %d | Square: %.2f\n",
               id, name, capital, population, square);
    }

    sqlite3_finalize(stmt);
    return rc;
}

double get_average_population_by_country(sqlite3* db, int country_id) {
    const char* sql = "SELECT AVG(population_region) FROM region WHERE country_id = ?;";
    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Failed to prepare statement: %s\n", sqlite3_errmsg(db));
        return 0.0;
    }

    sqlite3_bind_int(stmt, 1, country_id);

    double avg_pop = 0.0;
    if (sqlite3_step(stmt) == SQLITE_ROW) {
        avg_pop = sqlite3_column_double(stmt, 0);
    }

    sqlite3_finalize(stmt);
    return avg_pop;
}

int get_total_population(sqlite3* db) {
    const char* sql = "SELECT SUM(population_country) FROM country;";
    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Failed to prepare statement: %s\n", sqlite3_errmsg(db));
        return 0;
    }

    int total_pop = 0;
    if (sqlite3_step(stmt) == SQLITE_ROW) {
        total_pop = sqlite3_column_int(stmt, 0);
    }

    sqlite3_finalize(stmt);
    return total_pop;
}
