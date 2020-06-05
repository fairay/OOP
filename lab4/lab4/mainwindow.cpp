#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), _layout(), _elevator(5)
{
    ui->setupUi(this);
    ui->elv_widget->setLayout(&_layout);
    _layout.addWidget(_elevator.get_qwidget());
}

MainWindow::~MainWindow()
{
    delete ui;
}