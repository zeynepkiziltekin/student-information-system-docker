#include "StudentManager.hpp"
#include "Logger.hpp"
#include <iostream>

StudentManager::StudentManager(Database& db) : db(db) {}

void StudentManager::addStudent(const Student& student) {
    std::string sql = "INSERT INTO students (name, surname, department, email) VALUES ('" + 
                      student.name + "', '" + student.surname + "', '" + 
                      student.department + "', '" + student.email + "')";
    
    PGresult* res = PQexec(db.getConnection(), sql.c_str());

    if (PQresultStatus(res) != PGRES_COMMAND_OK) {
        std::string error = "Add Student Failed: " + std::string(PQresultErrorMessage(res));
        Logger::getInstance().log(LogLevel::ERROR, error);
    } else {
        Logger::getInstance().log(LogLevel::INFO, "Student added to DB successfully: " + student.email);
    }
    
    PQclear(res);
}

void StudentManager::deleteStudent(int id) {
    std::string sql = "DELETE FROM students WHERE id = " + std::to_string(id);
    PGresult* res = PQexec(db.getConnection(), sql.c_str());

    if (PQresultStatus(res) != PGRES_COMMAND_OK) {
        std::string error = "Delete Student Failed: " + std::string(PQresultErrorMessage(res));
        Logger::getInstance().log(LogLevel::ERROR, error);
    } else {
        // Etkilenen satir sayisini kontrol et (Hicbir sey silinmemis olabilir)
        std::string rowsAffected = PQcmdTuples(res);
        if (rowsAffected == "0") {
             Logger::getInstance().log(LogLevel::WARNING, "Delete operation tried but no student found with ID: " + std::to_string(id));
        } else {
             Logger::getInstance().log(LogLevel::INFO, "Student deleted from DB. ID: " + std::to_string(id));
        }
    }

    PQclear(res);
}

std::vector<Student> StudentManager::getAllStudents() {
    std::vector<Student> students;
    PGresult* res = PQexec(db.getConnection(), "SELECT id, name, surname, department, email FROM students");

    if (PQresultStatus(res) != PGRES_TUPLES_OK) {
        std::string error = "List Students Failed: " + std::string(PQresultErrorMessage(res));
        Logger::getInstance().log(LogLevel::ERROR, error);
        PQclear(res);
        return students;
    }

    int rows = PQntuples(res);
    for (int i = 0; i < rows; i++) {
        Student s;
        s.id = std::stoi(PQgetvalue(res, i, 0));
        s.name = PQgetvalue(res, i, 1);
        s.surname = PQgetvalue(res, i, 2);
        s.department = PQgetvalue(res, i, 3);
        s.email = PQgetvalue(res, i, 4);
        students.push_back(s);
    }

    PQclear(res);
    return students;
}
