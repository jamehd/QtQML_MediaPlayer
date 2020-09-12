#include "translation.h"

Translation::Translation( QGuiApplication *app, QObject *parent)
    : QObject(parent)
{
    Q_UNUSED(app);
    m_currentLanguage = "US";
}

QString Translation::getEmptyString()
{
    return QString("");
}

QString Translation::currentLanguage()
{
    return m_currentLanguage;
}

void Translation::setCurrentLanguage(QString language)
{
    if (language != m_currentLanguage) {
        m_currentLanguage = language;
        emit currentLanguageChanged();
    }
}

void Translation::selectLanguage(QString language)
{
    if (language != m_currentLanguage) {
        m_currentLanguage = language;
        emit currentLanguageChanged();
    }
}
