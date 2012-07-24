#ifndef SIM_H
#define SIM_H
#include <qtimer.h>
#include <qgraphicsscene.h>
#include <Box2D\Box2D.h>
#include "bot.h"

static const int BODYCOUNT = 6;
static const int32 B2_ITERATIONS = 10;
static const float32 B2_TIMESTEP = 1.0f / 60.0f;

class Simulator: public QObject{
	Q_OBJECT
	private:
	public:
		Simulator(QGraphicsScene *scene, QObject *parent = 0);
		~Simulator();
		int timerId;
		b2World *world;
		b2Body *groundBody;
		QGraphicsScene *scene;
		Bot *bodyItems[BODYCOUNT];
		void start();
	protected:
		void timerEvent(QTimerEvent *event);
};
#endif