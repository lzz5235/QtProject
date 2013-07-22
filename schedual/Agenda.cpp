#include "Agenda.h"

Agenda::Agenda(void)
{
}
Agenda::Agenda(QString date, QString topic, QString context)
{
	m_date = date;
	m_topic = topic;
	m_context = context;
}
Agenda::Agenda(QString Name, QString Num1, QString Num2,QString Email,QString Others,QString Pic)
{
	m_Name = Name;
	m_Num1 = Num1;
	m_Num2 = Num2;
	m_Email = Email;
	m_Others = Others;
	m_Pic = Pic;
}
QString Agenda::GetID()
{
	return m_ID;
}
QString Agenda::GetDate()
{
	return m_date;
}
QString Agenda::GetTopic()
{
	return m_topic;
}
QString Agenda::GetContext()
{
	return m_context;
}
QString Agenda::GetName()
{
	return m_Name;
}
QString Agenda::GetNum1()
{
	return m_Num1;
}
QString Agenda::GetNum2()
{
	return m_Num2;
}
QString Agenda::GetEmail()
{
	return m_Email;
}
QString Agenda::GetOther()
{
	return m_Others;
}
QString Agenda::GetPic()
{
	return m_Pic;
}
void Agenda::SetDate(QString Date)
{
	m_date = Date;
}
void Agenda::SetTopic(QString Topic)
{
	m_topic = Topic;
}
void Agenda::SetContext(QString Context)
{
	m_context = Context;
}
void Agenda::SetName(QString Name)
{
	m_Name = Name;
}
void Agenda::SetNum1(QString Num1)
{
	m_Num1 = Num1;
}
void Agenda::SetNum2(QString Num2)
{
	m_Num2 = Num2;
}
void Agenda::SetEmail(QString Email)
{
	m_Email = Email;
}
void Agenda::SetOther(QString Others)
{
	m_Others = Others;
}
void Agenda::SetPic(QString Pic)
{
	m_Pic = Pic;
}
Agenda::~Agenda(void)
{
}
