#pragma once
#include "iobjplug.h"

class CDragPlug :
	public IObjPlug
{
public:
	CDragPlug(float magnitude = 0.05f);
	~CDragPlug();
	
	virtual void init(CGObject* g);
	virtual void update();

protected:
	CGObject* g;
	float magnitude;
};
