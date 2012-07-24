#include "bot.h"
#include <iostream>
#include <cstdlib>
#include "qmessagebox.h"
#include "Box2D\Box2D.h"


Bot::Bot(b2World *world, QGraphicsItem *parent): QGraphicsPolygonItem(parent), world(world), botDynamicBody(0){
}

void Bot::_update(){
	b2Vec2 position = botDynamicBody->GetPosition();
	float32 angle = botDynamicBody->GetAngle();
	setPos(position.x, -position.y);
	setRotation(-(angle * 360.0) / (2 * PI));
}

void Bot::_init(){

	// Define body
	b2BodyDef botBodyDef;
	botBodyDef.type = b2_dynamicBody;
	botBodyDef.position.Set(x(),-y());
	botBodyDef.angle = -(rotation() * (2 * PI)) / 360.0;

	// Use world object to generate body
	botDynamicBody = world->CreateBody(&botBodyDef);

	// Define shape
	b2PolygonShape botShape;
	botShape.SetAsBox(1,1);

	const QPolygonF &poly = polygon();
	int n = botShape.m_vertexCount = poly.size();
	for (int i = 0; i < n; ++i) {
		const QPointF &p = poly.at(i);
		botShape.m_vertices[i].Set(p.x(), -p.y());
	}

	// Define fixtures
	b2FixtureDef botFixtureDef;
	botFixtureDef.shape = &botShape; // Set previously define shape to fixture shape
	botFixtureDef.density = 3;
	botFixtureDef.friction = 0.5f;
	botDynamicBody->CreateFixture(&botFixtureDef);
}

