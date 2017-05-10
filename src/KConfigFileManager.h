#ifndef _KCONFIGFILEMANGER_H_
#define _KCONFIGFILEMANGER_H_

class KConfigFileManager
{
 private:
    KConfigFileManager();
    ~KConfigFileManager();
 
public:
    static  KConfigFileManager& Instance();

    QVariant GetConfigValue(const QString& str) const;
    void SetConfigValue(const QString& str, int style);
    void SetConfigValue(const QString& str, const QString value);

private:
    QSettings* mpSetting;
};

#endif