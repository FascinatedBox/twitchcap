#include <QDialogButtonBox>
#include <QFormLayout>

#include "tcinfodialog.h"

TCInfoDialog::TCInfoDialog(QWidget *parent, TCSettings *settings)
    : QDialog(parent)
{
    _settings = settings;

    QFormLayout *layout = new QFormLayout;
    QDialogButtonBox *box = new QDialogButtonBox(
            QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
            parent
    );

    _userLine = new QLineEdit;
    _passLine = new QLineEdit;
    _channelLine = new QLineEdit;
    _membershipCheck = new QCheckBox;
    _tagsCheck = new QCheckBox;
    _commandsCheck = new QCheckBox;

    _userLine->setText(_settings->username());
    _passLine->setText(_settings->password());
    _channelLine->setText(_settings->channel());
    _commandsCheck->setChecked(_settings->commands());
    _membershipCheck->setChecked(_settings->membership());
    _tagsCheck->setChecked(_settings->tags());

    _passLine->setEchoMode(QLineEdit::Password);
    _passLine->setInputMethodHints(
            Qt::ImhHiddenText |
            Qt::ImhNoPredictiveText |
            Qt::ImhNoAutoUppercase
    );

    layout->insertRow(0, "Username:", _userLine);
    layout->insertRow(1, "Password:", _passLine);
    layout->insertRow(2, "Channel:", _channelLine);
    layout->insertRow(3, "Request membership", _membershipCheck);
    layout->insertRow(4, "Request tags", _tagsCheck);
    layout->insertRow(5, "Request commands", _commandsCheck);
    layout->addWidget(box);

    connect(box, &QDialogButtonBox::accepted,
            this, &TCInfoDialog::onAccepted);

    connect(box, &QDialogButtonBox::rejected,
            this, &QDialog::reject);

    setLayout(layout);
}

void TCInfoDialog::onAccepted()
{
    _settings->setUsername(_userLine->text().toLower());
    _settings->setPassword(_passLine->text().toLower());
    _settings->setChannel(_channelLine->text().toLower());
    _settings->setCommands(_commandsCheck->isChecked());
    _settings->setMembership(_membershipCheck->isChecked());
    _settings->setTags(_tagsCheck->isChecked());
    accept();
}
