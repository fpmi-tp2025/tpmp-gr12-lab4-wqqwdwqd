#ifndef DATABASE_H
#define DATABASE_H

#include <sqlite3.h>

// Инициализация базы данных
int init_database(sqlite3** db, const char* db_path);

// Закрытие базы данных
void close_database(sqlite3* db);

// Добавление страны
int add_country(sqlite3* db, const char* name, const char* capital, const char* language,
               int population, double square, const char* currency, const char* head);

// Добавление региона
int add_region(sqlite3* db, const char* name, int country_id, const char* capital,
              int population, double square);

// Удаление страны
int delete_country(sqlite3* db, int country_id);

// Удаление региона
int delete_region(sqlite3* db, int region_id);

// Получение списка регионов по стране
int get_regions_by_country(sqlite3* db, int country_id);

// Получение среднего населения по регионам страны
double get_average_population_by_country(sqlite3* db, int country_id);

// Получение суммы населения всех стран
int get_total_population(sqlite3* db);

#endif // DATABASE_H
