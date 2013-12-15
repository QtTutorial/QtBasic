#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringList>
#include "YTDBConnection.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_checkBox_clicked(bool checked);

private:
    Ui::MainWindow *ui;
    YTDBConnection *db;
};

#endif // MAINWINDOW_H
