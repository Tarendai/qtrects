#include "BouncePlug.h"
#include "GObject.h"

CBouncePlug::CBouncePlug()
{
}

CBouncePlug::~CBouncePlug()
{
}

void CBouncePlug::init(CGObject* g){
	this->g = g;
}

void CBouncePlug::update(){
	//
}

void CBouncePlug::collide(){
	//
}

void CBouncePlug::collide(CGObject* g){
	float xdist = this->g->X() - g->X();
	float ydist = this->g->Y() - g->Y();

	float x_vel = this->g->velocityX();
	x_vel += xdist/50;
	float y_vel = this->g->velocityY();
	y_vel += ydist/50;
	this->g->setVelocity(x_vel,y_vel);

	x_vel = g->velocityX();
	x_vel -= xdist/50;
	y_vel = g->velocityY();
	y_vel -= ydist/50;
	g->setVelocity(x_vel,y_vel);
}
