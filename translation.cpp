#include "translation.h"

Translation::Translation( QGuiApplication *app, QObject *parent)
    : QObject(parent)
{
}

QString Translation::getEmptyString()
{
}

QString Translation::currentLanguage()
{
}

void Translation::setCurrentLanguage(QString language)
{
}

void Translation::selectLanguage(QString language)
{
}
