#include "mainwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mainwidget w;
    w.setWindowState(Qt::WindowMaximized);
    w.show();

    return a.exec();
}
