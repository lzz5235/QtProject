#ifndef MUSIC_H
#define MUSIC_H

#include <QtGui/QMainWindow>
#include <QSettings>
#include <QFileDialog>
#include <QToolBar>
#include <QMessageBox>
#include <QAction>
#include <QLCDNumber>
#include <QTime>
#include <QTableWidget>
#include <QDesktopServices>
#include <QMenu>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QString>
#include <QSettings>
#include <phonon/audiooutput.h>
#include <phonon/seekslider.h>
#include <phonon/mediaobject.h>
#include <phonon/volumeslider.h>
#include <phonon/backendcapabilities.h>
#include <QList>
#include "ui_MusicDlg.h"


class MusicDlg : public QMainWindow
{
	Q_OBJECT
public:
	MusicDlg(QWidget *parent = 0, Qt::WFlags flags = 0);
	~MusicDlg();

	QSize sizeHint() const {
        return QSize(500, 300);
   }
	void ReadConfig();

private slots:
    void addFiles();
    void about();
//![1]
    void stateChanged(Phonon::State newState, Phonon::State oldState);
    void tick(qint64 time);
    void sourceChanged(const Phonon::MediaSource &source);
    void metaStateChanged(Phonon::State newState, Phonon::State oldState);
    void aboutToFinish();
    void tableClicked(int row, int column);
	//void on_ModifyMusic();
//![1]

private:
	Ui::Dialog ui;
    void setupActions();
    void setupMenus();
    void setupUi();    

//![2]
    Phonon::SeekSlider *seekSlider;
    Phonon::MediaObject *mediaObject;
    Phonon::MediaObject *metaInformationResolver;
    Phonon::AudioOutput *audioOutput;
    Phonon::VolumeSlider *volumeSlider;
    QList<Phonon::MediaSource> sources;
//![2]

    QAction *playAction;
    QAction *pauseAction;
    QAction *stopAction;
    QAction *nextAction;
    QAction *previousAction;
    QAction *addFilesAction;
    QAction *exitAction;
    QAction *aboutAction;
    QAction *aboutQtAction;
    QLCDNumber *timeLcd;
    QTableWidget *musicTable;
	QMenu *fileMenu;
	QMenu *aboutMenu;
	QString MusicPath;
	QSettings *ConfigIni;
};


#endif