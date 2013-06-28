#pragma once
#include "iobjplug.h"

class CJerkPlug :
	public IObjPlug
{
public:
	CJerkPlug(void);
	~CJerkPlug(void);
	
	virtual void init(CGObject* g);
	virtual void update();
protected:
	CGObject* g;
	float detriment;
};
