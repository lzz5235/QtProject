#include "schedual.h"


Schedual::Schedual(Account *account,QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags),acc(account)
{
	ui.setupUi(this);
	QTextCodec::setCodecForTr(QTextCodec::codecForName("gb2312"));
	QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
	setWindowTitle("Schedual");
	setWindowFlags(Qt::WindowMinimizeButtonHint);
	setWindowIcon(QIcon("./image/30.ico"));
	initTrayIcon();
	InitToolBar();
	InitTable();
	ClockInit();
	GetData();	
}
void Schedual::AutoRun()
{
	QSettings *reg=new QSettings("HKEY_LOCAL_MACHINE//SOFTWARE//Microsoft"
					"//Windows//CurrentVersion//Run",QSettings::NativeFormat);//�����Զ�����
	reg->setValue("Schedual",QApplication::applicationFilePath());
}
void Schedual::initTrayIcon()
{

	
	minAction = new QAction("Hide",this);     
    minAction->setIcon(QIcon("./image/hide.png"));     
    connect(minAction,SIGNAL(triggered()),this,SLOT(hide()));

  
    restoreAction = new QAction("restore",this);    
    restoreAction->setIcon(QIcon("./image/restore.png"));     
    connect(restoreAction,SIGNAL(triggered()),this,SLOT(showNormal()));

  
    aboutAction = new QAction("about",this);    
    aboutAction->setIcon(QIcon("./image/About.png"));     
    connect(aboutAction,SIGNAL(triggered()),this,SLOT(Aboub()));

  
    quitAction = new QAction("Exit",this);    
    quitAction->setIcon(QIcon("./image/13.png"));     
    connect(quitAction,SIGNAL(triggered()),qApp,SLOT(quit()));

  
    //��������ͼ��˵�����Ӷ���    
    trayIconMenu = new QMenu(this);     
    trayIconMenu->addAction(restoreAction);     
    trayIconMenu->addAction(minAction);     
    trayIconMenu->addSeparator();     
    trayIconMenu->addAction(aboutAction);     
    trayIconMenu->addSeparator();     
    trayIconMenu->addAction(quitAction);

  
    //��������������ͼ��    
    trayIcon = new QSystemTrayIcon(this);     
    trayIcon->setContextMenu(trayIconMenu);     
    trayIcon->setIcon(QIcon("./image/hide.png"));

  
    //��ʾϵͳ����ͼ��    
    trayIcon->show();  
    connect(trayIcon,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),this,    
            SLOT(trayIconActivated(QSystemTrayIcon::ActivationReason)));     
    connect(trayIcon, SIGNAL(messageClicked()), this, SLOT(trayIconMsgClicked()));     

}
void Schedual::ClockInit()
{
	timer = new QTimer;
	ui.lcdNumber->setNumDigits(8);
	ui.lcdNumber->display(QTime::currentTime().toString("hh:mm:ss"));//���ø�ʽ������������ʽ��
	connect(timer,SIGNAL(timeout()),this,SLOT(ClockChange()));
	timer->start(1000);
}
void Schedual::ClockChange()
{
	ui.lcdNumber->display(QTime::currentTime().toString("hh:mm:ss"));
}
void Schedual::InitToolBar()
{
    ui.OpenStart->setStatusTip(tr("��������")); 
	ui.OpenStart->setIcon(QIcon("./image/Coffee_016.png"));
    //connect(ui.OpenStart, SIGNAL(triggered()), this, SLOT( AutoRun() ));
	ui.toolBar->addAction(ui.OpenStart);

    ui.TimeAlarm->setStatusTip(tr("��������")); 
	ui.TimeAlarm->setIcon(QIcon("./image/AlertSetting.png"));
    connect(ui.TimeAlarm, SIGNAL(triggered()), this, SLOT( AlertSet() ));
	ui.toolBar->addAction(ui.TimeAlarm);


	ui.Music->setStatusTip(tr("�����趨")); 
	ui.Music->setIcon(QIcon("./image/music.png"));
    connect(ui.Music, SIGNAL(triggered()), this, SLOT( MusicSet() ));
	ui.toolBar->addAction(ui.Music);

	ui.NoteBook->setStatusTip(tr("�����ռ�")); 
	ui.NoteBook->setIcon(QIcon("./image/package.png"));
    connect(ui.NoteBook, SIGNAL(triggered()), this, SLOT( DiarySet() ));
	ui.toolBar->addAction(ui.NoteBook);

	ui.TeleBook->setStatusTip(tr("ͨѶ¼")); 
	ui.TeleBook->setIcon(QIcon("./image/book.png"));
    connect(ui.TeleBook, SIGNAL(triggered()), this, SLOT( TeleSet() ));
	ui.toolBar->addAction(ui.TeleBook);

	ui.PasswdBook->setStatusTip(tr("ˢ��")); 
	ui.PasswdBook->setIcon(QIcon("./image/11.png"));
    connect(ui.PasswdBook, SIGNAL(triggered()), this, SLOT( Flush() ));
	ui.toolBar->addAction(ui.PasswdBook);

	ui.synchro->setStatusTip(tr("����ͬ��")); 
	ui.synchro->setIcon(QIcon("./image/Maintenance.png"));
    connect(ui.synchro, SIGNAL(triggered()), this, SLOT( BlueTooth() ));
	ui.toolBar->addAction(ui.synchro);

	ui.Help->setStatusTip(tr("�����ĵ�")); 
	ui.Help->setIcon(QIcon("./image/plastic.png"));
    connect(ui.Help, SIGNAL(triggered()), this, SLOT( SchedualHelpDocument() ));
	ui.toolBar->addAction(ui.Help);

	ui.About->setStatusTip(tr("���ڱ�ϵͳ")); 
	ui.About->setIcon(QIcon("./image/box.png"));
    connect(ui.About, SIGNAL(triggered()), this, SLOT( Aboub() ));
	ui.toolBar->addAction(ui.About);

	ui.Exit->setStatusTip(tr("�˳�")); 
	ui.Exit->setIcon(QIcon("./image/13.png"));
    connect(ui.Exit, SIGNAL(triggered()), this, SLOT( Exit() ));
	ui.toolBar->addAction(ui.Exit);

	ui.toolBar->setIconSize(QSize(50,50));

	QPalette palette;
	palette.setColor(QPalette::Background, QColor(199,237,204));
	setPalette(palette);
	setAutoFillBackground(true);
}
void Schedual::on_clicked_listWidget_Right(const QPoint &pos)
{
	Others = new QAction("DetailSetting",this);
	Others->setIcon(QIcon("./image/delete.png"));
	DeleteAction = new QAction("Delete",this);
	DeleteAction->setIcon(QIcon("./image/delete.png"));

	connect(Others,SIGNAL(triggered()),this,SLOT(AlertSet()));
	connect(DeleteAction,SIGNAL(triggered()),this,SLOT(on_Delete()));
	QTableWidgetItem* curItem=ui.tableWidget->itemAt(pos);  //��ȡ��ǰ������Ľڵ�  
    if(curItem==NULL)return;           //����������Ҽ���λ�ò���treeItem�ķ�Χ�ڣ����ڿհ�λ���һ�  
	if(0!=curItem->data(Qt::UserRole))      //data(...)���ص�data�Ѿ���֮ǰ�����ڵ�ʱ��setdata()���ú�  
    {  
       QMenu *popMenu =new QMenu(this);//����һ���Ҽ������˵�   
	   popMenu->addAction(DeleteAction);
	   popMenu->addAction(Others);   
       popMenu->exec(QCursor::pos());//�����Ҽ��˵����˵�λ��Ϊ���λ��  
    } 
}
void Schedual::InitTable()
{
	ui.tableWidget->setColumnCount(3);
	ui.tableWidget->setRowCount(50);
	ui.tableWidget->setColumnWidth(0, 100);
	ui.tableWidget->setColumnWidth(1, 230);
	ui.tableWidget->setColumnWidth(2, 440);
	ui.tableWidget->setSelectionBehavior ( QAbstractItemView::SelectRows); //����ѡ����Ϊ������Ϊ��λ
	ui.tableWidget->setSelectionMode ( QAbstractItemView::SingleSelection); //����ѡ��ģʽ��ѡ����
	ui.tableWidget->setEditTriggers ( QAbstractItemView::NoEditTriggers );
	ui.textEdit->setReadOnly(true);
	connect(ui.tableWidget, SIGNAL(itemPressed(QTableWidgetItem*)), this, SLOT( on_clicked_listWidget(QTableWidgetItem *) ));
	connect(ui.tableWidget, SIGNAL(customContextMenuRequested(const QPoint &)), this, SLOT( on_clicked_listWidget_Right(const QPoint &)));
}

void Schedual::GetData()
{
	numRows = 0;
	//acc->GetSchedualData();
	for(int i=acc->ReturnVector(2).size();i>=0;i--)
	{
		ui.tableWidget->removeRow(i);//�Ӻ���ǰɾ�������������
	}

	acc->iter = acc->ReturnVector(2).begin();
	while(acc->iter!=acc->ReturnVector(2).end())
	{ // ��λ�������һ����¼
		QTableWidgetItem *item1 = new QTableWidgetItem(acc->iter->GetDate());
		QTableWidgetItem *item2 = new QTableWidgetItem(acc->iter->GetTopic());
		QTableWidgetItem *item3 = new QTableWidgetItem(acc->iter->GetContext());
		ui.tableWidget->setItem(numRows,0,item1);
		ui.tableWidget->setItem(numRows,1,item2);
		ui.tableWidget->setItem(numRows,2,item3);
		++(acc->iter);
		numRows++;
	}
	if(acc->iter==NULL)
	{
		QMessageBox::warning(this,tr("cannot GetData."),tr("cannot GetData........"),QMessageBox::Yes);// �����ѯʧ�ܣ�������ķ����õ��������ݿⷵ�ص�ԭ��
	}	
}
void Schedual::on_clicked_listWidget(QTableWidgetItem *item)
{
	selectRows = item->row();
	Date=ui.tableWidget->item(selectRows,0)->text();
	Topic=ui.tableWidget->item(selectRows,1)->text();
	Detail=ui.tableWidget->item(selectRows,2)->text();  

	SetNoteText();
}
void Schedual::SetNoteText()
{
	QString Text="PlanTime:"+Date+"\n";
	Text.append("PlanTopic:"+Topic+"\n");
	Text.append("PlanContext:\n"+Detail+"\n");
	ui.textEdit->setText(Text);
}

Schedual::~Schedual()
{
	delete Dlg;
	delete MuDlg ;
	delete acc;
}
void Schedual::AlertSet()
{
	Dlg = new AlertSetting(acc);
	if(Dlg->exec()==QDialog::Accepted)
	{	
		GetData();
	}
	else
		GetData();
}

void Schedual::MusicSet()
{
	MuDlg = new MusicDlg();
	MuDlg->setWindowModality(Qt::WindowModal);
	if(MuDlg!=NULL)
	{
		MuDlg->show();		
	}
	else
		close();
}
void Schedual::DiarySet()
{
	DiaDlg = new DiaryDlg(acc);
	if(DiaDlg->exec()==QDialog::Accepted)
	{	
		GetData();
	}
}
void Schedual::TeleSet()
{
	teleDlg = new TeleBookDlg(acc);
	if(teleDlg->exec()==QDialog::Accepted)
	{	
		GetData();
	}
}
void Schedual::SchedualHelpDocument()
{
	QMessageBox::information (this,tr("Help Document"),tr("The SoftWare is designed by ������ ŷ���� �ս� ������"),QMessageBox::Ok,NULL);
}