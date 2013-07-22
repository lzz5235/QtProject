#include "DiaryDlg.h"


DiaryDlg::DiaryDlg(Account *account,QWidget *parent):QDialog(parent),acc(account)
{
	ui.setupUi(this);
	InitPanel();
	connect(ui.listWidget, SIGNAL(itemPressed(QListWidgetItem *)), this, SLOT( on_clicked_listWidget(QListWidgetItem *) ));
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT( on_Add() ));
	connect(ui.pushButton_2, SIGNAL(clicked()), this, SLOT( on_Midify() ));
	connect(ui.pushButton_3, SIGNAL(clicked()), this, SLOT( on_Delete() ));
	GetData();	
}
DiaryDlg::~DiaryDlg()
{
}
void DiaryDlg::InitPanel()
{
	setWindowIcon(QIcon("./image/30.ico"));
	QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
	setWindowFlags(Qt::Dialog);
	setAttribute (Qt::WA_DeleteOnClose);
	setWindowTitle("DiaryWritting");
	ui.listWidget->setSortingEnabled(true);
	ui.dateEdit->setDate(QDate::currentDate());

	QPalette palette;
	palette.setColor(QPalette::Background, QColor(199,237,204));
	setPalette(palette);
	setAutoFillBackground(true);
}

void DiaryDlg::on_clicked_listWidget(QListWidgetItem *item)
{
	QSqlQuery query;
	selectRows = ui.listWidget->currentRow();

	if(!acc->ReturnVector(1).empty())//next()不能少
	{
		Date = acc->ReturnVector(1)[selectRows].GetDate();
		Topic = acc->ReturnVector(1)[selectRows].GetTopic();
		Context = acc->ReturnVector(1)[selectRows].GetContext();
	}
	else
	{
		QMessageBox::warning(this,tr("cannot GetData."),tr("cannot GetData."),QMessageBox::Yes);// 如果查询失败，用下面的方法得到具体数据库返回的原因
		//query.clear();
	}
	SetTime(QDate::fromString(Date,"yyyy-MM-dd"));
	SetTopic(Topic);
	SetDetail(Context);
}
QString DiaryDlg::GetTime()
{
	return ui.dateEdit->text();
}
QString DiaryDlg::GetTopic()
{
	return ui.lineEdit->text();
}
QString DiaryDlg::GetDetail()
{
	return ui.textEdit->toPlainText();
}
void DiaryDlg::SetTime(QDate time)
{
	ui.dateEdit->setDate(time);
}
void DiaryDlg::SetTopic(QString topic)
{
	ui.lineEdit->setText(topic);
}
void DiaryDlg::SetDetail(QString detail)
{
	ui.textEdit->setText(detail);
}
void DiaryDlg::GetData()
{// 这里已经成功连上数据库

	//acc->GetDiaryData();
	acc->iter= acc->ReturnVector(1).begin();
	while(acc->iter != acc->ReturnVector(1).end())
	{
		QListWidgetItem *item = new QListWidgetItem(acc->iter->GetDate());
		ui.listWidget->addItem(item);
		++(acc->iter);
	}
}
void DiaryDlg::on_Add()
{
	acc->AddDiaryAgenda(GetTime(),GetTopic(),GetDetail(),0);
	QListWidgetItem *item = new QListWidgetItem(GetTime());
	ui.listWidget->addItem(item);
}
void DiaryDlg::on_Delete()
{
	selectRows = ui.listWidget->currentRow();
	acc->DeleteDiaryAgenda(selectRows);
	ui.listWidget->takeItem(ui.listWidget->currentRow());
	SetTime(QDate::currentDate());
	SetTopic("");
	SetDetail("");
}
void DiaryDlg::on_Midify()
{
	selectRows = ui.listWidget->currentRow();
	acc->ModifyDiaryAgenda(GetTime(),GetTopic(),GetDetail(),selectRows);
	SetTopic(GetTopic());
	SetDetail(GetDetail());
}