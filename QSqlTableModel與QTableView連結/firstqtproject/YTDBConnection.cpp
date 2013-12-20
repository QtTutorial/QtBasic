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
    if(db.isOpen())//Open database
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

bool YTDBConnection::getTable(QTableView *srcTable,QString currentText)
{
    bool ret=false;
    if(db.isOpen())//Open database
    {
        QSqlTableModel *model=new QSqlTableModel(srcTable,db);
        model->setTable("Taiwan_PostCode");
        model->setEditStrategy(QSqlTableModel::OnManualSubmit);
        model->select();
        model->setFilter("City_CName='"+currentText+"'");
        srcTable->setModel(model);
    }
    return ret;
}
