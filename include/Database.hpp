#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <string>
#include <memory>
#include <pqxx/pqxx>

class Database {
public:
    // Yapici metod (Constructor)
    Database();
    
    // Yikici metod (Destructor - Baglantiyi kapatir)
    ~Database();

    // Veritabanina baglanma fonksiyonu
    void connect();
    
    // Baglanti durumunu kontrol etme
    bool isConnected() const;

    // Baglanti objesini dondurme (Sorgu atmak icin)
    pqxx::connection* getConnection();

private:
    std::string connectionString;
    std::unique_ptr<pqxx::connection> dbConnection;
};

#endif
