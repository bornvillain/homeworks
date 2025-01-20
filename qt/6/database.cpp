#include "database.h"

DataBase::DataBase(QObject *parent)
    : QObject{parent}
{
    dataBase = new QSqlDatabase();
    query_model = new QSqlQueryModel();
}

DataBase::~DataBase()
{
    delete dataBase;
    delete query_model;
    delete table_model;
}

/*!
 * \brief Метод добавляет БД к экземпляру класса QSqlDataBase
 * \param driver драйвер БД
 * \param nameDB имя БД (Если отсутствует Qt задает имя по умолчанию)
 */
void DataBase::AddDataBase(QString driver, QString nameDB)
{
    *dataBase = QSqlDatabase::addDatabase(driver, nameDB);
}

/*!
 * \brief Метод подключается к БД
 * \param для удобства передаем контейнер с данными необходимыми для подключения
 * \return возвращает тип ошибки
 */
void DataBase::ConnectToDataBase(QVector<QString> data)
{

    dataBase->setHostName(data[hostName]);
    dataBase->setDatabaseName(data[dbName]);
    dataBase->setUserName(data[login]);
    dataBase->setPassword(data[pass]);
    dataBase->setPort(data[port].toInt());

    bool status;
    status = dataBase->open( );
    emit sig_SendStatusConnection(status);

}
/*!
 * \brief Метод производит отключение от БД
 * \param Имя БД
 */
void DataBase::DisconnectFromDataBase(QString nameDb)
{

    *dataBase = QSqlDatabase::database(nameDb);
    dataBase->close();

}

void DataBase::RequestToDB(QString request, int typeRequest)
{
    switch (typeRequest) {
    case requestAllFilms:
        table_model=new QSqlTableModel(this, *dataBase);
        table_model->setTable("film");
        table_model->setEditStrategy(QSqlTableModel::OnManualSubmit);
        table_model->setQuery(request, *dataBase);
        emit sig_SendDataTableModel(table_model);
        break;
    case requestHorrors:
    case requestComedy:
        query_model->setQuery(request, *dataBase);
        emit sig_SendDataQueryModel(query_model);
        break;
    default:
        break;
    }
}

/*!
 * @brief Метод возвращает последнюю ошибку БД
 */
QSqlError DataBase::GetLastError()
{
    return dataBase->lastError();
}
