#include "RotatorPlug.h"

CRotatorPlug::CRotatorPlug(){
	//
	rotation = 0;
}

CRotatorPlug::~CRotatorPlug(){
	//
}

void CRotatorPlug::init(CGObject* g){
	this->g = g;
}

void CRotatorPlug::update(){
	//
	rotation++;
	g->rotate(rotation);
}
