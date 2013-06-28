#include "RandomSpawnPosPlug.h"
#include "GObject.h"
#include <cstdlib>

CRandomSpawnPosPlug::CRandomSpawnPosPlug(){
}

CRandomSpawnPosPlug::~CRandomSpawnPosPlug(){
}

void CRandomSpawnPosPlug::init(CGObject* g){
	g->setPos(rand()%420-210,rand()%180-90);
	g->remove(this);
}
