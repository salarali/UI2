#ifndef QTEST3_H
#define QTEST3_H

#include <QtGui/QWidget>
#include "ui_qtest3.h"

class qtest3 : public QWidget
{
	Q_OBJECT

public:
	qtest3(QWidget *parent = 0, Qt::WFlags flags = 0);
	~qtest3();

private:
	Ui::qtest3Class ui;
};

#endif // QTEST3_H
