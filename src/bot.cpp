#include "bot.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "qmessagebox.h"
#include "Box2D/Box2D.h"


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
	b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(0.09f, 0.09f);

	b2PolygonShape botShape;
	b2Vec2 vertices[19];

    vertices[0].Set(-0.090000f, 0.000000f);
    vertices[1].Set(-0.087385f, -0.021538f);
    vertices[2].Set(-0.079691f, -0.041825f);
    vertices[3].Set(-0.067366f, -0.059681f);
    vertices[4].Set(-0.051126f, -0.074069f);
    vertices[5].Set(-0.031914f, -0.084151f);
    vertices[6].Set(-0.010848f, -0.089344f);
    vertices[7].Set(0.010848f, -0.089344f);
    vertices[8].Set(0.031914f, -0.084151f);
    vertices[9].Set(0.051126f, -0.074069f);
    vertices[10].Set(0.067366f, -0.059681f);
    vertices[11].Set(0.079691f, -0.041825f);
    vertices[12].Set(0.087385f, -0.021538f);
    vertices[13].Set(0.087385f, 0.021538f);
    vertices[14].Set(0.079691f, 0.041825f);
    vertices[15].Set(0.067366f, 0.059681f);
    vertices[16].Set(-0.067366f, 0.059681f);
    vertices[17].Set(-0.079691f, 0.041825f);
    vertices[18].Set(-0.087385f, 0.021538f);
    int32 count = 19;
	botShape.Set(vertices,count);

	 // Define the dynamic body fixture.
    b2FixtureDef fixtureDef;
    b2FixtureDef fixtureDefTri;
    
    fixtureDef.shape = &dynamicBox;
    fixtureDefTri.shape = &botShape;
	 // Set the box density to be non-zero, so it will be dynamic.
    fixtureDef.density = 1.0f;
    fixtureDefTri.density = 1.0f;
    
    // Override the default friction.
    fixtureDef.friction = 0.3f;
    fixtureDefTri.friction = 0.3f;

    // Add the shape to the body.
    for(unsigned int i = 0; i < 6; i += 1){
        botDynamicBody->CreateFixture(&fixtureDefTri);
    }

	// Renderable definition of polygon
	poly	
	<< QPointF(-0.090000f*100, 0.000000f*100)
	<< QPointF(-0.087385f*100, -0.021538f*100)
	<< QPointF(-0.079691f*100, -0.041825f*100)
	<< QPointF(-0.067366f*100, -0.059681f*100)
	<< QPointF(-0.051126f*100, -0.074069f*100)
	<< QPointF(-0.031914f*100, -0.084151f*100)
	<< QPointF(-0.010848f*100, -0.089344f*100)
	<< QPointF(0.010848f*100, -0.089344f*100)
	<< QPointF(0.031914f*100, -0.084151f*100)
	<< QPointF(0.051126f*100, -0.074069f*100)
	<< QPointF(0.067366f*100, -0.059681f*100)
	<< QPointF(0.079691f*100, -0.041825f*100)
	<< QPointF(0.087385f*100, -0.021538f*100)
	<< QPointF(0.087385f*100, 0.021538f*100)
	<< QPointF(0.079691f*100, 0.041825f*100)
	<< QPointF(0.067366f*100, 0.059681f*100)
	<< QPointF(-0.067366f*100, 0.059681f*100)
	<< QPointF(-0.079691f*100, 0.041825f*100)
	<< QPointF(-0.087385f*100, 0.021538f*100);
	setPolygon(poly);
}


void Bot::_setPos(QPointF p){
	std::printf("%d %d", p.rx(), p.ry());
	setPos(p.rx(),p.ry());
	botDynamicBody->SetTransform(b2Vec2(p.rx(),-p.ry()),botDynamicBody->GetAngle());
}
