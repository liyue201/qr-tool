#include "stdafx.h"
#include "KConfigFileManager.h"


KConfigFileManager::KConfigFileManager()
{
    QString confPath = qApp->applicationDirPath() + "/kexin_qr.ini";
    mpSetting = new QSettings(confPath, QSettings::IniFormat);
    mpSetting->setIniCodec(QTextCodec::codecForLocale());
}

KConfigFileManager::~KConfigFileManager()
{
    if (NULL != mpSetting){
        delete mpSetting;
        mpSetting = NULL;
    }
}

KConfigFileManager& KConfigFileManager::Instance()
{
    static KConfigFileManager ins;
    return ins;
}

QVariant KConfigFileManager::GetConfigValue(const QString& str) const
{
    return mpSetting->value(str);
}

void KConfigFileManager::SetConfigValue(const QString& str, int style)
{
    mpSetting->setValue(str, style);
}

void KConfigFileManager::SetConfigValue(const QString& str, const QString value)
{
    mpSetting->setValue(str, value);
}
