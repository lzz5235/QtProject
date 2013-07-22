#include "Login.h"
#include <QMessageBox>
#include <QSettings>

Login::Login(QWidget *parent):QDialog(parent)
{
	ui.setupUi(this);
	//setAttribute (Qt::WA_DeleteOnClose);//退出时销毁
	ui.UserPasswd->setEchoMode(QLineEdit::Password);
	setWindowFlags(Qt::Dialog);
	setWindowTitle("Welcome to PlanManager System");
	setWindowIcon(QIcon("./image/30.ico"));
	SetbgPic();
	connect(ui.Login, SIGNAL(clicked()), this, SLOT( on_login() ));
	connect(ui.Cancel, SIGNAL(clicked()), this, SLOT( on_cancel() ));
	connect(ui.New, SIGNAL(clicked()), this, SLOT( on_New() ));
}

Login::~Login()
{

}
void Login::SetbgPic()
{
	QPalette palette;
	palette.setColor(QPalette::Background, QColor(199,237,204));
	setPalette(palette);
	setAutoFillBackground(true);
	//QPixmap pixmap("./image/background.jpg");
	//ui.frame->setPalette(palette);
	//ui.frame->setAutoFillBackground(true);
}
void Login::on_cancel()
{
	exit(0);
}
void Login::on_login()
{
	ReadConfig();
	if(ui.UserName->text()==RealName&&ui.UserPasswd->text()==RealPasswd)//判断用户名和密码是否正确
	{	
		//QMessageBox::warning(this,tr("Logining....."),tr("Login  Succeed......"),QMessageBox::Yes);
		accept();
	}
	else
	{
		QMessageBox::warning(this,tr("Warning"),tr("Your User name or Password Error!"),QMessageBox::Yes);
		ui.UserName->clear();
		ui.UserPasswd->clear();
	}
}
void Login::on_New()
{
	//QString Name,Passwd;
	if(!ui.UserName->text().isEmpty()&&!ui.UserPasswd->text().isEmpty())
	{	
		UserName = ui.UserName->text();
		UserPasswd = ui.UserPasswd->text();
		WriteConfig();
		QMessageBox::information(this, tr("New User"),tr("Succeed IniyUser......"),QMessageBox::Ok);
	}
	else
		QMessageBox::information(this, tr("New User"),tr("Not Empty ID and Passwd"),QMessageBox::Ok);	
}
void Login::ReadConfig()
{
	ConfigIni = new QSettings("./Config.ini",QSettings::IniFormat,0);
	RealName = ConfigIni->value("/config/UserName","20").toString();
	RealPasswd = ConfigIni->value("/config/UserPasswd","20").toString();
	decode(&RealName);
	decode(&RealPasswd);
	//QMessageBox::information(this, tr("About Music Setting"),RealName);
	//QMessageBox::information(this, tr("About Music Setting"),RealPasswd);
}
void Login::WriteConfig()
{
	encode(&UserName);
	encode(&UserPasswd);
	ConfigIni = new QSettings("./Config.ini",QSettings::IniFormat,0);  
	ConfigIni->setValue("/config/UserName",UserName);
	ConfigIni->setValue("/config/UserPasswd",UserPasswd);
	delete ConfigIni;
}
void Login::encode(QString *data)
{
	QString str = *data;
	int len = str.length();  
    for(int i=0;i<len;++i)  
    {  
        str[i] = QChar::fromAscii(str[i].toAscii() - 20);
	}
	*data = str;
}
void Login::decode(QString *data)
{
	QString str = *data;
	int len = str.length();  
    for(int i=0;i<len;++i)  
    {  
        str[i] = QChar::fromAscii(str[i].toAscii() + 20);
	}
	*data = str;
}
