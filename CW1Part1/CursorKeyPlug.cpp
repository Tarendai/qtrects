#include "CursorKeyPlug.h"
#include "GObject.h"

CCursorKeyPlug::CCursorKeyPlug(){
	//
}

CCursorKeyPlug::~CCursorKeyPlug(){
	//
}

void CCursorKeyPlug::init(CGObject* g){
	//
	this->g = g;
	g->setCustomColour(true);
}

void CCursorKeyPlug::update(){
	//
	g->setColour(0,1,0);
}

void CCursorKeyPlug::keyPressEvent( QKeyEvent *e ){
	//
	float vx = g->velocityX();
	float vy = g->velocityY();
	if(e->key() == Qt::Key_Up){
		vy += 0.5f;
	}
	if(e->key() == Qt::Key_Down){
		vy -= 0.5f;
	}
	if(e->key() == Qt::Key_Left){
		vx -= 0.5f;
	}
	if(e->key() == Qt::Key_Right){
		vx += 0.5f;
	}
	g->setVelocity(vx,vy);
}
