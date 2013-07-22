#ifndef TELEBOOKDLG_H
#define TELEBOOKDLG_H

#include <QtGui/QDialog>
#include <QTextCodec>
#include <QString>
#include <QListWidgetItem>
#include <QMessageBox>
#include <QPalette>
#include <QFileDialog>
#include <QRegExp>
#include <QSettings>
#include "ui_TeleBook.h"
#include "Account.h"
#define MaxLen 50


class TeleBookDlg : public QDialog
{
	Q_OBJECT

public:
	TeleBookDlg(Account *acc,QWidget *parent = 0);
	~TeleBookDlg();

	QString GetName();
	QString GetPhoneNumber1();
	QString GetPhoneNumber2();
	QString GetEmail();
	QString GetOthers();
	QString GetPic();

	void SetName(QString);
	void SetPhoneNumber(QString,QString);
	void SetEmail(QString);
	void SetOthers(QString);
	void SetPic(QString);
	void InitPanel();

	void GetData();

private slots: 
	void on_Add();
	void on_Delete();
	void on_AddPhoto();
	void on_clicked_listWidget(QListWidgetItem *item);


private:
	Ui::TeleBook ui;
	int selectRows;
	QString Photo;
	QPalette palette;
	QFileInfo* fileinfo;
	QSettings *ConfigIni;
	QString Path;
	Account *acc;
};


#endif