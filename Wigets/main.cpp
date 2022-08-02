#include "mainwindow.h"

#include <QApplication>
#include "autorization.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Autorization avt;
    w.show();
    avt.show();
    return a.exec();
}
