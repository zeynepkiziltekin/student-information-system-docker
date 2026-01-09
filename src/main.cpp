#include <iostream>
#include <limits>
#include "Logger.hpp"
#include "Database.hpp"
#include "StudentManager.hpp"

void printOptions() {
    std::cout << "\n--- Student Information System (Week 4) ---" << std::endl;
    std::cout << "1. Add New Student" << std::endl;
    std::cout << "2. List All Students" << std::endl;
    std::cout << "3. Delete Student" << std::endl;
    std::cout << "4. Exit" << std::endl;
    std::cout << "Select option: ";
}

void runMenu(StudentManager& manager) {
    int choice = 0;
    while (true) {
        printOptions();
        
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
                Logger::getInstance().log(LogLevel::INFO, "New student added: " + email);
                break;
            }
            case 2: {
                auto students = manager.getAllStudents();
                std::cout << "\n--- Student List (" << students.size() << ") ---" << std::endl;
                for (const auto& s : students) {
                    std::cout << "[" << s.id << "] " << s.name << " " << s.surname << " (" << s.email << ")" << std::endl;
                }
                Logger::getInstance().log(LogLevel::INFO, "Listed all students.");
                break;
            }
            case 3: {
                int id;
                std::cout << "Enter Student ID to delete: ";
                std::cin >> id;
                manager.deleteStudent(id);
                Logger::getInstance().log(LogLevel::WARNING, "Deleted student ID: " + std::to_string(id));
                break;
            }
            default:
                std::cout << "Invalid option!" << std::endl;
        }
    }
}

int main() {
    Logger::getInstance().log(LogLevel::INFO, "System started.");
    
    Database db;
    db.connect();

    if (!db.isConnected()) {
        Logger::getInstance().log(LogLevel::ERROR, "Database connection failed.");
        std::cout << "Error: No database connection." << std::endl;
        return 1;
    }

    StudentManager manager(db);
    runMenu(manager);

    Logger::getInstance().log(LogLevel::INFO, "System stopped.");
    return 0;
}
