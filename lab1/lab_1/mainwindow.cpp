#include "mainwindow.h"
#include "model_interface.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    canv_size = create_params();
    point_t view_p = create_point(VIEW_X, VIEW_Y, VIEW_Z);
    set_canvas_xy(canv_size, CANVAS_X, CANVAS_Y);
    set_point_view(canv_size, view_p);
    set_xy_range(canv_size, MIN_XY, MAX_XY);

    act = set_view_act(canv_size);
    code = model_action(act);

    scene = new QGraphicsScene(-10, -10, 20, 20);
    ui->graphicsView->setScene(scene);
    draw = init_draw(scene);

    set_binds();
    on_actionScanFile_triggered();
}

MainWindow::~MainWindow()
{
    act = clear_act();
    model_action(act);
    delete ui;
}

void MainWindow::make_move_act(void)
{
    double x, y, z;
    point_t p;
    transform_t trans;

    x = ui->move_x->text().toDouble();
    y = ui->move_y->text().toDouble();
    z = ui->move_z->text().toDouble();
    p = create_point(x, y, z);

    trans = create_move_trans(p);
    act = move_act(trans);
}
void MainWindow::make_scale_act(void)
{
    double x, y, z;
    double kx, ky, kz;
    point_t center;
    scale_t scale;
    transform_t trans;

    x = ui->scale_x->text().toDouble();
    y = ui->scale_y->text().toDouble();
    z = ui->scale_z->text().toDouble();
    center = create_point(x, y, z);

    kx = ui->scale_kx->text().toDouble();
    ky = ui->scale_ky->text().toDouble();
    kz = ui->scale_kz->text().toDouble();
    scale = create_scale(kx, ky, kz);

    trans = create_scale_trans(center, scale);
    act = scale_act(trans);

}
void MainWindow::make_rotate_act(void)
{
    double x, y, z;
    double ax, ay, az;
    point_t center;
    angle_t angles;
    transform_t trans;

    x = ui->rotate_x->text().toDouble();
    y = ui->rotate_y->text().toDouble();
    z = ui->rotate_z->text().toDouble();
    center = create_point(x, y, z);

    ax = ui->rotate_ax->text().toDouble();
    ay = ui->rotate_ay->text().toDouble();
    az = ui->rotate_az->text().toDouble();
    angles = create_angle_deg(ax, ay, az);

    trans = create_rotate_trans(center, angles);
    act = rotate_act(trans);
}

void MainWindow::on_actionTransform_triggered()
{
    switch (ui->tabWidget->currentIndex())
    {
        case 0:
            make_move_act();
            break;
        case 1:
            make_scale_act();
            break;
        case 2:
            make_rotate_act();
            break;
    }
    code = model_action(act);

    act = draw_act(draw);
    code = model_action(act);
}

void MainWindow::on_actionScanFile_triggered()
{
    const char *f_name = ui->name_file->text().toStdString().c_str();

    act = load_file_act(f_name);
    code = model_action(act);

    if (!code)
    {
        act = draw_act(draw);
        code = model_action(act);
    }
    else
        show_error_scan();
}


void MainWindow::set_binds(void)
{
    QValidator *val = new QDoubleValidator();
    val->setLocale(QLocale(QLocale::English));

    ui->move_x->setValidator(val);
    ui->move_y->setValidator(val);
    ui->move_z->setValidator(val);

    ui->scale_x->setValidator(val);
    ui->scale_y->setValidator(val);
    ui->scale_z->setValidator(val);
    ui->scale_kx->setValidator(val);
    ui->scale_ky->setValidator(val);
    ui->scale_kz->setValidator(val);

    ui->rotate_x->setValidator(val);
    ui->rotate_y->setValidator(val);
    ui->rotate_z->setValidator(val);
    ui->rotate_ax->setValidator(val);
    ui->rotate_ay->setValidator(val);
    ui->rotate_az->setValidator(val);
}

void MainWindow::show_error_scan(void)
{
    QMessageBox error_scan_msg(QMessageBox::Critical, "Error", "File scaning failed!");
    error_scan_msg.exec();
}
