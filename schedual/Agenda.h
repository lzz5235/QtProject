#pragma once
#include <QString>

class Agenda
{
private:
	QString m_ID;
	QString m_date;
	QString m_topic;
	QString m_context;
	QString m_Name,m_Num1,m_Num2,m_Email,m_Others,m_Pic;

public:
	Agenda(void);
	QString GetID();
	QString GetDate();
	QString GetTopic();
	QString GetContext();
	QString GetName();
	QString GetNum1();
	QString GetNum2();
	QString GetEmail();
	QString GetOther();
	QString GetPic();
	void SetDate(QString Date);
	void SetTopic(QString Topic);
	void SetContext(QString Context);
	void SetName(QString Name);
	void SetNum1(QString Num1);
	void SetNum2(QString Num2);
	void SetEmail(QString Email);
	void SetOther(QString Others);
	void SetPic(QString Pic);
	Agenda(QString date, QString topic, QString context);
	Agenda(QString Name, QString Num1, QString Num2,QString Email,QString Others,QString Pic);
	~Agenda(void);
};
