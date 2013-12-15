#ifndef YTDBCONNECTION_H
#define YTDBCONNECTION_H
#include <QtSql/QtSql>

class YTDBConnection
{
public:
    YTDBConnection();   //constructor
public:
    bool OpenDB();  //Connect to my database "Taiwan"
    void CloseDB(); //Close database
    bool getDataList(QStringList &d_list); //get a list of the Taiwan city names from database
private:
    QSqlDatabase db;
};

#endif // YTDBCONNECTION_H
