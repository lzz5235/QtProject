#include "Account.h"

Account::Account(void)
{
	ConnectDB();
	
	GetSchedualData();
	GetPhoneData();
	GetDiaryData();
}

Account::~Account(void)
{
	CloseDB();
}
bool Account::ConnectDB()
{
	db =  QSqlDatabase::addDatabase("QODBC");
	QString dsn = QString::fromLocal8Bit("ADOMySQL");
	//db.setConnectOptions("SQL_ATTR_ODBC_VERSION=SQL_OV_ODBC3");
    //QString dsn = QString("DRIVER={Microsoft Access Driver (*.mdb,*.accdb)};FIL={MS Access};DBQ=C:/schedual.accdb;");
	//"Driver={mysql};database=yourdatabase;uid=username;pwd=yourpassword;option=16386;"
	db.setDatabaseName(dsn);
	db.setHostName("localhost");
	//db.setDatabaseName("schedual"); // ����֮ǰ���������ݿ�
	db.setUserName("root"); // ���Ǵ����� root �û���
	db.setPassword("root"); // root �û�������
	bool Value = db.open(); // �����������ݿ�

	if(Value==0)
	{
		return 0;
		//QMessageBox::warning(this,tr("Cannot open database."),db.lastError().databaseText(),QMessageBox::Yes);		
	}            // �����ݿ�ʧ�ܣ���ʾ���ݿⷵ�ص�ʧ������
	return 1;
		
}
bool Account::CloseDB()
{
	db.close();
	return 0;
}


void Account::AddCommonAgenda(QString date, QString topic, QString context,int Type)
{
	Agenda agenda(date, topic, context);
	if(Type==1)
		agendaSchedualList.push_back(agenda);
	else
		agendaDiaryList.push_back(agenda);
	return;
}
void Account::AddCommonAgenda(QString Name, QString Num1, QString Num2,QString Email,QString Others,QString Pic)
{
	Agenda agenda(Name,Num1,Num2,Email,Others,Pic);
	agendaPhoneList.push_back(agenda);
}
bool Account::AddPhoneAgenda(QString Name, QString Num1, QString Num2,QString Email,QString Others,QString Pic)
{
	QSqlQuery query; 
	QString sql = "insert teleBook(Name,TelePhone1,TelePhone2,Email,others,Pic) values ('"+Name+"','"+Num1+"','"+Num2+"','"+Email+"','"+Others+"','"+Pic+"')";
	query.exec(sql);
	Agenda agenda(Name,Num1,Num2,Email,Others,Pic);
	agendaPhoneList.push_back(agenda);
	return 1;
}
bool Account::GetPhoneData()
{
	QSqlQuery query;   // �½�һ����ѯ��ʵ��
	if(query.exec("select * from TeleBook"))
	{			
		while(query.next()){ // ��λ�������һ����¼
			AddCommonAgenda(query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),
				query.value(4).toString(),query.value(5).toString(),query.value(6).toString());
		}
	}
	else
	{
		return 0;
		//QMessageBox::warning(this,tr("cannot GetData."),query.lastError().databaseText(),QMessageBox::Yes);// �����ѯʧ�ܣ�������ķ����õ��������ݿⷵ�ص�ԭ��
		query.clear();
	}	
	return 1;
}
bool Account::DeletePhoneAgenda(int Row)
{
	QSqlQuery query;
	QString sql = "delete  from teleBook where Name = '"+this->ReturnVector(3)[Row].GetName()+"'";
	if(!query.exec(sql))	return 0;
	iter = ReturnVector(3).begin();
	ReturnVector(3).erase(iter+Row);
	return 1;
}
QVector<Agenda>& Account::ReturnVector(int type)
{
	if(type==1)
		return agendaDiaryList;
	else if(type==2)
		return agendaSchedualList;
	else
		return agendaPhoneList;
}

bool Account::ModifyDiaryAgenda(QString date, QString topic, QString context,int Row)
{
	QSqlQuery query;
	QString sql = "update diary set  DiaryTime='"+date+"',DiaryTopic='"+topic+"',DiaryContext = '"+context+"' where DiaryContext = '"+ this->ReturnVector(1)[Row].GetContext() + "'";
	if(!query.exec(sql))	return 0;
	ReturnVector(1)[Row].SetDate(date);
	ReturnVector(1)[Row].SetTopic(topic);
	ReturnVector(1)[Row].SetContext(context);
	return 1;
}
bool Account::AddDiaryAgenda(QString date, QString topic, QString context,int Row)
{
	QSqlQuery query; 
	QString sql = "insert into Diary(DiaryTime,DiaryTopic,DiaryContext) values ('"+date+"','"+topic+"','"+context+"')";
	if(!query.exec(sql))	return 0;
	AddCommonAgenda(date,topic,context,2);
	return 1;
}
bool Account::GetDiaryData()
{
	// �����Ѿ��ɹ��������ݿ�
	QSqlQuery query;   // �½�һ����ѯ��ʵ��
	if(query.exec("select * from Diary"))
	{			
		while(query.next())
		{ // ��λ�������һ����¼
			this->AddCommonAgenda(query.value(1).toString(),QString::fromLocal8Bit(query.value(2).toByteArray()),QString::fromLocal8Bit(query.value(3).toByteArray()),2);
		}
	}
	else
	{
		return 0;
		query.clear();
	}
	return 1;
}
bool Account::DeleteDiaryAgenda(int Row)
{
	QSqlQuery query;
	QString sql = "delete  from diary where DiaryContext = '"+this->ReturnVector(1)[Row].GetContext()+"'";
	if(!query.exec(sql))	return 0;
	iter = ReturnVector(1).begin();
	ReturnVector(1).erase(iter+Row);
	return 1;
}

bool Account::GetSchedualData()
{
	QSqlQuery query;  
	if(query.exec("select * from note"))
	{			
		while(query.next()){ // ��λ�������һ����¼
			this->AddCommonAgenda(query.value(1).toString(),QString::fromLocal8Bit(query.value(2).toByteArray()),QString::fromLocal8Bit(query.value(3).toByteArray()),1);
		}
	}
	else
	{
		return 0;
		query.clear();
	}
	return 1;
}
bool Account::AddSchedualAgenda(QString date, QString topic, QString context,int Rows)
{
	QSqlQuery query; 
	QString sql = "insert into note(Time,Topic,Detail) values ('"+date+"','"+topic+"','"+context+"')";
	if(!query.exec(sql))	return 0;
	AddCommonAgenda(date,topic,context,1);
	return 1;
}
bool Account::ModifySchedualAgenda(QString date, QString topic, QString context,int Row)
{
	QSqlQuery query;
	QString sql = "update note set  Time='"+date+"',Topic='"+topic+"',Detail = '"+context+"' where Detail = '"+ this->ReturnVector(2)[Row].GetContext() + "'";
	if(!query.exec(sql))	return 0;
	ReturnVector(2)[Row].SetDate(date);
	ReturnVector(2)[Row].SetTopic(topic);
	ReturnVector(2)[Row].SetContext(context);
	return 1;
}
bool Account::DeleteSchedualAgenda(int Row)
{
	QSqlQuery query;
	QString sql = "delete  from note where Detail = '"+this->ReturnVector(2)[Row].GetContext()+"'";
	if(!query.exec(sql))	return 0;
	iter = ReturnVector(2).begin();
	ReturnVector(2).erase(iter+Row);
	return 1;
}
bool Account::DeleteAllAgenda()
{
	QSqlQuery query;
	QString sql = "delete  from note";
	query.exec(sql);
	ReturnVector(2).clear();
	return 1;
}