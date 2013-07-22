#include"telebookDlg.h"
#include <QIntValidator>

TeleBookDlg::TeleBookDlg(Account *account,QWidget *parent):QDialog(parent),acc(account)
{
	ui.setupUi(this);
	InitPanel();
	connect(ui.listWidget, SIGNAL(itemPressed(QListWidgetItem *)), this, SLOT( on_clicked_listWidget(QListWidgetItem *) ));
	connect(ui.pushButton_3, SIGNAL(clicked()), this, SLOT( on_Add() ));
	connect(ui.pushButton_2, SIGNAL(clicked()), this, SLOT( on_Delete() ));
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT( on_AddPhoto() ));
	GetData();
}
TeleBookDlg::~TeleBookDlg()
{
}
void TeleBookDlg::on_AddPhoto()
{
	Photo = QFileDialog::getOpenFileName(this,"Open Photo",QDir::currentPath(),
												"Document files (*.jpg *.png *.bmp);;All files(*.*)");
	if (!Photo.isNull()) 
	{
		QPixmap pixmap(Photo);
		palette.setBrush(ui.frame->backgroundRole(),QBrush(pixmap));
		ui.frame->setPalette(palette);
		//ui.frame->setMask(pixmap.mask()); //可以将图片中透明部分显示为透明的
		ui.frame->setAutoFillBackground(true);

		fileinfo = new QFileInfo(Photo);
		Path = fileinfo->path();

		ConfigIni = new QSettings("./Config.ini",QSettings::IniFormat,0);  
		ConfigIni->setValue("/config/Photo",Path);		
		delete ConfigIni;
	}
	else 
		return;
}
void TeleBookDlg::InitPanel()
{

	setWindowTitle("ConnectBook");
	setWindowIcon(QIcon("./image/30.ico"));
	QRegExp regExp1("^[1-9][0-9]*$");
	QRegExpValidator *pRegExpValidator1 = new QRegExpValidator(regExp1,this);
	ui.Tele1->setValidator(pRegExpValidator1);
	ui.Tele2->setValidator(pRegExpValidator1);

	QRegExp regExp2("[A-z0-9_/.-]+@[A-z0-9_/.]+");
	QRegExpValidator *pRegExpValidator2 = new QRegExpValidator(regExp2,this);
	ui.lineEdit_4->setValidator(pRegExpValidator2);

	ConfigIni = new QSettings("./Config.ini",QSettings::IniFormat,0);
	Path = ConfigIni->value("/config/Photo","20").toString();
	delete ConfigIni;

	//QPalette palette;
	palette.setColor(QPalette::Background, QColor(199,237,204));
	setPalette(palette);
	setAutoFillBackground(true);
}
void TeleBookDlg::GetData()
{
	//acc->GetPhoneData();
	acc->iter = acc->ReturnVector(3).begin();
	while(acc->iter != acc->ReturnVector(3).end())
	{
		QListWidgetItem *item = new QListWidgetItem(acc->iter->GetName());
		ui.listWidget->addItem(item);
		++(acc->iter);
	}
}
QString TeleBookDlg::GetName()
{
	return ui.lineEdit->text();
}
QString TeleBookDlg::GetOthers()
{
	return ui.textEdit->toPlainText();	
}
QString TeleBookDlg::GetPhoneNumber1()
{
	return  ui.Tele1->text();
}
QString TeleBookDlg::GetPhoneNumber2()
{
	return  ui.Tele2->text();
}
QString TeleBookDlg::GetEmail()
{
	return ui.lineEdit_4->text();
}
QString TeleBookDlg::GetPic()
{
	fileinfo = new QFileInfo(Photo);
	Photo = fileinfo->fileName();
	return Photo;
}
void TeleBookDlg::on_Add()
{
	acc->AddPhoneAgenda(GetName(),GetPhoneNumber1(),GetPhoneNumber2(),GetEmail(),GetOthers(),GetPic());
	QListWidgetItem *item = new QListWidgetItem(GetName());
	ui.listWidget->addItem(item);
}
void TeleBookDlg::on_Delete()
{
	selectRows = ui.listWidget->currentRow();
	acc->DeletePhoneAgenda(selectRows);
	ui.listWidget->takeItem(ui.listWidget->currentRow());

	SetName(NULL);
	SetPhoneNumber(NULL,NULL);
	SetEmail(NULL);
	SetOthers(NULL);
	SetOthers(NULL);
}
void TeleBookDlg::on_clicked_listWidget(QListWidgetItem *item)
{
	selectRows = ui.listWidget->currentRow();
	QString Rows = QString::number(selectRows);

	SetName(acc->ReturnVector(3)[selectRows].GetName());
	SetPhoneNumber(acc->ReturnVector(3)[selectRows].GetNum1(),acc->ReturnVector(3)[selectRows].GetNum2());
	SetEmail(acc->ReturnVector(3)[selectRows].GetEmail());
	SetOthers(acc->ReturnVector(3)[selectRows].GetOther());
	SetPic(acc->ReturnVector(3)[selectRows].GetPic());
}
void TeleBookDlg::SetName(QString Name)
{
	ui.lineEdit->setText(Name);
}
void TeleBookDlg::SetPhoneNumber(QString Num1,QString Num2)
{
	ui.Tele1->setText(Num1);
	ui.Tele2->setText(Num2);
}
void TeleBookDlg::SetEmail(QString Email)
{
	ui.lineEdit_4->setText(Email);
}
void TeleBookDlg::SetOthers(QString others)
{
	ui.textEdit->setText(others);
}
void TeleBookDlg::SetPic(QString pic)
{
	ConfigIni = new QSettings("./Config.ini",QSettings::IniFormat,0);
	Path = ConfigIni->value("/config/Photo","20").toString();
	QPixmap pixmap(Path+"//"+pic);
	//QMessageBox::warning(this,tr("cannot GetData."),Path+"//"+pic,QMessageBox::Yes);
	palette.setBrush(ui.frame->backgroundRole(),QBrush(pixmap));
	ui.frame->setPalette(palette);
	//ui.frame->setMask(pixmap.mask()); //可以将图片中透明部分显示为透明的
	ui.frame->setAutoFillBackground(true);
	delete ConfigIni;
}