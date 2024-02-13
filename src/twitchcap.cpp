#include <QApplication>
#include <QFile>

#include "tcmainwindow.h"

QString loadFile(QString path)
{
    QFile f(path);
    f.open(QIODevice::ReadOnly);
    QString s = f.readAll();
    f.close();

    return s;
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    TCMainWindow w;

    w.setStyleSheet(loadFile(":/style.qss"));
    w.start();
    return app.exec();
}
