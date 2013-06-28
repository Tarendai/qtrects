#pragma once
#include "GObject.h"

class CRotatorPlug :
	public IObjPlug
{
public:
	CRotatorPlug();
	~CRotatorPlug();
	
	virtual void init(CGObject* g);
	virtual void update();
	
protected:
	CGObject* g;
	float rotation;
};
