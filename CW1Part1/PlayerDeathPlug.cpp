#include "PlayerDeathPlug.h"
#include "GObject.h"
#include "CW1Part1.h"

#include "RotatorPlug.h"
#include "PulsatorPlug.h"
#include "CursorKeyPlug.h"
#include "DragPlug.h"
#include "RandomSpawnPosPlug.h"
#include "BouncePlug.h"
#include "ShrinkPlug.h"
#include "GrowthPlug.h"
#include "ConsumerPlug.h"

CPlayerDeathPlug::CPlayerDeathPlug(CW1Part1* w){
	this->w = w;
}

CPlayerDeathPlug::~CPlayerDeathPlug(){
}

void CPlayerDeathPlug::init(CGObject* g){
	//
	this->g = g;
}

void CPlayerDeathPlug::update(){
	//
}

void CPlayerDeathPlug::dispose(){

	CGObject* c = new CGObject(w);
	c->add(new CRotatorPlug());
	c->add(new CConsumerPlug());
	c->add(new CCursorKeyPlug());
	c->add(new CPlayerDeathPlug(w));
	c->add(new CDragPlug(0.08f));
	c->add(new CBouncePlug());
	w->addObject(c);
}
