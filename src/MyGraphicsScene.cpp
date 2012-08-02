#include "MyGraphicsScene.h"
#include <iostream>
#include "qgraphicsscene.h"
#include "qgraphicsitem.h"
#include "qlist.h"
#include "qmath.h"
#include "bot.h"

MyGraphicsScene::MyGraphicsScene(): QGraphicsScene(){
	selected = NULL;
}
void MyGraphicsScene::mousePressEvent( QGraphicsSceneMouseEvent* mouseEvent ){
	QPointF mousePos = mouseEvent->scenePos();
	QList<QGraphicsItem*> sceneItems = this->items();
	QList<QGraphicsItem*>::iterator it;
	for( it = sceneItems.begin(); it != sceneItems.end(); it++ ){
		QPointF itemPos = (*it)->pos();
		if( (int)abs(mousePos.rx() - itemPos.rx()) < 10 && (int)abs(mousePos.ry() - itemPos.ry()) < 10){
			selected = (Bot*)(*it);
		}
	}
}

void MyGraphicsScene::mouseMoveEvent( QGraphicsSceneMouseEvent* mouseEvent ){
	if(selected != NULL){
		selected->_setPos(QPointF(mouseEvent->scenePos().rx(),mouseEvent->scenePos().ry()));
	}
}

void MyGraphicsScene::mouseReleaseEvent( QGraphicsSceneMouseEvent* mouseEvent ){
	if(selected != NULL){
	}
}