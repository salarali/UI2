#include "Simulator.h"
#include <qtimer.h>
#include <qobject.h>
#include <qtimeline.h>
#include <qbasictimer.h>
#include <qtimerevent>

Simulator::Simulator(QGraphicsScene *scene, QObject *parent): QObject(parent), timerId(0), scene(scene){
			// Define the gravity vector.
			b2Vec2 gravity(0.0f,-10.0f);
			world = new b2World(gravity);

			b2BodyDef bodyDef;
			b2PolygonShape shapeDef;
			b2FixtureDef fixtureDef;

			bodyDef.position.Set(200.0f,-250);
			shapeDef.SetAsBox(100.0f, 10.0f);
			fixtureDef.shape = &shapeDef;
			groundBody = world->CreateBody(&bodyDef);
			groundBody->CreateFixture(&fixtureDef);

			// Create lots of little colored triangles, random pos, rotation, color.
			for (int i = 0; i < BODYCOUNT; ++i) { 
				Bot* polygon = bodyItems[i] = new Bot(world);
				polygon->setPos(200+-20 + qrand() % 40,200+ -75 - qrand() % 150);
				polygon->setRotation(qrand() % 360);
				polygon->setBrush(QColor(128 + qrand() % 128, 128 + qrand() % 128, 128 + qrand() % 128));
				polygon->_init();
				scene->addItem(polygon);
			}
}

Simulator::~Simulator(){
	delete world;
}

void Simulator::timerEvent(QTimerEvent *event){
	 if (event->timerId() == timerId) {
            world->Step(B2_TIMESTEP, B2_ITERATIONS, 0);
            for (int i = 0; i < BODYCOUNT; ++i)
				bodyItems[i]->_update();
        }
        QObject::timerEvent(event);
}

void Simulator::start(){
	 if (!timerId)
            timerId = startTimer(1000 / 60.0);
}