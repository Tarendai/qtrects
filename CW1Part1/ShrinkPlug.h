#pragma once
#include "iobjplug.h"

class CShrinkPlug :
	public IObjPlug
{
public:
	CShrinkPlug();
	~CShrinkPlug();
	
	virtual void init(CGObject* g);
	virtual void update();
	
	virtual void collide();
	virtual void collide(CGObject* g);

protected:
	CGObject* g;
};
