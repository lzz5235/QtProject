#include"AlertSetting.h"


AlertSetting::AlertSetting(Account *account,QWidget *parent):QDialog(parent),acc(account)
{
	ui.setupUi(this);
	QTextCodec::setCodecForTr(QTextCodec::codecForName("gb2312"));
	QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
	setWindowFlags(Qt::Dialog);
	setAttribute (Qt::WA_DeleteOnClose);
	ui.ListWidget->setContextMenuPolicy(Qt::CustomContextMenu);
	setWindowTitle("AlertSetting");
	setWindowIcon(QIcon("./image/30.ico"));
	InitPanel();
	connect(ui.AddButton, SIGNAL(clicked()), this, SLOT( on_Add() ));
	connect(ui.ModifyButton, SIGNAL(clicked()), this, SLOT( on_Modify() ));
	connect(ui.DeleteButton, SIGNAL(clicked()), this, SLOT( on_Delete() ));
	connect(ui.CleanButton, SIGNAL(clicked()), this, SLOT( on_DeleteAll() ));
	connect(ui.ListWidget, SIGNAL(itemPressed(QTableWidgetItem*)), this, SLOT( on_clicked_listWidget(QTableWidgetItem *) ));
	connect(ui.ListWidget, SIGNAL(customContextMenuRequested(const QPoint &)), this, SLOT( on_clicked_listWidget_Right(const QPoint &)));
	DayAlertSetting();	
	GetData();
}
void AlertSetting::DayAlertSetting()
{
	QDate Todaytime = QDate::currentDate();
	Today = Todaytime.toString("yyyy-MM-dd");
}

void AlertSetting::on_clicked_listWidget_Right(const QPoint &pos)
{
	AddAction = new QAction("Add",this);
	AddAction->setIcon(QIcon("./image/Add.png"));     
	ModifyAction = new QAction("Modify",this);
	ModifyAction->setIcon(QIcon("./image/modify.png"));
	DeleteAction = new QAction("Delete",this);
	DeleteAction->setIcon(QIcon("./image/delete.png"));

	connect(AddAction,SIGNAL(triggered()),this,SLOT(on_Add()));
	connect(ModifyAction,SIGNAL(triggered()),this,SLOT(on_Modify()));
	connect(DeleteAction,SIGNAL(triggered()),this,SLOT(on_Delete()));
	QTableWidgetItem* curItem=ui.ListWidget->itemAt(pos);  //��ȡ��ǰ������Ľڵ�  
    if(curItem==NULL)return;           //����������Ҽ���λ�ò���treeItem�ķ�Χ�ڣ����ڿհ�λ���һ�  
	if(0!=curItem->data(Qt::UserRole))      //data(...)���ص�data�Ѿ���֮ǰ�����ڵ�ʱ��setdata()���ú�  
    {  
       QMenu *popMenu =new QMenu(this);//����һ���Ҽ������˵�   
	   popMenu->addAction(AddAction);//���˵������QAction   ��action��ǰ���������������  
       popMenu->addAction(ModifyAction);  
	   popMenu->addAction(DeleteAction);  
       popMenu->exec(QCursor::pos());//�����Ҽ��˵����˵�λ��Ϊ���λ��  
    } 
}
void AlertSetting::InitPanel()
{
	ui.ListWidget->setSelectionBehavior ( QAbstractItemView::SelectRows); //����ѡ����Ϊ������Ϊ��λ
	ui.ListWidget->setSelectionMode ( QAbstractItemView::SingleSelection); //����ѡ��ģʽ��ѡ����
	ui.ListWidget->setEditTriggers ( QAbstractItemView::NoEditTriggers );
	ui.ListWidget->setColumnCount(3);
	ui.ListWidget->setRowCount(50);
	ui.ListWidget->setColumnWidth(0, 100);
	ui.ListWidget->setColumnWidth(1, 200);
	ui.ListWidget->setColumnWidth(2, 315);
	ui.dateEdit->setDate(QDate::currentDate());
	//ui.dateEdit->setDate(QDate::fromString("2011-09-01","yyyy-MM-dd"));
	//QTime::currentTime().toString("hh:mm:ss")
	QPalette palette;
	palette.setColor(QPalette::Background, QColor(199,237,204));
	setPalette(palette);
	setAutoFillBackground(true);

	ui.DeleteButton->setEnabled(false);
	ui.ModifyButton->setEnabled(false);
}
AlertSetting::~AlertSetting()
{
}
QString AlertSetting::GetTime()
{
	return ui.dateEdit->text();
}
QString AlertSetting::GetTopic()
{
	return ui.TopicEdit->text();
}
QString AlertSetting::GetDetail()
{
	return ui.DetailEdit->text();
}
void AlertSetting::SetTime(QDate time)
{
	ui.dateEdit->setDate(time);
}
void AlertSetting::SetTopic(QString topic)
{
	ui.TopicEdit->setText(topic);
}
void AlertSetting::SetDetail(QString detail)
{
	ui.DetailEdit->setText(detail);
}
void AlertSetting::GetData()
{// �����Ѿ��ɹ��������ݿ�
	numRows = 0;
	acc->ReturnVector(2).clear();
	acc->GetSchedualData();

	acc->iter= acc->ReturnVector(2).begin();
	while(acc->iter != acc->ReturnVector(2).end())
	{
		QTableWidgetItem *item1 = new QTableWidgetItem(acc->iter->GetDate());
		QTableWidgetItem *item2 = new QTableWidgetItem(acc->iter->GetTopic());
		QTableWidgetItem *item3 = new QTableWidgetItem(acc->iter->GetContext());
		ui.ListWidget->setItem(numRows,0,item1);
		ui.ListWidget->setItem(numRows,1,item2);
		ui.ListWidget->setItem(numRows,2,item3);
		//ui.ListWidget->addItem(item);
		numRows++;
		++(acc->iter);
	}
}
void AlertSetting::on_Add()
{
	acc->AddSchedualAgenda(GetTime(),GetTopic(),GetDetail(),0);
	QTableWidgetItem *item1 = new QTableWidgetItem(GetTime());
	QTableWidgetItem *item2 = new QTableWidgetItem(GetTopic());
	QTableWidgetItem *item3 = new QTableWidgetItem(GetDetail());
	ui.ListWidget->setItem(acc->agendaSchedualList.size()-1,0,item1);
	ui.ListWidget->setItem(acc->agendaSchedualList.size()-1,1,item2);
	ui.ListWidget->setItem(acc->agendaSchedualList.size()-1,2,item3);
}
void AlertSetting::on_Modify()
{
	selectRows = ui.ListWidget->currentRow();

	acc->ModifySchedualAgenda(GetTime(),GetTopic(),GetDetail(),selectRows);

	ui.ListWidget->setItem(selectRows,0,new QTableWidgetItem(GetTime()));
	ui.ListWidget->setItem(selectRows,1,new QTableWidgetItem(GetTopic()));
	ui.ListWidget->setItem(selectRows,2,new QTableWidgetItem(GetDetail()));
}
void AlertSetting::on_Delete()
{
	selectRows = ui.ListWidget->currentRow();
	acc->DeleteSchedualAgenda(selectRows);

	ui.ListWidget->removeRow(selectRows);
	QString Text="";
	Date="";Topic="";Detail="";
	ui.label_5->setText(Text);
}
void AlertSetting::on_DeleteAll()
{	
	for(int i=acc->ReturnVector(2).size();i>=0;i--)
	{
		ui.ListWidget->removeRow(i);//�Ӻ���ǰɾ�������������
	}
	acc->DeleteAllAgenda();
	QString Text="";
	ui.label_5->setText(Text);
	Date="";Topic="";Detail="";
}
void AlertSetting::on_clicked_listWidget(QTableWidgetItem *item)
{
	selectRows = item->row();

	Date=acc->ReturnVector(2)[selectRows].GetDate();
	Topic=acc->ReturnVector(2)[selectRows].GetTopic();
	Detail=acc->ReturnVector(2)[selectRows].GetContext();
	if(!Date.isEmpty()&&!Topic.isEmpty())
	{
		ui.DeleteButton->setEnabled(true);
		ui.ModifyButton->setEnabled(true);
	}
	else
	{
		ui.DeleteButton->setEnabled(false);
		ui.ModifyButton->setEnabled(false);
	}

	SetTime(QDate::fromString(Date,"yyyy-MM-dd"));
	SetTopic(Topic);
	SetDetail(Detail);
	SetNoteText();
}
void AlertSetting::SetNoteText()
{
	QString Text="PlanTime:"+Date+"\n";
	Text.append("PlanTopic:"+Topic+"\n");
	Text.append("PlanContext:\n"+Detail+"\n");
	ui.label_5->setText(Text);
}