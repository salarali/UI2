#include "MyGraphicsView.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <qmessagebox.h>
#include <wchar.h>


void MyGraphicsView::resizeEvent(QResizeEvent* event){
}

MyGraphicsView::MyGraphicsView(QWidget* parent): fieldWidth(742), fieldHeight(542){
	this->setFixedSize(fieldWidth,fieldHeight);	
}

MyGraphicsView::MyGraphicsView(QGraphicsScene* scene,QWidget* parent): fieldWidth(742), fieldHeight(542){
	this->setScene(scene);
	this->setFixedSize(fieldWidth,fieldHeight);	
}

void MyGraphicsView::drawBackground(QPainter* painter, const QRectF& rect){

	int startAngle = 30 * 16;
    int spanAngle = 120 * 16;
	painter->setBrush(Qt::darkGreen);
	painter->setPen(Qt::white);

	QRect mainRect(0,0,740,540);   
	QRect innerRect(67.5,67.5,605,405); 
	QRect middleCircle(320,220,100,100);
	QRect middleLine(370,67.5,0.5,405); 
	QRect goalBox1(37,235,30,70); 
	QRect goalArcLine1(147.5,252.5,0.5,35); 
	QRect goalArc1A(-13,172.5,160,160); 
	QRect goalArc1B(-13,207.5,160,160);
	QRect goalBox2(672,235,30,70); 
	QRect goalArcLine2(593,252.5,0.5,35); 
	QRect goalArc2A(593,172.5,160,160);
	QRect goalArc2B(593,207.5,160,160);

	painter->drawRect(mainRect);
	painter->drawRect(innerRect);
	painter->drawEllipse(middleCircle);
	painter->drawRect(middleLine);
	painter->drawRect(goalBox1);
	painter->drawRect(goalArcLine1);
    painter->drawArc(goalArc1A, 0, 1440); 
    painter->drawArc(goalArc1B, -1440, 1440); 
	painter->drawRect(goalBox2);
	painter->drawRect(goalArcLine2);
    painter->drawArc(goalArc2A, 1440, 1440); 
    painter->drawArc(goalArc2B, -2880, 1440); 
}
