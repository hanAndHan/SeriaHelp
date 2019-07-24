#include "seriahelp.h"
#include <QtWidgets/QApplication>
#include <QFile>
class CommonHelper
{
public:
	static void setStyle(const QString &style)
	{
		QFile qss(style);
		qss.open(QFile::ReadOnly);
		qApp->setStyleSheet(qss.readAll());
		qss.close();
	}
};
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	CommonHelper::setStyle("skin.css");
	SeriaHelp w;
	w.setFixedSize(740,399);
	//w.setWindowFlags(Qt::FramelessWindowHint);
	w.show();
	return a.exec();
}
