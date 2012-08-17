#ifndef ASYNC_H
#define ASYNC_H

#include <QtGui>
#include <QtNetwork>
#include <QUdpSocket>
#include <QDialog>
#include "simulator.h"

class Async : public QDialog
 {
     Q_OBJECT

public:
    Async(QWidget *parent = 0);
	Simulator update;
	void Receive(QString address, quint16 port);
	void Send(QByteArray message, QString address, quint16 port);
	quint16 port_1;


private slots:
    void processPendingDatagrams();


private:
    QUdpSocket *udpSocket;
};

#endif
