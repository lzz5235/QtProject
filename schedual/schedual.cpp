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
					"//Windows//CurrentVersion//Run",QSettings::NativeFormat);//开机自动运行
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

  
    //创建托盘图标菜单并添加动作    
    trayIconMenu = new QMenu(this);     
    trayIconMenu->addAction(restoreAction);     
    trayIconMenu->addAction(minAction);     
    trayIconMenu->addSeparator();     
    trayIconMenu->addAction(aboutAction);     
    trayIconMenu->addSeparator();     
    trayIconMenu->addAction(quitAction);

  
    //创建并设置托盘图标    
    trayIcon = new QSystemTrayIcon(this);     
    trayIcon->setContextMenu(trayIconMenu);     
    trayIcon->setIcon(QIcon("./image/hide.png"));

  
    //显示系统托盘图标    
    trayIcon->show();  
    connect(trayIcon,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),this,    
            SLOT(trayIconActivated(QSystemTrayIcon::ActivationReason)));     
    connect(trayIcon, SIGNAL(messageClicked()), this, SLOT(trayIconMsgClicked()));     

}
void Schedual::ClockInit()
{
	timer = new QTimer;
	ui.lcdNumber->setNumDigits(8);
	ui.lcdNumber->display(QTime::currentTime().toString("hh:mm:ss"));//设置格式，还有其他形式的
	connect(timer,SIGNAL(timeout()),this,SLOT(ClockChange()));
	timer->start(1000);
}
void Schedual::ClockChange()
{
	ui.lcdNumber->display(QTime::currentTime().toString("hh:mm:ss"));
}
void Schedual::InitToolBar()
{
    ui.OpenStart->setStatusTip(tr("开机启动")); 
	ui.OpenStart->setIcon(QIcon("./image/Coffee_016.png"));
    //connect(ui.OpenStart, SIGNAL(triggered()), this, SLOT( AutoRun() ));
	ui.toolBar->addAction(ui.OpenStart);

    ui.TimeAlarm->setStatusTip(tr("定期提醒")); 
	ui.TimeAlarm->setIcon(QIcon("./image/AlertSetting.png"));
    connect(ui.TimeAlarm, SIGNAL(triggered()), this, SLOT( AlertSet() ));
	ui.toolBar->addAction(ui.TimeAlarm);


	ui.Music->setStatusTip(tr("音乐设定")); 
	ui.Music->setIcon(QIcon("./image/music.png"));
    connect(ui.Music, SIGNAL(triggered()), this, SLOT( MusicSet() ));
	ui.toolBar->addAction(ui.Music);

	ui.NoteBook->setStatusTip(tr("个人日记")); 
	ui.NoteBook->setIcon(QIcon("./image/package.png"));
    connect(ui.NoteBook, SIGNAL(triggered()), this, SLOT( DiarySet() ));
	ui.toolBar->addAction(ui.NoteBook);

	ui.TeleBook->setStatusTip(tr("通讯录")); 
	ui.TeleBook->setIcon(QIcon("./image/book.png"));
    connect(ui.TeleBook, SIGNAL(triggered()), this, SLOT( TeleSet() ));
	ui.toolBar->addAction(ui.TeleBook);

	ui.PasswdBook->setStatusTip(tr("刷新")); 
	ui.PasswdBook->setIcon(QIcon("./image/11.png"));
    connect(ui.PasswdBook, SIGNAL(triggered()), this, SLOT( Flush() ));
	ui.toolBar->addAction(ui.PasswdBook);

	ui.synchro->setStatusTip(tr("数据同步")); 
	ui.synchro->setIcon(QIcon("./image/Maintenance.png"));
    connect(ui.synchro, SIGNAL(triggered()), this, SLOT( BlueTooth() ));
	ui.toolBar->addAction(ui.synchro);

	ui.Help->setStatusTip(tr("帮助文档")); 
	ui.Help->setIcon(QIcon("./image/plastic.png"));
    connect(ui.Help, SIGNAL(triggered()), this, SLOT( SchedualHelpDocument() ));
	ui.toolBar->addAction(ui.Help);

	ui.About->setStatusTip(tr("关于本系统")); 
	ui.About->setIcon(QIcon("./image/box.png"));
    connect(ui.About, SIGNAL(triggered()), this, SLOT( Aboub() ));
	ui.toolBar->addAction(ui.About);

	ui.Exit->setStatusTip(tr("退出")); 
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
	QTableWidgetItem* curItem=ui.tableWidget->itemAt(pos);  //获取当前被点击的节点  
    if(curItem==NULL)return;           //这种情况是右键的位置不在treeItem的范围内，即在空白位置右击  
	if(0!=curItem->data(Qt::UserRole))      //data(...)返回的data已经在之前建立节点时用setdata()设置好  
    {  
       QMenu *popMenu =new QMenu(this);//定义一个右键弹出菜单   
	   popMenu->addAction(DeleteAction);
	   popMenu->addAction(Others);   
       popMenu->exec(QCursor::pos());//弹出右键菜单，菜单位置为光标位置  
    } 
}
void Schedual::InitTable()
{
	ui.tableWidget->setColumnCount(3);
	ui.tableWidget->setRowCount(50);
	ui.tableWidget->setColumnWidth(0, 100);
	ui.tableWidget->setColumnWidth(1, 230);
	ui.tableWidget->setColumnWidth(2, 440);
	ui.tableWidget->setSelectionBehavior ( QAbstractItemView::SelectRows); //设置选择行为，以行为单位
	ui.tableWidget->setSelectionMode ( QAbstractItemView::SingleSelection); //设置选择模式，选择单行
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
		ui.tableWidget->removeRow(i);//从后向前删除不会出现问题
	}

	acc->iter = acc->ReturnVector(2).begin();
	while(acc->iter!=acc->ReturnVector(2).end())
	{ // 定位结果到下一条记录
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
		QMessageBox::warning(this,tr("cannot GetData."),tr("cannot GetData........"),QMessageBox::Yes);// 如果查询失败，用下面的方法得到具体数据库返回的原因
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
	QMessageBox::information (this,tr("Help Document"),tr("The SoftWare is designed by 李肇中 欧陈赓 苏江 林令民"),QMessageBox::Ok,NULL);
}