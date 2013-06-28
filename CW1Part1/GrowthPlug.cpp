#include "GrowthPlug.h"
#include "GObject.h"

CGrowthPlug::CGrowthPlug(){
}

CGrowthPlug::~CGrowthPlug(){
}

void CGrowthPlug::init(CGObject* g){
	this->g = g;
}

void CGrowthPlug::update(){
	float s = this->g->scale();
	s += 0.001f;
	this->g->setScale(s);
}

void CGrowthPlug::collide(CGObject* g){

}
