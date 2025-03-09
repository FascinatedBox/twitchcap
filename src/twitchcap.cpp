#include <QApplication>
#include "tcmainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    TCMainWindow w;

    w.start();
    return app.exec();
}
