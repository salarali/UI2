#include "async.h"
#include <iostream>

Async::Async(QWidget *parent)
     : QDialog(parent)
{
}

void Async::Receive(QString address, quint16 port)
{
	udpSocket = new QUdpSocket(this);
 	udpSocket->bind(QHostAddress(address),port, QUdpSocket::ShareAddress);
    connect(udpSocket, SIGNAL(readyRead()),this,SLOT(processPendingDatagrams()));

	port_1 = port;
  
}
void Async::processPendingDatagrams()
{
	QString OInMessage;
    QHostAddress PeerIP;

    while (udpSocket->hasPendingDatagrams())
    {
        QByteArray datagram;
        datagram.resize(udpSocket->pendingDatagramSize());
        udpSocket->readDatagram(datagram.data(),datagram.size(),&PeerIP,&port_1);
		OInMessage=datagram.data();
		
		char hello[1024];
		strcpy(hello,datagram.data());
		memset(hello,0,1024);
				
		std::string message = std::string(hello, datagram.size());
		update.update(message);
	}
}

void Async::Send(QByteArray message,QString address, quint16 port)
{
	udpSocket = new QUdpSocket(this);
	QByteArray datagram = message;
	udpSocket->writeDatagram(datagram.data(), datagram.size(), QHostAddress(address), port);
}
