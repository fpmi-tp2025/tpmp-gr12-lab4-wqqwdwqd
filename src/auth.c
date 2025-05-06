#include "auth.h"

int authenticate_user(const char* username, const char* password) {
    // Простая проверка имени пользователя и пароля
    if (strcmp(username, "admin") == 0 && strcmp(password, "password") == 0) {
        return 1; // Успешная аутентификация
    }
    return 0; // Неуспешная аутентификация
}
