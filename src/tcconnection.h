#ifndef TCCONNECTION_H
# define TCCONNECTION_H
# include <QTcpSocket>

# include "tcsettings.h"

class TCConnection : public QObject
{
    Q_OBJECT

public:
    TCConnection(TCSettings *);

public:
    void sendMessage(QString);
    void startConnect();

signals:
    void socketNotice(QString);
    void socketRecv(QString);
    void socketSend(QString);

private slots:
    void onReadyRead();

private:
    void write(QByteArray);

    TCSettings *_settings;
    QTcpSocket *_socket;
    QByteArray _channel;
};

#endif
