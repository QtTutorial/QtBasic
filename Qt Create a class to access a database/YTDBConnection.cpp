#include "YTDBConnection.h"

YTDBConnection::YTDBConnection()
{
}

bool YTDBConnection::OpenDB()
{
    db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("Taiwan");
    return db.open();
}

void YTDBConnection::CloseDB()
{
    db.close();
}
bool YTDBConnection::getDataList(QStringList &d_list)
{
    bool ret=false;
    if(db.open())
    {
        QSqlQuery query("Select City_CName from Taiwan_City");
        while(query.next())
        {
            d_list.append(query.value(0).toString().trimmed());
            ret=true;
        }
    }
    return ret;
}
