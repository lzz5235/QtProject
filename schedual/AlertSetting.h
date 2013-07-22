#ifndef ALERTSETTING_H
#define ALERTSETTING_H

#include <QtGui>
#include <QDialog>
#include <QTableWidgetItem>
#include <QListWidget>
#include <QMessageBox>
#include <QTextCodec>
#include <QMenu>
#include "ui_AlertSetting.h"
#include "Account.h"


class AlertSetting :public QDialog
{
	Q_OBJECT

public:
	AlertSetting(Account *acc,QWidget *parent = 0);
	~AlertSetting();

	QString GetTime();
	QString GetTopic();
	QString GetDetail();
	void SetTime(QDate);
	void SetTopic(QString);
	void SetDetail(QString);
	void SetNoteText();
	void InitPanel();

	void GetData();
	void DayAlertSetting();

private slots: 
	void on_Add();
	void on_Modify();
	void on_Delete();
	void on_DeleteAll();
	void on_clicked_listWidget(QTableWidgetItem *);
	void on_clicked_listWidget_Right(const QPoint &);

private:
	Ui::AlertSetting ui;
	QSqlDatabase db;
	QString ID,Date,Topic,Detail;
	QString Today;
	int numRows;
	int selectRows;
	QAction *AddAction;
	QAction *ModifyAction;
	QAction *DeleteAction;
	Account *acc;
};

#endif // ALERTSETTING_H