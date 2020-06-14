#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "iostream"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    _qscene(new QGraphicsScene(-10, -10, 10, 10)),
    _scene(new Scene())
{
    ui->setupUi(this);
    ui->graphicsView->setScene(&(*_qscene));
    _set_binds();

    try
    {
        command::AddCamera add_cmd(2, 4, 500);
        _scene.execute(add_cmd);

        command::LoadCarcass load_cmd(ui->name_file->text().toStdString());
        _scene.execute(load_cmd);

        command::QDrawScene draw_cmd(_qscene, QPen(Qt::red), QPen(Qt::blue));
        _scene.execute(draw_cmd);
        cout << ";)" << endl;
    }
    catch (err::SceneError &err)
    {
        cout << err.what() << endl;
    }
    catch (...)
    {
        cout << "Unknown error!" << endl;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_transButton_clicked()
{
    try
    {
        shared_ptr<command::BaseCommand> cmd;
        switch (ui->tabWidget->currentIndex())
        {
            case 0:
                cmd = _move_cmd();
                break;
            case 1:
                cmd = _scale_cmd();
                break;
            case 2:
                cmd = _rotate_cmd();
                break;
        }
        _scene.execute(*cmd);

        command::QDrawScene draw_cmd(_qscene, QPen(Qt::red), QPen(Qt::blue));
        _scene.execute(draw_cmd);
        cout << ";)" << endl;
    }
    catch (err::SceneError &err)
    {
        _show_error(err.what());
    }
    catch (...)
    {
        _show_error("Unknown error!");
    }



}

void MainWindow::on_readButton_clicked()
{
    try
    {
        command::LoadCarcass load_cmd(ui->name_file->text().toStdString());
        _scene.execute(load_cmd);
        cout << ";)" << endl;

        command::RemoveObject del_cmd(1);
        _scene.execute(del_cmd);

        command::QDrawScene draw_cmd(_qscene, QPen(Qt::red), QPen(Qt::blue));
        _scene.execute(draw_cmd);
        cout << ";)" << endl;
    }
    catch (err::SceneError &err)
    {
        _show_error(err.what());
    }
    catch (...)
    {
        _show_error("Unknown error!");
    }
}

shared_ptr<command::BaseCommand> MainWindow::_move_cmd(void)
{
    double x, y, z;

    x = ui->move_x->text().toDouble();
    y = ui->move_y->text().toDouble();
    z = ui->move_z->text().toDouble();
    return shared_ptr<command::BaseCommand>(new command::Move(x, y, z, 1));
}

shared_ptr<command::BaseCommand> MainWindow::_scale_cmd(void)
{
    double x, y, z;

    x = ui->scale_kx->text().toDouble();
    y = ui->scale_ky->text().toDouble();
    z = ui->scale_kz->text().toDouble();
    return shared_ptr<command::BaseCommand>(new command::Scale(x, y, z, 1));
}

shared_ptr<command::BaseCommand> MainWindow::_rotate_cmd(void)
{
    double x, y, z;

    x = ui->rotate_ax->text().toDouble();
    y = ui->rotate_ay->text().toDouble();
    z = ui->rotate_az->text().toDouble();
    return shared_ptr<command::BaseCommand>(new command::Rotate(x, y, z, 1));
}

void MainWindow::_show_error(const char* err)
{
    QMessageBox error_scan_msg(QMessageBox::Critical, "Error", err);
    error_scan_msg.exec();
}

void MainWindow::_set_binds(void)
{
    QValidator *val = new QDoubleValidator();
    val->setLocale(QLocale(QLocale::English));

    ui->move_x->setValidator(val);
    ui->move_y->setValidator(val);
    ui->move_z->setValidator(val);

    ui->scale_kx->setValidator(val);
    ui->scale_ky->setValidator(val);
    ui->scale_kz->setValidator(val);

    ui->rotate_ax->setValidator(val);
    ui->rotate_ay->setValidator(val);
    ui->rotate_az->setValidator(val);
}
