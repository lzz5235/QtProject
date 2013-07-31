#include "weather.h"

#include <QApplication>
#include <QTextCodec>
#include <QTextStream>
#include <QDomDocument>
#include <QtScript/QScriptValue>
#include <QtScript/QScriptEngine>
#include <QSettings>

#include <QDebug>

CWeatherWidget::CWeatherWidget()
{
	QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));
	QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GBK"));
	m_strCityName = QString(tr("北京"));
	Init();
	InitPic();

	//通过本机公网IP得到所在城市
	m_NetworkManager = new QNetworkAccessManager(this);
	m_NetworkRequest.setUrl(QUrl("http://iframe.ip138.com/ic.asp"));
	m_NetworkReplyIP = m_NetworkManager->get(m_NetworkRequest);
	connect(m_NetworkReplyIP, SIGNAL(readyRead()), this, SLOT(slotPublicNetworkIP()));

	setWindowFlags(Qt::WindowMinimizeButtonHint );
	setWindowTitle(tr("天气预报-测试版"));
	QIcon icon = QIcon("./images/mostly_sunny.gif");
	setWindowIcon(icon);
//	setFixedSize(230, 190);	
}

CWeatherWidget::~CWeatherWidget()
{
	//delete frame;
}
QString CWeatherWidget::showPic(QString  *str)
{
	QMap<QString,QString>::iterator it = m_map.find(*str); //遍历map  
	return it.value();
}
void CWeatherWidget::InitPic()
{
	m_map.insert("晴","sunny.gif");
	m_map.insert("多云","cloudy.gif");
	m_map.insert("晴转多云","mostly_sunny.gif");
	m_map.insert("多云转阴","mostly_cloudy.gif");
	m_map.insert("雨","rain.gif");
	m_map.insert("阵雨","chance_of_storm.gif");
	m_map.insert("雷阵雨转中雨","chance_of_tstorm.gif");
}
void CWeatherWidget::slotPublicNetworkLocal()
{
	char*  ch;
	char  info[100]={0};
	int i = 0;
	QByteArray ba = strNetworkInfo.toLocal8Bit();  
	ch=ba.data();

	char *temp1;	temp1 = ch;
	char *temp2;
	char *temp3;
	while(	*temp1 !='[' ){temp1++;}
	temp2 = ++temp1;
	while(	*temp2 !=']' ){temp2++;}
	temp3  = ++temp2;
	while(	*temp3 != '<'){temp3++;}

	for(i = 0;*temp1 !=*temp2;i++,temp1++)
	{
		info[i] = *temp1;
	}
	info[--i] = '\0';
	m_nerworkIP = QString(info);

	i=0;
	while(i!=7){	temp2++;i++;}
	for(i = 0;*temp2 !=*temp3 ;i++,temp2++)
	{
		info[i] = *temp2;
	}
	info[i] = '\0';

	for(;info[i]!=' ';i--){	}	i-=2;info[i] = '\0';

	m_strLocal = QString(info) ;

	for(i=0;info[i]!='\0';i++)
	{
		info[i] = info[i+6];
	}
	m_NumLocal = QString(info) ;
}
void CWeatherWidget::slotPublicNetworkLocal(QString & str)
{
	char*  ch;
	char  info[100]={0};
	int i = 0;
	QByteArray ba = str.toLocal8Bit();  
	ch=ba.data();

	char *temp1;	temp1 = ch;
	char *temp2;
	char *temp3;
	while(	*temp1 !='[' ){temp1++;}
	temp2 = ++temp1;
	while(	*temp2 !=']' ){temp2++;}
	temp3  = ++temp2;
	while(	*temp3 != '<'){temp3++;}

	for(i = 0;*temp1 !=*temp2;i++,temp1++)
	{
		info[i] = *temp1;
	}
	info[--i] = '\0';
	m_nerworkIP = QString(info);

	i=0;
	while(i!=7){	temp2++;i++;}
	for(i = 0;*temp2 !=*temp3 ;i++,temp2++)
	{
		info[i] = *temp2;
	}
	info[i] = '\0';

	for(;info[i]!=' ';i--){	}	info[i] = '\0';
	m_strLocal = QString(info) ;

	for(i=0;info[i]!='\0';i++)
	{
		info[i] = info[i+6];
	}
	m_NumLocal = QString(info) ;
}
void CWeatherWidget::slotPublicNetworkIP()
{
	QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GBK"));
	strNetworkInfo = m_NetworkReplyIP->readAll();

	slotPublicNetworkLocal();//获取IP 归属地
	slotWeatherInfo();
}

void CWeatherWidget::Init()
{
	QAction* newAct = new QAction( tr("本机公网IP查询"), this);
	newAct->setCheckable(true);
	connect(newAct, SIGNAL(triggered()), this, SLOT(slotNetworkIP()));
	QAction* openAct = new QAction(tr("开机自启动"), this);
	openAct->setCheckable(true);
	connect(openAct, SIGNAL(triggered()), this, SLOT(slotBootStart()));

	//创建菜单
	m_customSetMenu = menuBar()->addMenu(tr("常见选项"));
	m_customSetMenu->addAction(openAct);
	m_customSetMenu->addAction(newAct);

	QWidget *centreWidget = new QWidget(this);
	m_ctiyLabel = new QLabel(tr("北京市"), this);
	m_ctiyLabel->setStyleSheet("font:14px; font:bold; color:red"); 

	QDate data = QDate::currentDate();
	m_ctiyLabel->setAlignment(Qt::AlignHCenter);
	m_dateLable = new QLabel(data.toString("yyyy-MM-dd"), this);
	m_dateLable->setAlignment(Qt::AlignHCenter);
	m_timeLable = new QLabel(this);
	m_timeLable->setStyleSheet("color:blue"); 
	m_timeLable->setAlignment(Qt::AlignHCenter);
	m_switchButtom = new QPushButton(tr("[切换城市]"), this);
	QVBoxLayout* Vlayout1 = new QVBoxLayout(this);
	Vlayout1->addWidget(m_ctiyLabel);
	Vlayout1->addWidget(m_dateLable);
	Vlayout1->addWidget(m_timeLable);
	Vlayout1->addWidget(m_switchButtom);

	m_picLable = new QLabel(this);
	m_picLable->setAlignment(Qt::AlignHCenter);
	QPixmap pixFail;
	pixFail.load("./images/mostly_cloudy.gif");
	m_picLable->setPixmap(pixFail);
	m_weatherPicLable = new QLabel(tr("无信息"), this);
	m_weatherPicLable->setAlignment(Qt::AlignHCenter);
	m_tadayTLable = new QLabel(tr("无信息"), this);
	m_tadayTLable->setAlignment(Qt::AlignHCenter);
	QVBoxLayout* Vlayout2 = new QVBoxLayout(this);
	Vlayout2->addWidget(m_picLable);
	Vlayout2->addWidget(m_weatherPicLable);
	Vlayout2->addWidget(m_tadayTLable);

	m_curentWeatherLable = new QLabel(tr("当前：无信息"), this);
	m_humidityLable = new QLabel(tr("湿度：无信息"), this);
	m_windLable = new QLabel(tr("风向：无信息<br />风速：无信息"), this);
	m_currentWeatherLable = new QLabel(tr("实时天气：无信息"), this);
	QVBoxLayout* Vlayout3 = new QVBoxLayout(this);
	Vlayout3->addWidget(m_curentWeatherLable);
	Vlayout3->addWidget(m_humidityLable);
	Vlayout3->addWidget(m_windLable);
	Vlayout3->addWidget(m_currentWeatherLable);

	QHBoxLayout* Hlayout1 = new QHBoxLayout(this);
	Hlayout1->addLayout(Vlayout1);
	Hlayout1->addLayout(Vlayout2);
	Hlayout1->addLayout(Vlayout3);

	m_threeWeatherLable = new QLabel("无信息<br />无信息<br />无信息", this);

	QVBoxLayout* Vlayout4 = new QVBoxLayout(centreWidget);
	Vlayout4->addLayout(Hlayout1);
	Vlayout4->addWidget(m_threeWeatherLable);
	setCentralWidget(centreWidget);

	connect(m_switchButtom, SIGNAL(clicked()), this, SLOT(switchCtiy()));

	QTimer *timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
	timer->start(500);

	QTimer *timerChange = new QTimer(this);
	connect(timerChange, SIGNAL(timeout()), this, SLOT(slotWeatherInfo()));
	timerChange->start(600000);
}

void CWeatherWidget::showTime()
{
	static bool showColon = true;
	QTime time = QTime::currentTime();
	QString text = time.toString("hh:mm");
	if(showColon)
	{
		text[2] = ':';
		showColon = false;
	}
	else
	{
		text[2] = ' ';
		showColon = true;     	
	}
	m_timeLable->setText(text);
}

void CWeatherWidget::switchCtiy()
{
	bool ok = false;
	QString cityName = QInputDialog::getText( this, tr("输入城市名称"),
		               tr("请输入城市名称：") + "\n" + tr("[支持全拼或汉字/区、县、县级市要用全称且为汉字]"), QLineEdit::Normal, "", &ok);
	if (!cityName.isEmpty())
	{
		m_NumLocal = cityName;
	}
	else
	{
		return;
	}
	slotWeatherInfo();
}
QString CWeatherWidget::FindCode()
{
		QFile file("./images/weathercity.code.txt");
		int code=0;
		QString line;
		if(!file.open(QFile::ReadOnly | QFile::Text))
		{
			QMessageBox::warning(this,tr("错误提示"),tr("打开文件失败！"),QMessageBox::Ok);
			return 0;
		}
		QTextStream in(&file);
		while (!in.atEnd())
		{
			line = in.readLine();
			if(line.contains(m_NumLocal,Qt::CaseInsensitive))
			{
				code = line.indexOf(m_NumLocal);
				break;
			}
		}
		return 		line.mid(code,10+m_NumLocal.size());
}
void CWeatherWidget::slotWeatherInfo()
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));

	QString code  = FindCode().right(9);

	QString url = "http://m.weather.com.cn/data/";
	url += code;
	url +=".html";
	
	qDebug() << url;
	//QString url = "http://m.weather.com.cn/data/404010100.html";

	m_NetworkRequest.setUrl(QUrl(url));
    m_NetworkReply = m_NetworkManager->get(m_NetworkRequest);
    connect(m_NetworkReply, SIGNAL(readyRead()), this, SLOT(slotReadyRead()));
}

void CWeatherWidget::slotReadyRead()
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
	QString str,strC,strF;
	QString info;
	
	QString data[4][4] = {	{"temp1","weather1","wind1","fl1"},
								{"temp2","weather2","wind2","fl2"},
								{"temp3","weather3","wind3","fl3"},
								{"temp4","weather4","wind1","fl4"}		};

	QString json = m_NetworkReply->readAll();
    if(json.size() < 1000) 
	{ 
		m_threeWeatherLable->setText( m_strCityName + tr(":查无此城市!"));
        return ;
    }
	
	QScriptValue sc;
	QScriptEngine engine;
	sc = engine.evaluate("(" + json + ")"); //规定写法，具体没研究

	QPixmap pixFail;
	pixFail.load("./images/" + showPic(&	(sc.property("weatherinfo").property("weather1").toString() )	)	);
	m_picLable->setPixmap(pixFail);

	m_dateLable->setText(sc.property("weatherinfo").property("date_y").toString());//date
	m_ctiyLabel->setText(sc.property("weatherinfo").property("city").toString()); //city

	strC = sc.property("weatherinfo").property("temp1").toString();
	strF = sc.property("weatherinfo").property("tempF1").toString();
	if (strC.isEmpty()&&strF.isEmpty())
	{
		m_curentWeatherLable->setText(QString(tr("当前摄氏温度：无信息")));
		m_humidityLable->setText(QString(tr("当前华氏温度：无信息")));
	} 
	else
	{
		m_curentWeatherLable->setText(QString(tr("当前：")) + strC);
		m_humidityLable->setText(QString(tr("当前：")) + strF) ;
	}

	
	str = sc.property("weatherinfo").property("wind1").toString();
	str +=",";
	str +=sc.property("weatherinfo").property("fl1").toString();
	if (str.isEmpty())
	{
		m_windLable->setText(QString(tr("风向：无信息")));
	} 
	else
	{
		str.replace(" ", "");
		str.replace(QString(tr("、")), QString("<br />"));
		m_windLable->setText(str);
	}	

	m_currentWeatherLable->setText(tr("实时天气：") + sc.property("weatherinfo").property("weather1").toString());
	m_weatherPicLable->setText(sc.property("weatherinfo").property("index48").toString());//index48
	m_tadayTLable->setText(sc.property("weatherinfo").property("index_tr").toString()+tr("出游"));


	for(int i=1;i<4;i++)
	{
			info.append(sc.property("weatherinfo").property(data[i][0]).toString()+tr(","));
			info.append(sc.property("weatherinfo").property(data[i][1]).toString()+tr(","));
			info.append(sc.property("weatherinfo").property(data[i][2]).toString()+tr(","));
			info.append(sc.property("weatherinfo").property(data[i][3]).toString()+tr("<font/>"));
			info.append(" <br />");
			if(i % 2 == 0)
			{
				info.append("<font color=blue>");
			}else
			{
				info.append("<font color=green>");
			}
	}
	info.append(tr("...以上是未来三天预报..."));
    m_threeWeatherLable->setText(info);

}

void CWeatherWidget::slotNetworkIP()
{
	QMessageBox::question(this, tr("公网IP查询"), m_nerworkIP + "\n" + m_strLocal);
}

 //开机自动运行  
void CWeatherWidget::slotBootStart()
{
	int rb = QMessageBox::question(NULL, tr("提示"), tr("是否设置开机自启动？"), "Yes", "No");

	if(rb == 0)
	{
		QSettings *reg=new QSettings("HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Run",QSettings::NativeFormat);   
		reg->setValue("app",QCoreApplication::applicationFilePath());
	}
}
