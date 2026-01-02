#include "Logger.hpp"
#include "Database.hpp"
#include "StudentManager.hpp"

int main() {
    Logger::getInstance().log(LogLevel::INFO, "System Started - Week 3 Phase 3");

    Database db;
    db.connect();

    if (db.isConnected()) {
        Logger::getInstance().log(LogLevel::INFO, "Database connection successful.");
        StudentManager manager(db);
    } else {
        Logger::getInstance().log(LogLevel::ERROR, "Database connection FAILED (Expected on local Windows).");
    }

    Logger::getInstance().log(LogLevel::INFO, "Application shutting down...");
    return 0;
}
