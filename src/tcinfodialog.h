#ifndef TCINFODIALOG_H
# define TCINFODIALOG_H
# include <QCheckBox>
# include <QDialog>
# include <QLineEdit>

# include "tcsettings.h"

class TCInfoDialog : public QDialog
{
    Q_OBJECT

public:
    TCInfoDialog(QWidget *parent, TCSettings *);

private slots:
    void onAccepted();

private:
    TCSettings *_settings;
    QLineEdit *_userLine;
    QLineEdit *_passLine;
    QLineEdit *_channelLine;
    QCheckBox *_commandsCheck;
    QCheckBox *_membershipCheck;
    QCheckBox *_tagsCheck;
};

#endif
