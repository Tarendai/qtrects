#include "ShrinkPlug.h"
#include "GObject.h"

CShrinkPlug::CShrinkPlug()
{
}

CShrinkPlug::~CShrinkPlug()
{
}

void CShrinkPlug::init(CGObject* g){
	//
	this->g = g;
}

void CShrinkPlug::update(){
	//
}
void CShrinkPlug::collide(){

}

void CShrinkPlug::collide(CGObject* g){
	//
	float s = this->g->scale();
	s -= 0.1f;
	if(s >= 0.05f){
		this->g->setScale(s);
	}
}
