#include "tcconnection.h"

TCConnection::TCConnection(TCSettings *settings)
{
    _settings = settings;
    _socket = new QTcpSocket;

    connect(_socket, &QIODevice::readyRead,
            this, &TCConnection::onReadyRead);
}

void TCConnection::write(QByteArray ba)
{
    _socket->write(ba + "\n");
    emit socketSend(ba);
}

void TCConnection::onReadyRead()
{
    do {
        QString data = _socket->readLine();

        emit socketRecv(data);

        if (data.startsWith(QString("PING :tmi.twitch.tv")))
            write("PONG :tmi.twitch.tv");
    } while (_socket->canReadLine());
}

void TCConnection::startConnect()
{
    QString serverName = "irc.chat.twitch.tv";

    _channel = _settings->channel().toLocal8Bit();
    QByteArray password = _settings->password().toLocal8Bit();
    QByteArray username = _settings->username().toLocal8Bit();

    _socket->connectToHost(serverName, 6667);

    if (_socket->waitForConnected() == false) {
        emit socketNotice("Waiting for connection failed.");
        return;
    }

    emit socketNotice("Connection established.");
    _socket->write("PASS oauth:" + password + "\n");
    emit socketSend("PASS oauth:***");
    write("NICK " + username);
    write("JOIN #" + _channel);

    if (_settings->tags())
        write("CAP REQ :twitch.tv/tags");

    if (_settings->membership())
        write("CAP REQ :twitch.tv/membership");

    if (_settings->commands())
        write("CAP REQ :twitch.tv/commands");
}

void TCConnection::sendMessage(QString m)
{
    write("PRIVMSG #" + _channel + " :" + m.toLocal8Bit());
}
