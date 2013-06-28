#pragma once
#include "iobjplug.h"

class CGrowthPlug :
	public IObjPlug
{
public:
	CGrowthPlug();
	~CGrowthPlug();

	virtual void init(CGObject* g);
	virtual void update();
	
	virtual void collide(CGObject* g);

protected:
	CGObject* g;
};
