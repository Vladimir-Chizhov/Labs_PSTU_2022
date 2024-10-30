/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QPushButton *add_ver_btn;
    QTextEdit *add_ver_textEdit;
    QLabel *add_ver_status_label;
    QLabel *add_ver_name_label;
    QLabel *add_ver_info_label;
    QPushButton *del_ver_btn;
    QTextEdit *add_ver_vername_textEdit;
    QLabel *add_edge_name_label;
    QLabel *add_edge_f_label;
    QTextEdit *add_edge_f_textEdit;
    QTextEdit *add_edge_s_textEdit;
    QLabel *add_edge_s_label;
    QTextEdit *add_edge_ves_textEdit;
    QLabel *add_edge_ves_label;
    QPushButton *add_edge_btn;
    QLabel *add_edge_status_label;
    QPushButton *del_edge_btn;
    QLabel *BFS_name_label;
    QLabel *BFS_info_label;
    QTextEdit *BFS_textEdit;
    QPushButton *BFS_btn;
    QTextBrowser *BFS_result_textBrowser;
    QLabel *BFS_status_label;
    QPushButton *DFS_btn;
    QPushButton *DA_btn;
    QPushButton *example_graph_btn;
    QPushButton *example_graph_delete;
    QLabel *TSP_info_label;
    QLabel *TSP_name_label;
    QTextEdit *TSP_textEdit;
    QTextBrowser *TSP_result_textBrowser;
    QLabel *TSP_status_label;
    QPushButton *TSP_btn;
    QTextBrowser *TSP_result_textBrowser_2;
    QMenuBar *menubar;
    QMenu *menutravelingSalesman;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1160, 700);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(1160, 700));
        MainWindow->setMaximumSize(QSize(1160, 700));
        MainWindow->setTabShape(QTabWidget::TabShape::Rounded);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(460, 20, 680, 660));
        sizePolicy.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy);
        graphicsView->setStyleSheet(QString::fromUtf8("background-color: rgba(200, 200, 200, 150);\n"
"\n"
""));
        graphicsView->setFrameShadow(QFrame::Shadow::Plain);
        add_ver_btn = new QPushButton(centralwidget);
        add_ver_btn->setObjectName("add_ver_btn");
        add_ver_btn->setGeometry(QRect(130, 100, 71, 30));
        add_ver_textEdit = new QTextEdit(centralwidget);
        add_ver_textEdit->setObjectName("add_ver_textEdit");
        add_ver_textEdit->setGeometry(QRect(1140, 0, 20, 20));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(10);
        add_ver_textEdit->setFont(font);
        add_ver_textEdit->setStyleSheet(QString::fromUtf8("background-color: rgba(200, 200, 200, 0);"));
        add_ver_status_label = new QLabel(centralwidget);
        add_ver_status_label->setObjectName("add_ver_status_label");
        add_ver_status_label->setGeometry(QRect(290, 60, 141, 30));
        add_ver_status_label->setFont(font);
        add_ver_name_label = new QLabel(centralwidget);
        add_ver_name_label->setObjectName("add_ver_name_label");
        add_ver_name_label->setGeometry(QRect(100, 10, 231, 20));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Arial")});
        font1.setPointSize(10);
        font1.setBold(true);
        add_ver_name_label->setFont(font1);
        add_ver_info_label = new QLabel(centralwidget);
        add_ver_info_label->setObjectName("add_ver_info_label");
        add_ver_info_label->setGeometry(QRect(150, 35, 161, 21));
        add_ver_info_label->setFont(font);
        del_ver_btn = new QPushButton(centralwidget);
        del_ver_btn->setObjectName("del_ver_btn");
        del_ver_btn->setGeometry(QRect(210, 100, 71, 30));
        add_ver_vername_textEdit = new QTextEdit(centralwidget);
        add_ver_vername_textEdit->setObjectName("add_ver_vername_textEdit");
        add_ver_vername_textEdit->setGeometry(QRect(130, 60, 151, 30));
        add_ver_vername_textEdit->setFont(font);
        add_edge_name_label = new QLabel(centralwidget);
        add_edge_name_label->setObjectName("add_edge_name_label");
        add_edge_name_label->setGeometry(QRect(70, 150, 291, 20));
        add_edge_name_label->setFont(font1);
        add_edge_f_label = new QLabel(centralwidget);
        add_edge_f_label->setObjectName("add_edge_f_label");
        add_edge_f_label->setGeometry(QRect(50, 180, 20, 30));
        add_edge_f_label->setFont(font);
        add_edge_f_textEdit = new QTextEdit(centralwidget);
        add_edge_f_textEdit->setObjectName("add_edge_f_textEdit");
        add_edge_f_textEdit->setGeometry(QRect(80, 180, 40, 30));
        add_edge_f_textEdit->setFont(font);
        add_edge_s_textEdit = new QTextEdit(centralwidget);
        add_edge_s_textEdit->setObjectName("add_edge_s_textEdit");
        add_edge_s_textEdit->setGeometry(QRect(150, 180, 40, 30));
        add_edge_s_textEdit->setFont(font);
        add_edge_s_label = new QLabel(centralwidget);
        add_edge_s_label->setObjectName("add_edge_s_label");
        add_edge_s_label->setGeometry(QRect(130, 180, 10, 30));
        add_edge_s_label->setFont(font);
        add_edge_ves_textEdit = new QTextEdit(centralwidget);
        add_edge_ves_textEdit->setObjectName("add_edge_ves_textEdit");
        add_edge_ves_textEdit->setGeometry(QRect(235, 180, 40, 30));
        add_edge_ves_textEdit->setFont(font);
        add_edge_ves_label = new QLabel(centralwidget);
        add_edge_ves_label->setObjectName("add_edge_ves_label");
        add_edge_ves_label->setGeometry(QRect(200, 180, 25, 30));
        add_edge_ves_label->setFont(font);
        add_edge_btn = new QPushButton(centralwidget);
        add_edge_btn->setObjectName("add_edge_btn");
        add_edge_btn->setGeometry(QRect(120, 220, 71, 30));
        add_edge_status_label = new QLabel(centralwidget);
        add_edge_status_label->setObjectName("add_edge_status_label");
        add_edge_status_label->setGeometry(QRect(289, 180, 161, 30));
        add_edge_status_label->setFont(font);
        del_edge_btn = new QPushButton(centralwidget);
        del_edge_btn->setObjectName("del_edge_btn");
        del_edge_btn->setGeometry(QRect(220, 220, 71, 30));
        BFS_name_label = new QLabel(centralwidget);
        BFS_name_label->setObjectName("BFS_name_label");
        BFS_name_label->setGeometry(QRect(180, 260, 81, 20));
        BFS_name_label->setFont(font1);
        BFS_info_label = new QLabel(centralwidget);
        BFS_info_label->setObjectName("BFS_info_label");
        BFS_info_label->setGeometry(QRect(50, 290, 125, 30));
        BFS_info_label->setFont(font);
        BFS_textEdit = new QTextEdit(centralwidget);
        BFS_textEdit->setObjectName("BFS_textEdit");
        BFS_textEdit->setGeometry(QRect(185, 290, 40, 30));
        BFS_textEdit->setFont(font);
        BFS_btn = new QPushButton(centralwidget);
        BFS_btn->setObjectName("BFS_btn");
        BFS_btn->setGeometry(QRect(50, 370, 101, 30));
        BFS_result_textBrowser = new QTextBrowser(centralwidget);
        BFS_result_textBrowser->setObjectName("BFS_result_textBrowser");
        BFS_result_textBrowser->setGeometry(QRect(50, 330, 341, 30));
        BFS_result_textBrowser->setFont(font);
        BFS_status_label = new QLabel(centralwidget);
        BFS_status_label->setObjectName("BFS_status_label");
        BFS_status_label->setGeometry(QRect(239, 290, 211, 30));
        BFS_status_label->setFont(font);
        DFS_btn = new QPushButton(centralwidget);
        DFS_btn->setObjectName("DFS_btn");
        DFS_btn->setGeometry(QRect(160, 370, 101, 30));
        DA_btn = new QPushButton(centralwidget);
        DA_btn->setObjectName("DA_btn");
        DA_btn->setGeometry(QRect(270, 370, 121, 30));
        example_graph_btn = new QPushButton(centralwidget);
        example_graph_btn->setObjectName("example_graph_btn");
        example_graph_btn->setGeometry(QRect(100, 610, 100, 25));
        example_graph_btn->setFont(font);
        example_graph_delete = new QPushButton(centralwidget);
        example_graph_delete->setObjectName("example_graph_delete");
        example_graph_delete->setGeometry(QRect(230, 610, 100, 25));
        example_graph_delete->setFont(font);
        TSP_info_label = new QLabel(centralwidget);
        TSP_info_label->setObjectName("TSP_info_label");
        TSP_info_label->setGeometry(QRect(50, 450, 125, 30));
        TSP_info_label->setFont(font);
        TSP_name_label = new QLabel(centralwidget);
        TSP_name_label->setObjectName("TSP_name_label");
        TSP_name_label->setGeometry(QRect(140, 420, 161, 20));
        TSP_name_label->setFont(font1);
        TSP_textEdit = new QTextEdit(centralwidget);
        TSP_textEdit->setObjectName("TSP_textEdit");
        TSP_textEdit->setGeometry(QRect(180, 450, 40, 30));
        TSP_textEdit->setFont(font);
        TSP_result_textBrowser = new QTextBrowser(centralwidget);
        TSP_result_textBrowser->setObjectName("TSP_result_textBrowser");
        TSP_result_textBrowser->setGeometry(QRect(50, 490, 341, 30));
        TSP_result_textBrowser->setFont(font);
        TSP_status_label = new QLabel(centralwidget);
        TSP_status_label->setObjectName("TSP_status_label");
        TSP_status_label->setGeometry(QRect(300, 450, 151, 30));
        TSP_status_label->setFont(font);
        TSP_btn = new QPushButton(centralwidget);
        TSP_btn->setObjectName("TSP_btn");
        TSP_btn->setGeometry(QRect(230, 450, 61, 30));
        TSP_result_textBrowser_2 = new QTextBrowser(centralwidget);
        TSP_result_textBrowser_2->setObjectName("TSP_result_textBrowser_2");
        TSP_result_textBrowser_2->setGeometry(QRect(50, 530, 341, 30));
        TSP_result_textBrowser_2->setFont(font);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1160, 25));
        menutravelingSalesman = new QMenu(menubar);
        menutravelingSalesman->setObjectName("menutravelingSalesman");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menutravelingSalesman->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "travelingSalesman", nullptr));
        add_ver_btn->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        add_ver_status_label->setText(QCoreApplication::translate("MainWindow", "\320\222\320\265\321\200\321\210\320\270\320\275: 0", nullptr));
        add_ver_name_label->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\320\275\320\270\320\265 / \320\243\320\264\320\260\320\273\320\265\320\275\320\270\320\265 \320\262\320\265\321\200\321\210\320\270\320\275\321\213", nullptr));
        add_ver_info_label->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\262\320\265\321\200\321\210\320\270\320\275\321\213 ", nullptr));
        del_ver_btn->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        add_edge_name_label->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265 (\320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\320\265) / \320\243\320\264\320\260\320\273\320\265\320\275\320\270\320\265 \321\200\320\265\320\261\321\200\320\260", nullptr));
        add_edge_f_label->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202", nullptr));
        add_edge_s_label->setText(QCoreApplication::translate("MainWindow", "\320\232", nullptr));
        add_edge_ves_label->setText(QCoreApplication::translate("MainWindow", "\320\222\320\265\321\201", nullptr));
        add_edge_btn->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        add_edge_status_label->setText(QString());
        del_edge_btn->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        BFS_name_label->setText(QCoreApplication::translate("MainWindow", "\320\220\320\273\320\263\320\276\321\200\320\270\321\202\320\274\321\213", nullptr));
        BFS_info_label->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\207\320\260\320\273\321\214\320\275\320\260\321\217 \320\262\320\265\321\200\321\210\320\270\320\275\320\260", nullptr));
        BFS_btn->setText(QCoreApplication::translate("MainWindow", "\320\236\320\261\321\205\320\276\320\264 \320\262 \321\210\320\270\321\200\320\270\320\275\321\203", nullptr));
        BFS_status_label->setText(QString());
        DFS_btn->setText(QCoreApplication::translate("MainWindow", "\320\236\320\261\321\205\320\276\320\264 \320\262 \320\263\320\273\321\203\320\261\320\270\320\275\321\203", nullptr));
        DA_btn->setText(QCoreApplication::translate("MainWindow", "\320\220\320\273\320\263\320\276\321\200\320\270\321\202\320\274 \320\224\320\265\320\271\320\272\321\201\321\202\321\200\321\213", nullptr));
        example_graph_btn->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\270\320\274\320\265\321\200 \320\263\321\200\320\260\321\204\320\260", nullptr));
        example_graph_delete->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\263\321\200\320\260\321\204", nullptr));
        TSP_info_label->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\207\320\260\320\273\321\214\320\275\320\260\321\217 \320\262\320\265\321\200\321\210\320\270\320\275\320\260", nullptr));
        TSP_name_label->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\264\320\260\321\207\320\260 \320\272\320\276\320\274\320\274\320\270\320\262\320\276\321\217\320\266\321\221\321\200\320\260", nullptr));
        TSP_status_label->setText(QString());
        TSP_btn->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\276\320\264", nullptr));
        menutravelingSalesman->setTitle(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
