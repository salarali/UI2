#ifndef MY_GRAPHICS_SCENE
#define MY_GRAPHICS_SCENE

#include <qgraphicsscene.h>
#include "qgraphicssceneevent.h"
#include "bot.h"

class MyGraphicsScene: public QGraphicsScene{
	Q_OBJECT
	private:
		Bot* selected;
	public:
		MyGraphicsScene();
		virtual void mousePressEvent( QGraphicsSceneMouseEvent* mouseEvent );
		virtual void mouseMoveEvent( QGraphicsSceneMouseEvent* mouseEvent );
		virtual void mouseReleaseEvent( QGraphicsSceneMouseEvent* mouseEvent );
};
#endif