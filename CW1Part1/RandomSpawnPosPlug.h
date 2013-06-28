#pragma once
#include "iobjplug.h"

class CRandomSpawnPosPlug :
	public IObjPlug
{
public:
	CRandomSpawnPosPlug();
	~CRandomSpawnPosPlug();
	
	virtual void init(CGObject* g);
	virtual void update(){}
};
