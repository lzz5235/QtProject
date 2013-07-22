#ifndef SCHEDUAL_H
#define SCHEDUAL_H

#include <QtGui/QMainWindow>
#include <QTableWidget>
#include <QWidget>
#include <QMenu>
#include <QTableWidgetItem>
#include <QListWidget>
#include <QAction>
#include <QSystemTrayIcon>
#include <QMessageBox>
#include <QTextCodec>
#include <QTime>
//#include <QBluetoothServiceInfo>

#include "Account.h"
#include "ui_schedual.h"
#include "AlertSetting.h"
#include "MusicDlg.h"
#include "DiaryDlg.h"
#include "TeleBookDlg.h"



//class AlertSetting;
class Schedual : public QMainWindow
{
	Q_OBJECT

public:
	Schedual(Account *acc,QWidget *parent = 0, Qt::WFlags flags = 0);
	~Schedual();
	void InitToolBar();
	void InitTable();
	void InitMenuTool();
	void ClockInit();
	void GetData();
	void SetNoteText();
	void initTrayIcon();


private slots: 
        void BlueTooth();
		void Exit();
		void Aboub();
		void AlertSet();
		void MusicSet();
		void DiarySet();
		void TeleSet();
		void on_clicked_listWidget(QTableWidgetItem *item);
		void on_clicked_listWidget_Right(const QPoint &pos);
		void ClockChange();
		void AutoRun();
		void SchedualHelpDocument();		
		void Flush();//Ë¢ÐÂ
		

private:
	Ui::SchedualClass ui;
	QStringList headers;
	AlertSetting *Dlg;
	MusicDlg *MuDlg;
	DiaryDlg *DiaDlg;
	TeleBookDlg *teleDlg;

	QString ID,Date,Topic,Detail;
	int numRows;
	int selectRows;
	QTimer *timer;
	QTimer *flush;
	QAction *minAction;
	QAction *restoreAction;
	QAction *aboutAction;
	QAction *quitAction;
	QAction *DeleteAction;
	QAction *Others;
	QMenu *trayIconMenu;
	QSystemTrayIcon *trayIcon;
	Account *acc;
};

#endif // SCHEDUAL_H
