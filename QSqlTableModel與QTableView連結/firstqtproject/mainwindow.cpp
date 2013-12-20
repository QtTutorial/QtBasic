#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLineEdit>
#include <QCompleter>
#include <QTextCodec>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    db=new YTDBConnection;
    ui->setupUi(this);
    ui->comboBox->setEnabled(false);
    QStringList cityname;
    if(db->OpenDB())
    {
        if(db->getDataList(cityname))
        {
            ui->comboBox->addItems(cityname);
        }
    }
    QStringList test;
    test<<QStringLiteral("郵遞區號")<<QStringLiteral("縣市")<<QStringLiteral("鄉鎮區")<<QStringLiteral("鄉鎮區英文");
    //ui->tableView-;
}
MainWindow::~MainWindow()
{
    db->CloseDB();
    delete db;
    delete ui;
}
void MainWindow::on_checkBox_clicked(bool checked)
{
    if(checked)  ui->comboBox->setEnabled(true);
    else ui->comboBox->setEnabled(false);
}

void MainWindow::on_comboBox_currentIndexChanged(const QString &arg1)
{
     db->getTable(ui->tableView,ui->comboBox->currentText());
}
