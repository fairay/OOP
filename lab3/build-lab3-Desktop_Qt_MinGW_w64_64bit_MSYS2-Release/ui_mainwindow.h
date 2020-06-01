/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionTransform;
    QAction *actionScanFile;
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QFrame *move_frame;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *move_x;
    QLineEdit *move_y;
    QLineEdit *move_z;
    QLabel *label_2;
    QWidget *tab_2;
    QFrame *move_frame_4;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLineEdit *scale_kx;
    QLineEdit *scale_ky;
    QLineEdit *scale_kz;
    QLabel *label_17;
    QWidget *tab_3;
    QFrame *move_frame_5;
    QLabel *label_18;
    QLabel *label_20;
    QLineEdit *rotate_ax;
    QLineEdit *rotate_az;
    QLabel *label_21;
    QLabel *label_19;
    QLineEdit *rotate_ay;
    QLabel *label;
    QLabel *label_22;
    QLabel *label_23;
    QPushButton *transButton;
    QLineEdit *name_file;
    QPushButton *readButton;
    QGraphicsView *graphicsView;
    QFrame *line_3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(719, 837);
        MainWindow->setMinimumSize(QSize(719, 837));
        MainWindow->setMaximumSize(QSize(719, 837));
        QFont font;
        font.setPointSize(11);
        MainWindow->setFont(font);
        MainWindow->setWindowOpacity(1.000000000000000);
        actionTransform = new QAction(MainWindow);
        actionTransform->setObjectName(QString::fromUtf8("actionTransform"));
        actionTransform->setCheckable(true);
        actionScanFile = new QAction(MainWindow);
        actionScanFile->setObjectName(QString::fromUtf8("actionScanFile"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setFont(font);
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(20, 50, 521, 171));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        move_frame = new QFrame(tab);
        move_frame->setObjectName(QString::fromUtf8("move_frame"));
        move_frame->setGeometry(QRect(0, 0, 511, 141));
        move_frame->setFrameShape(QFrame::StyledPanel);
        move_frame->setFrameShadow(QFrame::Raised);
        label_3 = new QLabel(move_frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 40, 51, 20));
        label_4 = new QLabel(move_frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 70, 51, 20));
        label_5 = new QLabel(move_frame);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 100, 51, 20));
        move_x = new QLineEdit(move_frame);
        move_x->setObjectName(QString::fromUtf8("move_x"));
        move_x->setGeometry(QRect(80, 40, 391, 20));
        move_y = new QLineEdit(move_frame);
        move_y->setObjectName(QString::fromUtf8("move_y"));
        move_y->setGeometry(QRect(80, 70, 391, 20));
        move_z = new QLineEdit(move_frame);
        move_z->setObjectName(QString::fromUtf8("move_z"));
        move_z->setGeometry(QRect(80, 100, 391, 20));
        label_2 = new QLabel(move_frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 5, 491, 21));
        label_2->setAlignment(Qt::AlignCenter);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        move_frame_4 = new QFrame(tab_2);
        move_frame_4->setObjectName(QString::fromUtf8("move_frame_4"));
        move_frame_4->setGeometry(QRect(0, 0, 511, 141));
        move_frame_4->setFrameShape(QFrame::StyledPanel);
        move_frame_4->setFrameShadow(QFrame::Raised);
        label_14 = new QLabel(move_frame_4);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(10, 40, 51, 20));
        label_15 = new QLabel(move_frame_4);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(10, 70, 51, 20));
        label_16 = new QLabel(move_frame_4);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(10, 100, 51, 20));
        scale_kx = new QLineEdit(move_frame_4);
        scale_kx->setObjectName(QString::fromUtf8("scale_kx"));
        scale_kx->setGeometry(QRect(80, 40, 391, 20));
        scale_ky = new QLineEdit(move_frame_4);
        scale_ky->setObjectName(QString::fromUtf8("scale_ky"));
        scale_ky->setGeometry(QRect(80, 70, 391, 20));
        scale_kz = new QLineEdit(move_frame_4);
        scale_kz->setObjectName(QString::fromUtf8("scale_kz"));
        scale_kz->setGeometry(QRect(80, 100, 391, 20));
        label_17 = new QLabel(move_frame_4);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(10, 5, 501, 21));
        label_17->setAlignment(Qt::AlignCenter);
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        move_frame_5 = new QFrame(tab_3);
        move_frame_5->setObjectName(QString::fromUtf8("move_frame_5"));
        move_frame_5->setGeometry(QRect(0, 0, 511, 141));
        move_frame_5->setFrameShape(QFrame::StyledPanel);
        move_frame_5->setFrameShadow(QFrame::Raised);
        label_18 = new QLabel(move_frame_5);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(10, 40, 61, 20));
        label_20 = new QLabel(move_frame_5);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(10, 100, 61, 20));
        rotate_ax = new QLineEdit(move_frame_5);
        rotate_ax->setObjectName(QString::fromUtf8("rotate_ax"));
        rotate_ax->setGeometry(QRect(80, 40, 381, 20));
        rotate_az = new QLineEdit(move_frame_5);
        rotate_az->setObjectName(QString::fromUtf8("rotate_az"));
        rotate_az->setGeometry(QRect(80, 100, 381, 20));
        label_21 = new QLabel(move_frame_5);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(10, 5, 501, 21));
        label_21->setAlignment(Qt::AlignCenter);
        label_19 = new QLabel(move_frame_5);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(10, 70, 61, 20));
        rotate_ay = new QLineEdit(move_frame_5);
        rotate_ay->setObjectName(QString::fromUtf8("rotate_ay"));
        rotate_ay->setGeometry(QRect(80, 70, 381, 20));
        label = new QLabel(move_frame_5);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(460, 40, 35, 16));
        label_22 = new QLabel(move_frame_5);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(460, 70, 35, 16));
        label_23 = new QLabel(move_frame_5);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(460, 100, 35, 16));
        tabWidget->addTab(tab_3, QString());
        transButton = new QPushButton(centralWidget);
        transButton->setObjectName(QString::fromUtf8("transButton"));
        transButton->setGeometry(QRect(550, 70, 151, 151));
        QFont font1;
        font1.setPointSize(13);
        transButton->setFont(font1);
        name_file = new QLineEdit(centralWidget);
        name_file->setObjectName(QString::fromUtf8("name_file"));
        name_file->setGeometry(QRect(40, 10, 481, 31));
        readButton = new QPushButton(centralWidget);
        readButton->setObjectName(QString::fromUtf8("readButton"));
        readButton->setGeometry(QRect(550, 5, 151, 41));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(60, 240, 600, 550));
        graphicsView->setMinimumSize(QSize(600, 550));
        graphicsView->setMaximumSize(QSize(600, 550));
        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(10, 220, 701, 20));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 719, 17));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(move_x, move_y);
        QWidget::setTabOrder(move_y, move_z);
        QWidget::setTabOrder(move_z, transButton);
        QWidget::setTabOrder(transButton, tabWidget);

        retranslateUi(MainWindow);
        QObject::connect(transButton, SIGNAL(clicked()), actionTransform, SLOT(trigger()));
        QObject::connect(readButton, SIGNAL(clicked()), actionScanFile, SLOT(trigger()));

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\320\233\320\260\320\261\320\276\321\200\320\260\321\202\320\276\321\200\320\275\320\260\321\217 \321\200\320\260\320\261\320\276\321\202\320\260 \342\204\2261", nullptr));
        actionTransform->setText(QApplication::translate("MainWindow", "Transform", nullptr));
#ifndef QT_NO_SHORTCUT
        actionTransform->setShortcut(QApplication::translate("MainWindow", "Return", nullptr));
#endif // QT_NO_SHORTCUT
        actionScanFile->setText(QApplication::translate("MainWindow", "ScanFile", nullptr));
#ifndef QT_NO_ACCESSIBILITY
        tab->setAccessibleName(QApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\274\320\265\321\211\320\265\320\275\320\270\320\265", nullptr));
#endif // QT_NO_ACCESSIBILITY
        label_3->setText(QApplication::translate("MainWindow", "\316\224x = ", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\316\224y = ", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "\316\224z =", nullptr));
        move_x->setInputMask(QString());
        move_x->setText(QApplication::translate("MainWindow", "0.0", nullptr));
        move_x->setPlaceholderText(QApplication::translate("MainWindow", "\320\245 \321\201\320\274\320\265\321\211\320\265\320\275\320\270\320\265", nullptr));
        move_y->setText(QApplication::translate("MainWindow", "0.0", nullptr));
        move_y->setPlaceholderText(QApplication::translate("MainWindow", "Y \321\201\320\274\320\265\321\211\320\265\320\275\320\270\320\265", nullptr));
        move_z->setText(QApplication::translate("MainWindow", "0.0", nullptr));
        move_z->setPlaceholderText(QApplication::translate("MainWindow", "Z \321\201\320\274\320\265\321\211\320\265\320\275\320\270\320\265", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\320\241\320\274\320\265\321\211\320\265\320\275\320\270\320\265", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\274\320\265\321\211\320\265\320\275\320\270\320\265", nullptr));
        label_14->setText(QApplication::translate("MainWindow", "kx = ", nullptr));
        label_15->setText(QApplication::translate("MainWindow", "ky = ", nullptr));
        label_16->setText(QApplication::translate("MainWindow", "kz =", nullptr));
        scale_kx->setInputMask(QString());
        scale_kx->setText(QApplication::translate("MainWindow", "1.0", nullptr));
        scale_kx->setPlaceholderText(QApplication::translate("MainWindow", "kX", nullptr));
        scale_ky->setText(QApplication::translate("MainWindow", "1.0", nullptr));
        scale_ky->setPlaceholderText(QApplication::translate("MainWindow", "kY", nullptr));
        scale_kz->setText(QApplication::translate("MainWindow", "1.0", nullptr));
        scale_kz->setPlaceholderText(QApplication::translate("MainWindow", "kZ", nullptr));
        label_17->setText(QApplication::translate("MainWindow", "\320\232\320\276\321\215\321\204\321\204\320\270\321\206\320\270\320\265\320\275\321\202\321\213 \320\274\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\320\275\320\270\321\217", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265", nullptr));
        label_18->setText(QApplication::translate("MainWindow", "\342\210\240x = ", nullptr));
        label_20->setText(QApplication::translate("MainWindow", "\342\210\240z =", nullptr));
        rotate_ax->setInputMask(QString());
        rotate_ax->setText(QApplication::translate("MainWindow", "0.0", nullptr));
        rotate_ax->setPlaceholderText(QApplication::translate("MainWindow", "\320\222\321\200\320\260\321\211\320\265\320\275\320\270\320\265 \320\262\320\276\320\272\321\200\321\203\320\263 OX", nullptr));
        rotate_az->setText(QApplication::translate("MainWindow", "0.0", nullptr));
        rotate_az->setPlaceholderText(QApplication::translate("MainWindow", "\320\222\321\200\320\260\321\211\320\265\320\275\320\270\320\265 \320\262\320\276\320\272\321\200\321\203\320\263 OZ", nullptr));
        label_21->setText(QApplication::translate("MainWindow", "\320\243\320\263\320\273\321\213 \320\262\321\200\320\260\321\211\320\265\320\275\320\270\321\217", nullptr));
        label_19->setText(QApplication::translate("MainWindow", "\342\210\240y = ", nullptr));
        rotate_ay->setInputMask(QString());
        rotate_ay->setText(QApplication::translate("MainWindow", "0.0", nullptr));
        rotate_ay->setPlaceholderText(QApplication::translate("MainWindow", "\320\222\321\200\320\260\321\211\320\265\320\275\320\270\320\265 \320\262\320\276\320\272\321\200\321\203\320\263 OY", nullptr));
        label->setText(QApplication::translate("MainWindow", " \302\260", nullptr));
        label_22->setText(QApplication::translate("MainWindow", " \302\260", nullptr));
        label_23->setText(QApplication::translate("MainWindow", " \302\260", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "\320\222\321\200\320\260\321\211\320\265\320\275\320\270\320\265", nullptr));
        transButton->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\277\320\276\320\273\320\275\320\270\321\202\321\214", nullptr));
        name_file->setInputMask(QString());
        name_file->setText(QApplication::translate("MainWindow", "input.txt", nullptr));
        name_file->setPlaceholderText(QApplication::translate("MainWindow", "\320\270\320\274\321\217 \321\204\320\260\320\271\320\273\320\260", nullptr));
        readButton->setText(QApplication::translate("MainWindow", "\320\241\321\207\320\270\321\202\320\260\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
