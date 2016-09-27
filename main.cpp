#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include <mmstream.h>
#include <stdlib.h>
#include <Digitalv.h>
#include "player.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
