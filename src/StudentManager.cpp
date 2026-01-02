#include "Student.hpp"
#include <iostream>

StudentManager::StudentManager(Database& db) : db(db) {}

void StudentManager::addStudent(const Student& student) {
    try {
        pqxx::work w(*db.getConnection());
        w.exec_params(
            "INSERT INTO students (name, surname, department, email) VALUES ($1, $2, $3, $4)",
            student.name, student.surname, student.department, student.email
        );
        w.commit();
        std::cout << "Added: " << student.name << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Add error: " << e.what() << std::endl;
    }
}

std::vector<Student> StudentManager::getAllStudents() {
    std::vector<Student> students;
    try {
        pqxx::work w(*db.getConnection());
        pqxx::result r = w.exec("SELECT id, name, surname, department, email FROM students");
        for (auto row : r) {
            students.push_back({
                row[0].as<int>(), row[1].as<std::string>(), row[2].as<std::string>(),
                row[3].as<std::string>(), row[4].as<std::string>()
            });
        }
    } catch (const std::exception &e) {
        std::cerr << "List error: " << e.what() << std::endl;
    }
    return students;
}

void StudentManager::updateStudentEmail(int id, const std::string& newEmail) {
    try {
        pqxx::work w(*db.getConnection());
        w.exec_params("UPDATE students SET email = $1 WHERE id = $2", newEmail, id);
        w.commit();
        std::cout << "Updated student " << id << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Update error: " << e.what() << std::endl;
    }
}

void StudentManager::deleteStudent(int id) {
    try {
        pqxx::work w(*db.getConnection());
        w.exec_params("DELETE FROM students WHERE id = $1", id);
        w.commit();
        std::cout << "Deleted student " << id << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Delete error: " << e.what() << std::endl;
    }
}

std::optional<Student> StudentManager::getStudentById(int id) {
    return std::nullopt; // Simdilik bos
}
