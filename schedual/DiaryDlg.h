#ifndef DIARYDLG_H
#define DIARYDLG_H

#include <QtGui/QDialog>
#include <QTextCodec>
#include <QString>
#include <QListWidgetItem>
#include <QMessageBox>
#include <QtAlgorithms>
#include "ui_DiaryDlg.h"
#include "Account.h"
#include "Agenda.h"

class DiaryDlg : public QDialog
{
	Q_OBJECT

public:
	DiaryDlg(Account *acc,QWidget *parent = 0);
	~DiaryDlg();

	QString GetTime();
	QString GetTopic();
	QString GetDetail();
	void SetTime(QDate);
	void SetTopic(QString);
	void SetDetail(QString);
	void InitPanel();
	void GetData();

private slots: 
	void on_Add();
	void on_Midify();
	void on_Delete();
	void on_clicked_listWidget(QListWidgetItem *item);


private:
	Ui::DiaryDlg ui;
	QString ID,Date,Topic,Context;
	int numRows;
	int selectRows;
	int *Count;
	Account *acc;
};


#endif