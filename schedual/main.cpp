#include "schedual.h"
#include "Login.h"
#include "Account.h"
#include <QtGui/QApplication>
#include <QSplashScreen>
#include <QTest>

void splashScreen();
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	//splashScreen();
	Login loginDlg;
	loginDlg.show();
	if(loginDlg.exec()==QDialog::Accepted)
	{
		loginDlg.hide();
		Account *acc = new Account();
		Schedual *schDlg = new Schedual(acc);
		schDlg->show();
	}
	else
	{
		loginDlg.close();
	}
	return a.exec();
}
void splashScreen()
{
	QSplashScreen *splash = new QSplashScreen;  
    splash->setPixmap(QPixmap("./image/splash.jpg"));  
    splash->show();
	Qt::Alignment topRight = Qt::AlignRight | Qt::AlignTop;  
    splash->showMessage(QObject::tr("Setting up the Login Window..."),  
                        topRight,  
                        Qt::red);
	QTest::qSleep(3000);
	splash->showMessage(QObject::tr("Loading modules..."),  
                        topRight,  
                        Qt::blue);  
    QTest::qSleep(3000);  
	delete splash;
}