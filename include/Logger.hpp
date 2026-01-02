#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <mutex>

enum class LogLevel {
    INFO,
    WARNING,
    ERROR
};

class Logger {
public:
    // Singleton: Tek bir logger nesnesi heryerden kullanilsin
    static Logger& getInstance();

    // Log yazdirma fonksiyonu
    void log(LogLevel level, const std::string& message);

private:
    Logger(); // Constructor private (Singleton kurali)
    ~Logger();

    std::ofstream logFile;
    std::mutex logMutex; // Ayni anda iki yerden yazilirsa karismasin diye
    
    std::string getTimestamp();
    std::string levelToString(LogLevel level);
};

#endif
