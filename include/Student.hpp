#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>
#include <vector>
#include <optional>
#include "Database.hpp"

struct Student {
    int id;
    std::string name;
    std::string surname;
    std::string department;
    std::string email;
};

class StudentManager {
public:
    explicit StudentManager(Database& db);
    void addStudent(const Student& student);
    std::vector<Student> getAllStudents();
    std::optional<Student> getStudentById(int id);
    void updateStudentEmail(int id, const std::string& newEmail);
    void deleteStudent(int id);

private:
    Database& db;
};

#endif
