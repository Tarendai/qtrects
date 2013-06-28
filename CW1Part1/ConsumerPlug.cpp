#include "ConsumerPlug.h"
#include "GObject.h"
#include <algorithm>

CConsumerPlug::CConsumerPlug(){
	detriment  = 1;
}

CConsumerPlug::~CConsumerPlug(){
}

void CConsumerPlug::init(CGObject* g){
	//
	this->g = g;
	g->setCustomColour(true);
	g->setCustomColour(1,1,0);
}

void CConsumerPlug::update(){
	//
	g->setColour(1,1,0);
}

void CConsumerPlug::collide(CGObject* g){
	//
	g->setColour(1,1,0);
	float s = g->scale();
	float gs = this->g->scale();
	if(s < gs){
		//g->stun();
		detriment += 0.3;
	}else {
		detriment -= 0.05;
	}
	float d = (std::min)((0.25f*gs),s);
	
	s -= d;
	g->setScale(s);
	s =  gs;
	d = (std::min)(((0.25f/detriment)*gs),s);
	s += d;
	s = (std::min)(s,9.0f);
	this->g->setScale(s);
}
