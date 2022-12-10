#ifndef DATABASE_H
#define DATABASE_H
#include <SQLiteCpp/Database.h>
#include <sqlite3.h>
#include <string>

class Database {
public:
    Database() = delete;

    ~Database() = default;

public:
    bool isValid() const;


public:
    void createNewDatabase();

    void logPackageDelivery(uint64_t _userId, unsigned int deliveryAmount);

    unsigned int getDeliveryAmount(uint64_t _userId);


public:
    static Database* createConnection(const std::string& _dbPath);

private:
    Database(SQLite::Database _databaseConnection);



private:

    SQLite::Database m_databaseConnection;


    unsigned int DEFAULT_NUMBER_OF_PACKAGES;
    unsigned int DEFAULT_COOL_DOWN;


};


#endif // DATABASE_H
