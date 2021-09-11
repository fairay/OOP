#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), _elevator(6)
{
    ui->setupUi(this);
    ui->elv_widget->setLayout(&_elevator);
}

MainWindow::~MainWindow()
{
    delete ui;
}
