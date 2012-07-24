#include "qtest3.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	qtest3 w;
	w.show();
	return a.exec();
}
