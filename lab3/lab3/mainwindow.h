#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QMessageBox>
#include <QDoubleValidator>

#include "memory"
#include "scene/scene_interface.h"
#include "scene/scene.h"
#include "command/commands.h"


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
    void on_transButton_clicked();
    void on_readButton_clicked();

private:
    Ui::MainWindow *ui;
    std::shared_ptr<QGraphicsScene> _qscene;
    SceneInterface _scene;

    void _show_error(const char* err);
    void _set_binds(void);
    void _init_scene();

    shared_ptr<command::BaseCommand> _move_cmd(void);
    shared_ptr<command::BaseCommand> _scale_cmd(void);
    shared_ptr<command::BaseCommand> _rotate_cmd(void);
};

#endif // MAINWINDOW_H
