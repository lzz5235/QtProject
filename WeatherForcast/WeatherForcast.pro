#-------------------------------------------------
#
# Project created by QtCreator 2013-10-15T22:17:55
#
#-------------------------------------------------

QT       += script
QT       += widgets
QT       += network xml
QT       += webkit


greaterThan(QT_MAJOR_VERSION, 4): QT +=

TARGET = WeatherForcast
TEMPLATE = app


SOURCES += main.cpp\
        weather.cpp

HEADERS  += weather.h

FORMS    += weather.ui

OTHER_FILES += \
    images/weathercity.code.txt \
    images/thunderstorm.gif \
    images/sunny.gif \
    images/storm.gif \
    images/snow.gif \
    images/smoke.gif \
    images/sleet.gif \
    images/rain.gif \
    images/partly_cloudy.gif \
    images/mostly_sunny.gif \
    images/mostly_cloudy.gif \
    images/mist.gif \
    images/icy.gif \
    images/haze.gif \
    images/fog.gif \
    images/flurries.gif \
    images/dust.gif \
    images/cloudy.gif \
    images/chance_of_tstorm.gif \
    images/chance_of_storm.gif \
    images/chance_of_snow.gif \
    images/chance_of_rain.gif
