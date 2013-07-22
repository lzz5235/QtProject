#ifndef LOGIN_H
#define LOGIN_H

#include <QtGui/QDialog>
#include <QPixmap>
#include <QPalette>
#include <QString>
#include <QSettings>
#include "ui_Login.h"


class Login : public QDialog
{
	Q_OBJECT

public:
	Login(QWidget *parent = 0);
	~Login();

private slots: 
	void on_login();
	void on_cancel();
	void on_New();


private:
	Ui::login ui;
	QPalette palette;
	QSettings *ConfigIni;
	QString	UserName,UserPasswd;
	QString RealName,RealPasswd;

	void SetbgPic();
	void WriteConfig();
	void ReadConfig();

	void encode(QString *data);
	/* �����ļ� ��ÿ���ַ�����1 */  
	void decode(QString *data);
	/* �����ļ� ��ÿ���ַ���1 */  
};

#endif // LOGIN_H