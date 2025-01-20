#ifndef DATABASE_H
#define DATABASE_H

#include <QTableWidget>
#include <QTableView>
#include <QObject>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QSqlTableModel>

#define POSTGRE_DRIVER "QPSQL"
#define DB_NAME "netology_cpp"

//Количество полей данных необходимых для подключения к БД
#define NUM_DATA_FOR_CONNECT_TO_DB 5

//Перечисление полей данных
enum fieldsForConnect{
    hostName = 0,
    dbName = 1,
    login = 2,
    pass = 3,
    port = 4
};

//Типы запросов
enum requestType{

    requestAllFilms = 1,
    requestComedy   = 2,
    requestHorrors  = 3

};

class DataBase : public QObject
{
    Q_OBJECT

public:
    explicit DataBase(QObject *parent = nullptr);
    ~DataBase();

    void AddDataBase(QString driver, QString nameDB = "");
    void DisconnectFromDataBase(QString nameDb = "");
    void RequestToDB(QString request, int typeRequest);
    QSqlError GetLastError(void);
    void ConnectToDataBase(QVector<QString> dataForConnect);


signals:
    void sig_SendStatusConnection(bool);
    void sig_SendDataTableModel(QSqlTableModel *tableModel);
    void sig_SendDataQueryModel(QSqlQueryModel *queryModel);

private:

    QSqlDatabase* dataBase;
    QSqlQueryModel* query_model;
    QSqlTableModel* table_model;
};

#endif // DATABASE_H
