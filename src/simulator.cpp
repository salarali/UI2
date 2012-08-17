#include "simulator.h"
#include <qtimer.h>
#include <qobject.h>
#include <qtimeline.h>
#include <qbasictimer.h>
#include <QTimerEvent>
#include "async.h"
#include <iostream>

#include "messages_robocup_ssl_wrapper.pb.h"
#include "messages_robocup_ssl_detection.pb.h"
#include "messages_robocup_ssl_geometry.pb.h"

Simulator::Simulator(QGraphicsScene *scene, QObject *parent): QObject(parent), timerId(0), scene(scene){
			// Define the gravity vector.
			b2Vec2 gravity(0.0f,-0.0f);
			world = new b2World(gravity,true);

			b2BodyDef bodyDef;
			b2PolygonShape shapeDef;
			b2FixtureDef fixtureDef;

			bodyDef.position.Set(0,-2.7);
			shapeDef.SetAsBox(3.7,0.01f);
			fixtureDef.shape = &shapeDef;
			groundBody = world->CreateBody(&bodyDef);
			groundBody->CreateFixture(&fixtureDef);

//			bodyDef.position.Set(0,0);
//			shapeDef.SetAsBox(3.7,0.01f);
//			fixtureDef.shape = &shapeDef;
//			groundBody = world->CreateBody(&bodyDef);
//			groundBody->CreateFixture(&fixtureDef);
//			
//			Async hello;
//			hello.Receive("127.0.0.1",30011);
//			hello.show();
//			hello.hide();
						
			
//			bodyDef.position.Set(0,0);
//			shapeDef.SetAsBox(0.01f,2.7f);
//			fixtureDef.shape = &shapeDef;
//			groundBody = world->CreateBody(&bodyDef);
//			groundBody->CreateFixture(&fixtureDef);

//			bodyDef.position.Set(3.7f,0);
//			shapeDef.SetAsBox(3.7f,2.7f);
//			fixtureDef.shape = &shapeDef;
//			groundBody = world->CreateBody(&bodyDef);
//			groundBody->CreateFixture(&fixtureDef);

			SSL_WrapperPacket packet;
			std::cout << packet.ParseFromString(data) << std::endl;
			
			std::cout << packet.detection().robots_blue(0).x() << std::endl;



			
			// Create lots of little colored triangles, random pos, rotation, color.
			for (int i = 0; i < BODYCOUNT; ++i) {
				//poly << QPointF(0, -10) << QPointF(-5, 0) << QPointF(5, 0);
				Bot* polygon = bodyItems[i] = new Bot(world);
				polygon->_init();
				//polygon->_setPos(QPointF(qrand()%20, qrand()%20));
				polygon->_setPos(QPointF(200, 0));				
				polygon->setRotation(qrand() % 360);
				polygon->setBrush(QColor(128 + qrand() % 128, 128 + qrand() % 128, 128 + qrand() % 128));
				scene->addItem(polygon);
			}
}

Simulator::Simulator(){
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

void Simulator::update(std::string message)
{
	data = message;
}
