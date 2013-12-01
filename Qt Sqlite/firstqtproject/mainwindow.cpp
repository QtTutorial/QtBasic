#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextCodec>
#include <QtSql/QtSql>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->comboBox->setEnabled(false);
    QStringList cityname;
    if(DBConnection(cityname))
        ui->comboBox->addItems(cityname);

}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_checkBox_clicked(bool checked)
{
    if(checked)  ui->comboBox->setEnabled(true);
    else ui->comboBox->setEnabled(false);
}
bool MainWindow::DBConnection(QStringList &citylist)
{
    QSqlDatabase db;
    db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("Taiwan");
    if(db.open())
    {
        QSqlQuery query("Select City_cname from Taiwan_City");
        while(query.next())
        {
            citylist.append(query.value(0).toString().trimmed());
        }
        qDebug()<<"Success";
		db.close();

         return true;
    }
    else return false;
}
