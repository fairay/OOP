#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDoubleValidator>
#include <QMessageBox>
#include "defines.h"
#include "model_interface.h"
#include "ui_mainwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionTransform_triggered();

    void on_actionScanFile_triggered();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    model_t model;
    proj_params_t canv_size;
    act_data_t act;
    err_t code;
    draw_t draw;

    /// Draw parameters
    const unsigned int CANVAS_X = 600;
    const unsigned int CANVAS_Y = 550;

    const double MIN_XY = -10;
    const double MAX_XY = 10;

    const double VIEW_X = 2;
    const double VIEW_Y = 4;
    const double VIEW_Z = 11;

    void set_binds(void);
    void show_error_scan(void);

    void make_move_act(void);
    void make_scale_act(void);
    void make_rotate_act(void);
};


#endif // MAINWINDOW_H
