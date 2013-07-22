#include "schedual.h"
#include "windows.h"
#include <QWaitCondition>



void Schedual::Flush()
{
	acc->ReturnVector(2).clear();
	acc->GetSchedualData();
	GetData();
}
void Schedual::BlueTooth()
{
	ShellExecuteA(NULL,"open","C:\\Users\\lzz\\Documents\\Visual Studio 2008\\Projects\\ศํผþสตัต\\schedual_v2\\schedual_v2\\Mobile.jar", NULL, NULL, SW_SHOWNORMAL);
}
void Schedual::Exit()
{
	close();
}
void Schedual::Aboub()
{
	QApplication::aboutQt ();
}