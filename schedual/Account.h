#pragma once
#include "Agenda.h"
#include <QVector>
#include <QString>
#include <QSqlQuery>
#include <QtSql>
#include <QSqlDatabase>
#include <QTextCodec>
#include <QMessageBox>



class Account
{
private:
	QVector<Agenda> agendaDiaryList;
	QVector<Agenda> agendaSchedualList;
	QVector<Agenda> agendaPhoneList;
	QVector<Agenda>::iterator iter;

	QSqlDatabase db;

public:
	Account(void);
	~Account(void);
	friend class AlertSetting;
	friend class DiaryDlg;
	friend class TeleBookDlg;
	friend class Schedual;

	bool ConnectDB();
	bool CloseDB();

	bool GetDiaryData();
	bool AddDiaryAgenda(QString date, QString topic, QString context,int Row);
	bool DeleteDiaryAgenda(int Row);
    bool ModifyDiaryAgenda(QString date, QString topic, QString context,int Row);
	
	bool GetSchedualData();
	bool AddSchedualAgenda(QString date, QString topic, QString context,int Row);
	bool DeleteSchedualAgenda(int Row);
	bool DeleteAllAgenda();
	bool ModifySchedualAgenda(QString date, QString topic, QString context,int Row);

	bool GetPhoneData();
	bool DeletePhoneAgenda(int Row);
	bool AddPhoneAgenda(QString Name, QString Num1, QString Num2,QString Email,QString Others,QString Pic);
	
	
	void AddCommonAgenda(QString date, QString topic, QString context,int Type);
	void AddCommonAgenda(QString Name, QString Num1, QString Num2,QString Email,QString Others,QString Pic);
	QVector<Agenda>& ReturnVector(int type);//1  Diary   2 Scheadual   3  Phone
	
};
