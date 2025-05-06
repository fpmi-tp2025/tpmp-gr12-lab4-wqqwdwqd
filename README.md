## Project Name: Country Management System

### Description
Country Management System — это консольное приложение на языке C, которое позволяет управлять данными о странах и регионах. Приложение обеспечивает следующие функции:
- **Добавление/удаление/обновление** данных о странах и регионах.
- **Аутентификация пользователей** с использованием простой системы логина и пароля.
- **Работа с базой данных SQLite**, включая хранение информации о странах, регионах и изображениях флагов.
- **Выполнение различных SQL-запросов**, таких как выборка, удаление и обновление данных.

### 🛠 Installation
Для установки и запуска приложения выполните следующие шаги:

1. **Установите зависимости (если необходимо):**
   Убедитесь, что у вас установлены:
   - GCC (GNU Compiler Collection)
   - SQLite3

   Для Ubuntu/Debian:
   ```bash
   sudo apt update
   sudo apt install gcc sqlite3 libsqlite3-dev
   ```

2. **Скомпилируйте проект:**
   Перейдите в корень проекта и выполните:
   ```bash
   make
   ```

3. **Создайте базу данных (если её нет):**
   Если файл `countries.db` отсутствует, создайте его с помощью скрипта:
   ```bash
   sqlite3 countries.db < create_tables.sql
   ```
   Где `create_tables.sql` содержит SQL-запросы для создания таблиц.

4. **Запустите приложение:**
   После успешной сборки выполните:
   ```bash
   ./bin/app
   ```

### Usage
После запуска приложения вы увидите следующее:

#### 1. Аутентификация
```
Enter username: admin
Enter password: password
Authentication successful.
```

#### 2. Добавление страны и регионов
Пример добавления России и её регионов:
```
Adding Russia...
Adding Moscow region...
Adding Saint Petersburg region...
Adding Novosibirsk region...
```

#### 3. Получение информации
- **Список регионов по стране:**
  ```
  Regions in country ID 1:
  ID: 1 | Name: Moscow | Capital: Moscow | Population: 12000000 | Square: 2511.00
  ID: 2 | Name: Saint Petersburg | Capital: Saint Petersburg | Population: 5400000 | Square: 1439.00
  ID: 3 | Name: Novosibirsk | Capital: Novosibirsk | Population: 1600000 | Square: 317.00
  ```

- **Среднее население регионов:**
  ```
  Average population of Russia: 6333333.33
  ```

- **Общее население всех стран:**
  ```
  Total population in the database: 146000000
  ```

#### 4. Удаление данных
- Удаление региона:
  ```
  Deleting region with ID 1...
  Region deleted successfully.
  ```

- Удаление страны:
  ```
  Deleting country with ID 1...
  Country and associated regions deleted successfully.
  ```

### Contributing
Проект был разработан студентом Хань Юй в рамках учебного задания. Были реализованы следующие задачи:
- Создание структуры базы данных SQLite.
- Реализация CRUD-операций для таблиц `country` и `region`.
- Разработка интерфейса аутентификации.
- Обработка SQL-запросов для получения статистики.
- Поддержка хранения изображений флагов в формате BLOB.

