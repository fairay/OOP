#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "iostream"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    _scene(new QGraphicsScene(-1, -1, 1, 1))
{
    ui->setupUi(this);
    ui->graphicsView->setScene(&(*_scene));
}

MainWindow::~MainWindow()
{
    delete ui;
}
