#ifndef TCMAINWINDOW_H
# define TCMAINWINDOW_H
# include <QLineEdit>
# include <QMainWindow>
# include <QTextBrowser>

# include "tcconnection.h"
# include "tcsettings.h"

class TCMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    TCMainWindow();

    void start();

private slots:
    void onLineReturnPress();
    void onSocketNotice(QString);
    void onSocketSend(QString);
    void onSocketRecv(QString);

private:
    void showInfoDialog();

    TCConnection *_connection;
    TCSettings *_settings;
    QTextBrowser *_recvBrowser;
    QLineEdit *_sendLine;
};

#endif
