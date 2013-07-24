#include <QApplication>
#include <QTextCodec>
#include "weather.h"

int main(int argc, char *argv[])
{
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));
	QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GBK"));
	QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));

    QApplication app(argc, argv);

    CWeatherWidget weather;
    weather.show();

    return app.exec();
}
