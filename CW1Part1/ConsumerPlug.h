#pragma once
#include "iobjplug.h"

class CConsumerPlug :
	public IObjPlug
{
public:
	CConsumerPlug();
	~CConsumerPlug();
	
	virtual void init(CGObject* g);
	virtual void update();
	
	virtual void collide(CGObject* g);

protected:
	CGObject* g;
	float detriment;
};
