#include <QApplication>
#include <QTextCodec>
#include "weather.h"

#if QT_VERSION < QT_VERSION_CHECK(5,0,0)
    #if defined(_MSC_VER) && (_MSC_VER < 1600)

        QTextCodec::setCodecForTr(QTextCodec::codecForName("GB2312"));
    #else
        QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    #endif
#endif
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    CWeatherWidget weather;
    weather.show();

    return app.exec();
}
