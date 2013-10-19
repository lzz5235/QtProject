#ifndef QWR_H
#define QWR_H
#if defined(_MSC_VER) && (_MSC_VER >= 1600)
# pragma execution_character_set("utf-8")
#endif

#include<QtWebKit>
#include <QApplication>
#include <QtScript/QScriptValue>
#include <QtScript/QScriptEngine>
#include <QtNetwork>
#include <QMainWindow>
//#include <QtWidgets>
#include <QWebElement>
#include <QDomDocument>

#include <QSettings>
#include <QFile>
#include <QMap>


#include <QAction>
#include <QMenuBar>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QInputDialog>
#include <QMessageBox>
#include <QDate>
#include <QTimer>


class QVBoxLayout;
class QHBoxLayout;
class QTextEdit;
class QLabel;
class QLineEdit;
class QPushButton;
class QActionGroup;
class QTranslator;
class QLabel;
//-----------
class QMenu;

class CWeatherWidget : public QMainWindow 
{
    Q_OBJECT

public:
    CWeatherWidget();
    ~CWeatherWidget();

private slots:
	void slotNetworkIP();
	void slotBootStart();
	void switchCtiy();
	void showTime();
	void slotReadyRead();
	void slotWeatherInfo();
	void slotPublicNetworkIP();
	void slotPublicNetworkLocal(QString & str);
	void slotPublicNetworkLocal();
	QString FindCode();
	QString showPic(QString  *str);
	void InitPic();
// protected:
//     void resizeEvent ( QResizeEvent * event );
private:
	void Init();

private:

	QMenu* m_customSetMenu;
	QLabel* m_ctiyLabel;
	QLabel* m_dateLable;
	QLabel* m_timeLable;
	QPushButton* m_switchButtom;
	QLabel* m_picLable;
	QLabel* m_weatherPicLable;
	QLabel* m_tadayTLable;
	QLabel* m_curentWeatherLable;
	QLabel* m_humidityLable;
	QLabel* m_windLable;
	QLabel* m_currentWeatherLable;
	QLabel* m_threeWeatherLable;
	QString m_strCityName;
	QString m_nerworkIP;
	QString m_strLocal;
	QString m_NumLocal;
	QString strNetworkInfo;

	QMap<QString,QString> m_map;


    //network
    QNetworkAccessManager *m_NetworkManager;
    QNetworkRequest m_NetworkRequest;
    QNetworkReply *m_NetworkReply;
	QNetworkReply *m_NetworkReplyIP;
	QWebFrame *frame;
	
};

#endif // QWR_H
