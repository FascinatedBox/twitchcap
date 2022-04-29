#include <QApplication>
#include <QDesktopWidget>
#include <QVBoxLayout>

#include "tcinfodialog.h"
#include "tcmainwindow.h"

void centerWidget(QWidget *w)
{
    QRect geometry = QApplication::desktop()->screenGeometry();
    int x = (geometry.width() - w->width()) / 2;
    int y = (geometry.height() - w->height()) / 2;
    w->move(x, y);
}

TCMainWindow::TCMainWindow()
{
    _settings = TCSettings::loadSettings();
    _connection = new TCConnection(_settings);
    _recvBrowser = new QTextBrowser;
    _sendLine = new QLineEdit;

    QWidget *w = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(_recvBrowser);
    layout->addWidget(_sendLine);
    w->setLayout(layout);

    setCentralWidget(w);
    setWindowTitle("TwitchCap");

    connect(_connection, &TCConnection::socketNotice,
            this, &TCMainWindow::onSocketNotice);

    connect(_connection, &TCConnection::socketRecv,
            this, &TCMainWindow::onSocketRecv);

    connect(_connection, &TCConnection::socketSend,
            this, &TCMainWindow::onSocketSend);

    connect(_sendLine, &QLineEdit::returnPressed,
            this, &TCMainWindow::onLineReturnPress);
}

void TCMainWindow::onSocketRecv(QString s)
{
    _recvBrowser->append("> " + s.trimmed());
}

void TCMainWindow::onSocketSend(QString s)
{
    _recvBrowser->append("<<< " + s);
}

void TCMainWindow::onSocketNotice(QString s)
{
    _recvBrowser->append("* " + s);
}

void TCMainWindow::onLineReturnPress()
{
    _connection->sendMessage(_sendLine->text());
    _sendLine->clear();
}

void TCMainWindow::showInfoDialog()
{
    TCInfoDialog *dialog = new TCInfoDialog(this, _settings);

    dialog->setMinimumWidth(300);
    centerWidget(dialog);
    dialog->setMinimumWidth(0);

    if (dialog->exec() == QDialog::Rejected)
        exit(EXIT_FAILURE);

    _settings->saveSettings();
    delete dialog;
}

void TCMainWindow::start()
{
    show();
    setMinimumWidth(600);
    setMinimumWidth(0);
    centerWidget(this);
    showInfoDialog();
    _connection->startConnect();
}
