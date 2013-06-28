#include "DragPlug.h"
#include "GObject.h"

CDragPlug::CDragPlug(float magnitude){
	this->magnitude = magnitude;
}

CDragPlug::~CDragPlug(){
}


void CDragPlug::init(CGObject* g){
	this->g = g;
}

void CDragPlug::update(){
	//

	float y_vel = g->velocityY();
	float x_vel = g->velocityX();

	if((y_vel <magnitude)&&(y_vel > -magnitude)){
		y_vel = 0;
	}
	if(y_vel > 0){
		y_vel -= magnitude;
	} else if( y_vel < 0){
		y_vel += magnitude;
	}

	if((x_vel <magnitude)&&(x_vel > -magnitude)){
		x_vel = 0;
	}
	if(x_vel > 0){
		x_vel -= magnitude;
	} else if( x_vel < 0){
		x_vel += magnitude;
	}
	g->setVelocity(x_vel,y_vel);
}
