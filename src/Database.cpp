#include "Database.hpp"
#include "Logger.hpp"
#include <iostream>

Database::Database() : conn(nullptr) {}

Database::~Database() {
    disconnect();
}

void Database::connect() {
    Logger::getInstance().log(LogLevel::INFO, "Attempting to connect to database...");
    
    // Baglanti cumlesi (Docker ortaminda genelde bu parametreler kullanilir)
    // Eger baglanmazsa password kismini kontrol etmek gerekebilir.
    conn = PQconnectdb("host=db port=5432 dbname=studentdb user=postgres password=postgres");

    if (PQstatus(conn) != CONNECTION_OK) {
        std::string errorMsg = "Connection to database failed: " + std::string(PQerrorMessage(conn));
        Logger::getInstance().log(LogLevel::ERROR, errorMsg);
        disconnect(); // Hatali baglantiyi temizle
    } else {
        Logger::getInstance().log(LogLevel::INFO, "Successfully connected to database.");
    }
}

void Database::disconnect() {
    if (conn != nullptr) {
        PQfinish(conn);
        conn = nullptr;
        Logger::getInstance().log(LogLevel::INFO, "Database connection closed.");
    }
}

bool Database::isConnected() const {
    return conn != nullptr && PQstatus(conn) == CONNECTION_OK;
}

PGconn* Database::getConnection() const {
    return conn;
}
