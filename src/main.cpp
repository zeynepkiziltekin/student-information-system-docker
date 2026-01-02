
#include <iostream>

#include "Logger.hpp"

#include "Database.hpp"
#include "StudentManager.hpp"

int main() {

    std::cout << "System Started - Week 3" << std::endl;

    Logger::getInstance().log(LogLevel::INFO, "System Started - Week 3 Phase 3");


    Database db;
    db.connect();

    if (db.isConnected()) {

        StudentManager manager(db);
        std::cout << "Testing CRUD operations..." << std::endl;
        
        manager.addStudent({0, "Test", "User", "CS", "test@itu.edu.tr"});
        
        auto list = manager.getAllStudents();
        std::cout << "Count: " << list.size() << std::endl;
    } else {
        std::cout << "Offline mode (No DB connection on Windows)." << std::endl;
    }


        Logger::getInstance().log(LogLevel::INFO, "Database connection successful.");
        StudentManager manager(db);
    } else {
        Logger::getInstance().log(LogLevel::ERROR, "Database connection FAILED (Expected on local Windows).");
    }

    Logger::getInstance().log(LogLevel::INFO, "Application shutting down...");

    return 0;
}
