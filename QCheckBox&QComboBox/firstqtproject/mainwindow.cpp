#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->comboBox->setEnabled(false);
    QStringList cityname;
    cityname<<"Keelung"<<"Taipei"<<"Xinbei";
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
