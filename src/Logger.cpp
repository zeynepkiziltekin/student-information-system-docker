#include "Logger.hpp"
#include <ctime>
#include <iomanip>

Logger& Logger::getInstance() {
    static Logger instance;
    return instance;
}

Logger::Logger() {
    // Loglari 'app.log' dosyasina da kaydedelim
    logFile.open("app.log", std::ios::app);
}

Logger::~Logger() {
    if (logFile.is_open()) {
        logFile.close();
    }
}

void Logger::log(LogLevel level, const std::string& message) {
    std::lock_guard<std::mutex> guard(logMutex);
    
    std::string timestamp = getTimestamp();
    std::string levelStr = levelToString(level);
    std::string finalMessage = "[" + timestamp + "] [" + levelStr + "] " + message;

    // Hem ekrana yaz
    std::cout << finalMessage << std::endl;

    // Hem dosyaya yaz (Varsa)
    if (logFile.is_open()) {
        logFile << finalMessage << std::endl;
    }
}

std::string Logger::getTimestamp() {
    std::time_t now = std::time(nullptr);
    std::tm* localTime = std::localtime(&now);
    
    std::ostringstream oss;
    oss << std::put_time(localTime, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}

std::string Logger::levelToString(LogLevel level) {
    switch (level) {
        case LogLevel::INFO: return "INFO";
        case LogLevel::WARNING: return "WARN";
        case LogLevel::ERROR: return "ERROR";
        default: return "UNKNOWN";
    }
}
