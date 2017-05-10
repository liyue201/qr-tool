#include <QApplication>
#include "KMainWindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QTranslator appTranslator;

    if (appTranslator.load(qApp->applicationDirPath() + "/kexin_qr_zh_CN.qm"))
    {
        app.installTranslator(&appTranslator);
        QTranslator* qtTranslator = new QTranslator(&app);
        if (qtTranslator->load(qApp->applicationDirPath() + "/qt_zh_CN.qm"))
        {
            app.installTranslator(qtTranslator);
        }
    }

    KMainWindow window;
    window.show();
    return app.exec();
}


