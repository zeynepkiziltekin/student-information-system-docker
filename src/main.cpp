#include <iostream>
#include <limits>
#include "Logger.hpp"
#include "Database.hpp"
#include "StudentManager.hpp"

void printMenu() {
    std::cout << "\n--- Student Information System ---" << std::endl;
    std::cout << "1. Add New Student" << std::endl;
    std::cout << "2. List All Students" << std::endl;
    std::cout << "3. Delete Student" << std::endl;
    std::cout << "4. Exit" << std::endl;
    std::cout << "Select option: ";
}

int main() {
    Logger::getInstance().log(LogLevel::INFO, "Application UI started.");
    
    Database db;
    db.connect();

    if (!db.isConnected()) {
        Logger::getInstance().log(LogLevel::ERROR, "Database connection failed. Exiting menu.");
        std::cout << "Error: No database connection (Are you running in Docker?). Exiting." << std::endl;
        return 1;
    }

    StudentManager manager(db);
    int choice = 0;

    while (true) {
        printMenu();
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number." << std::endl;
            continue;
        }

        if (choice == 4) {
            std::cout << "Exiting system..." << std::endl;
            break;
        }

        switch (choice) {
            case 1: {
                std::string name, surname, dept, email;
                std::cout << "Name: "; std::cin >> name;
                std::cout << "Surname: "; std::cin >> surname;
                std::cout << "Department: "; std::cin >> dept;
                std::cout << "Email: "; std::cin >> email;
                
                manager.addStudent({0, name, surname, dept, email});
                Logger::getInstance().log(LogLevel::INFO, "User added a new student: " + email);
                break;
            }
            case 2: {
                auto students = manager.getAllStudents();
                std::cout << "\n--- Student List (" << students.size() << ") ---" << std::endl;
                for (const auto& s : students) {
                    std::cout << "[" << s.id << "] " << s.name << " " << s.surname << " (" << s.email << ")" << std::endl;
                }
                Logger::getInstance().log(LogLevel::INFO, "User listed all students.");
                break;
            }
            case 3: {
                int id;
                std::cout << "Enter Student ID to delete: ";
                std::cin >> id;
                manager.deleteStudent(id);
                Logger::getInstance().log(LogLevel::WARNING, "User deleted student ID: " + std::to_string(id));
                break;
            }
            default:
                std::cout << "Invalid option!" << std::endl;
        }
    }

    Logger::getInstance().log(LogLevel::INFO, "Application UI stopped.");


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
