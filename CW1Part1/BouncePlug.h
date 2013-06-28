#pragma once
#include "iobjplug.h"

class CBouncePlug :
	public IObjPlug
{
public:
	CBouncePlug();
	~CBouncePlug();
	
	virtual void init(CGObject* g);
	virtual void update();

	virtual void collide();
	virtual void collide(CGObject* g);

protected:
	CGObject* g;
};
