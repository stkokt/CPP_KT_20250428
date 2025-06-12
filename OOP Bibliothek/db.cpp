#include "C:\SQLite\sqlite3.h"
#include<iostream>
#include <iostream>
#include <vector>
#include <tuple>
#include <string>
//#include <sqlite3.h>

// Funktion zum Aufrufen von SQLite-Callbacks
static int callback(void* NotUsed, int argc, char** argv, char** azColName) {
    for (int i = 0; i < argc; i++) {
        std::cout << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL") << std::endl;
    }
    std::cout << std::endl;
    return 0;
}

int main() {
    sqlite3* db;
    char* errMsg = 0;
    int rc;

    // Daten als Vektor von Tuples
    std::vector<std::tuple<std::string, std::string, std::string, std::string, short, std::string, std::string>> medien = {
        {"978-3-423-12345-6", "Thomas Mann", "Der Zauberberg", "1924", 16, "2025-06-15", "AS25Q20002"}
    };

    // Datenbank öffnen
    rc = sqlite3_open("medien.db", &db);
    if (rc) {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
        return 1;
    } else {
        std::cout << "Opened database successfully" << std::endl;
    }

    // SQL-Befehl zum Erstellen der Tabelle
    const char* sqlCreateTable = "CREATE TABLE IF NOT EXISTS MEDIEN("
                                 "ISBN TEXT PRIMARY KEY, "
                                 "AUTOR TEXT NOT NULL, "
                                 "TITEL TEXT NOT NULL, "
                                 "JAHR TEXT NOT NULL, "
                                 "ANZAHL_EXEMPLARE INTEGER NOT NULL, "
                                 "AUSLEIHDATUM TEXT, "
                                 "SIGNATUR TEXT NOT NULL);";

    // Tabelle erstellen
    rc = sqlite3_exec(db, sqlCreateTable, callback, 0, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    } else {
        std::cout << "Table created successfully" << std::endl;
    }

    // SQL-Befehl zum Einfügen der Daten
    std::string sqlInsert = "INSERT INTO MEDIEN (ISBN, AUTOR, TITEL, JAHR, ANZAHL_EXEMPLARE, AUSLEIHDATUM, SIGNATUR) VALUES ";
    for (const auto& medium : medien) {
        sqlInsert += "('" + std::get<0>(medium) + "', '" +
                     std::get<1>(medium) + "', '" +
                     std::get<2>(medium) + "', '" +
                     std::get<3>(medium) + "', " +
                     std::to_string(std::get<4>(medium)) + ", '" +
                     std::get<5>(medium) + "', '" +
                     std::get<6>(medium) + "'),";
    }
    sqlInsert.pop_back(); // Entferne das letzte Komma
    sqlInsert += ";";

    // Daten einfügen
    rc = sqlite3_exec(db, sqlInsert.c_str(), callback, 0, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    } else {
        std::cout << "Records created successfully" << std::endl;
    }

    // Datenbank schließen
    sqlite3_close(db);

    return 0;
}
