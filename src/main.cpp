#include <iostream>
#include "Database.hpp"
#include "StudentManager.hpp"

int main() {
    std::cout << "System Started - Week 3" << std::endl;

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

    return 0;
}
