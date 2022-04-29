#ifndef TCSETTINGS_H
# define TCSETTINGS_H
# include <QJsonObject>

#define SETTER_FN(fieldname, v) \
{ \
    if (fieldname != v) \
        _updated = true; \
\
    fieldname = v; \
}

class TCSettings : public QObject
{
    Q_OBJECT

public:
    TCSettings();

    static TCSettings *loadSettings();
    void saveSettings();

    QString channel() { return _channel; }
    QString password() { return _password; }
    QString username() { return _username; }
    bool commands() { return _commands; }
    bool membership() { return _membership; }
    bool tags() { return _tags; }

    void setChannel(QString c) { SETTER_FN(_channel, c); }
    void setPassword(QString p) { SETTER_FN(_password, p); }
    void setUsername(QString u) { SETTER_FN(_username, u); }
    void setCommands(bool c) { SETTER_FN(_commands, c); }
    void setMembership(bool m) { SETTER_FN(_membership, m); }
    void setTags(bool t) { SETTER_FN(_tags, t); }

private:
    void buildSettingsObject(QJsonObject &);

    QString _channel;
    QString _password;
    QString _username;
    bool _commands;
    bool _membership;
    bool _tags;
    bool _updated;
};

#endif
