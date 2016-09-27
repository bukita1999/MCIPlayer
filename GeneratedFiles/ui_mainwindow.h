/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QSlider>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QToolButton *loadFileButton;
    QListWidget *listWidget;
    QToolButton *playButton;
    QToolButton *modeBotton;
    QToolButton *preButton;
    QToolButton *nextButton;
    QSlider *progresslSlider;
    QLabel *currentTimeLabel;
    QLabel *totalTImeLabel;
    QToolButton *volumnButton;
    QToolButton *removeFileButton;
    QToolButton *upButton;
    QToolButton *downButton;
    QToolButton *stopButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 480);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        MainWindow->setFont(font);
        QIcon icon;
        QString iconThemeName = QStringLiteral("mytheme");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QStringLiteral(":/images/icon.png"), QSize(), QIcon::Normal, QIcon::On);
        }
        MainWindow->setWindowIcon(icon);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        loadFileButton = new QToolButton(centralWidget);
        loadFileButton->setObjectName(QStringLiteral("loadFileButton"));
        loadFileButton->setGeometry(QRect(30, 30, 80, 40));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(13, 127, 217, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush2(QColor(255, 255, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QBrush brush3(QColor(120, 120, 120, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        loadFileButton->setPalette(palette);
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setWeight(75);
        loadFileButton->setFont(font1);
        loadFileButton->setStyleSheet(QLatin1String("background-color: rgb(13, 127, 217);\n"
"border:none;"));
        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(30, 90, 731, 330));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(false);
        font2.setWeight(50);
        listWidget->setFont(font2);
        listWidget->setFlow(QListView::TopToBottom);
        listWidget->setLayoutMode(QListView::SinglePass);
        listWidget->setViewMode(QListView::ListMode);
        playButton = new QToolButton(centralWidget);
        playButton->setObjectName(QStringLiteral("playButton"));
        playButton->setGeometry(QRect(651, 425, 50, 50));
        modeBotton = new QToolButton(centralWidget);
        modeBotton->setObjectName(QStringLiteral("modeBotton"));
        modeBotton->setGeometry(QRect(531, 425, 50, 50));
        QIcon icon1;
        iconThemeName = QStringLiteral("mytheme");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon1 = QIcon::fromTheme(iconThemeName);
        } else {
            icon1.addFile(QStringLiteral("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        modeBotton->setIcon(icon1);
        preButton = new QToolButton(centralWidget);
        preButton->setObjectName(QStringLiteral("preButton"));
        preButton->setGeometry(QRect(591, 425, 50, 50));
        preButton->setIcon(icon1);
        nextButton = new QToolButton(centralWidget);
        nextButton->setObjectName(QStringLiteral("nextButton"));
        nextButton->setGeometry(QRect(711, 425, 50, 50));
        nextButton->setIcon(icon1);
        progresslSlider = new QSlider(centralWidget);
        progresslSlider->setObjectName(QStringLiteral("progresslSlider"));
        progresslSlider->setGeometry(QRect(70, 440, 331, 22));
        progresslSlider->setOrientation(Qt::Horizontal);
        currentTimeLabel = new QLabel(centralWidget);
        currentTimeLabel->setObjectName(QStringLiteral("currentTimeLabel"));
        currentTimeLabel->setGeometry(QRect(30, 442, 41, 16));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        currentTimeLabel->setPalette(palette1);
        QFont font3;
        font3.setPointSize(10);
        currentTimeLabel->setFont(font3);
        totalTImeLabel = new QLabel(centralWidget);
        totalTImeLabel->setObjectName(QStringLiteral("totalTImeLabel"));
        totalTImeLabel->setGeometry(QRect(410, 442, 41, 16));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        totalTImeLabel->setPalette(palette2);
        totalTImeLabel->setFont(font3);
        volumnButton = new QToolButton(centralWidget);
        volumnButton->setObjectName(QStringLiteral("volumnButton"));
        volumnButton->setGeometry(QRect(493, 431, 30, 30));
        removeFileButton = new QToolButton(centralWidget);
        removeFileButton->setObjectName(QStringLiteral("removeFileButton"));
        removeFileButton->setGeometry(QRect(120, 30, 51, 40));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        removeFileButton->setPalette(palette3);
        removeFileButton->setFont(font1);
        removeFileButton->setStyleSheet(QLatin1String("background-color: rgb(13, 127, 217);\n"
"border:none;"));
        upButton = new QToolButton(centralWidget);
        upButton->setObjectName(QStringLiteral("upButton"));
        upButton->setGeometry(QRect(180, 50, 20, 20));
        downButton = new QToolButton(centralWidget);
        downButton->setObjectName(QStringLiteral("downButton"));
        downButton->setGeometry(QRect(205, 50, 20, 20));
        stopButton = new QToolButton(centralWidget);
        stopButton->setObjectName(QStringLiteral("stopButton"));
        stopButton->setGeometry(QRect(456, 436, 30, 30));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MCIPlayer", 0));
        loadFileButton->setText(QApplication::translate("MainWindow", "\345\257\274\345\205\245\346\255\214\346\233\262", 0));
        playButton->setText(QString());
        modeBotton->setText(QApplication::translate("MainWindow", "...", 0));
        preButton->setText(QApplication::translate("MainWindow", "...", 0));
        nextButton->setText(QApplication::translate("MainWindow", "...", 0));
        currentTimeLabel->setText(QApplication::translate("MainWindow", "00:00", 0));
        totalTImeLabel->setText(QApplication::translate("MainWindow", "00:00", 0));
        volumnButton->setText(QString());
        removeFileButton->setText(QApplication::translate("MainWindow", "\347\247\273\351\231\244", 0));
        upButton->setText(QString());
        downButton->setText(QString());
        stopButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
