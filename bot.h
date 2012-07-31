#ifndef BOT_H
#define BOT_H 
#include <qgraphicsitem.h>
#include "Box2D\Box2D.h"


static const float PI = 3.14159265359;
class Bot: public QGraphicsPolygonItem{
	private:
		b2World* world;
		b2Body*  botDynamicBody;
		QPolygonF poly;
	public:
		Bot(b2World *w, QGraphicsItem *parent = 0);
		void _init();
		void _update();
		void _setPos(QPointF p);
};

#endif