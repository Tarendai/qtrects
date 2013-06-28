#include "PulsatorPlug.h"
#include "GObject.h"

CPulsatorPlug::CPulsatorPlug(){
	//
	minscale = 0.7;
	scale = minscale;
	maxscale = 1.2;
}

CPulsatorPlug::~CPulsatorPlug(){
	//
}

void CPulsatorPlug::init(CGObject* g){
	this->g = g;
}

void CPulsatorPlug::update(){
	//
	if(scale >= maxscale){
		growing = false;
		scale -= 0.02;
		return;
	} else if (scale <= minscale){
		growing = true;
		scale += 0.01;
		return;
	}
	if(growing){
		scale += 0.01;
	} else {
		scale -= 0.01;
	}
	g->setScale(scale);
	
	
}
