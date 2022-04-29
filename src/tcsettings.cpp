#include <QDir>
#include <QFile>
#include <QJsonDocument>

#include "tcsettings.h"

#define TWITCHCAP_DIR ".config/twitchcap/"
#define TWITCHCAP_JSON_PATH (QDir::homePath() + ("/" TWITCHCAP_DIR "twitchcap.json"))

TCSettings::TCSettings()
{
    _updated = false;
}

TCSettings *TCSettings::loadSettings()
{
    QFile f(TWITCHCAP_JSON_PATH);

    if (f.open(QIODevice::ReadOnly) == false)
        return new TCSettings;

    QByteArray ba = f.readAll();
    QJsonDocument d(QJsonDocument::fromJson(ba));
    QJsonObject o = d.object();

    TCSettings *s = new TCSettings;

    s->_channel = o["channel"].toString("");
    s->_password = o["password"].toString("");
    s->_username = o["username"].toString("");
    s->_commands = o["commands"].toBool(false);
    s->_membership = o["membership"].toBool(false);
    s->_tags = o["tags"].toBool(false);

    f.close();
    return s;
}

void TCSettings::buildSettingsObject(QJsonObject &o)
{
    o["channel"] = _channel;
    o["password"] = _password;
    o["username"] = _username;
    o["commands"] = _commands;
    o["membership"] = _membership;
    o["tags"] = _tags;
}

void TCSettings::saveSettings()
{
    if (_updated == false)
        return;

    QFile f(TWITCHCAP_JSON_PATH);

    if (f.open(QIODevice::WriteOnly) == false) {
        /* Maybe the config dir hasn't been made yet. */
        QDir configDir = QDir(QDir::homePath());

        if (configDir.exists(TWITCHCAP_DIR) == true ||
            configDir.mkdir(TWITCHCAP_DIR) == false ||
            f.open(QIODevice::WriteOnly) == false)
            /* Out of ideas. Give up on saving prefs. */
            return;
    }

    QJsonObject o;

    buildSettingsObject(o);
    f.write(QJsonDocument(o).toJson());
    f.close();
}
