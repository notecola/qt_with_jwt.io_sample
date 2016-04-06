#include "qtsample.h"
#include <QtWidgets/QApplication>
#include <QStandardPaths>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	qtsample w;

	QString strSettingsFile = QStandardPaths::writableLocation(QStandardPaths::TempLocation);
	strSettingsFile += "/test.ini";
	
	if (!w.Init(strSettingsFile))
	{
		//we may want to do something if we cannot start
		exit(-1);
	}

	w.show();
	return a.exec();
}
