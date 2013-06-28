#pragma once
#include "iobjplug.h"

class CPulsatorPlug :
	public IObjPlug
{
public:
	CPulsatorPlug();
	~CPulsatorPlug();

	virtual void init(CGObject* g);
	virtual void update();
	
protected:
	CGObject* g;
	float scale;
	bool growing;
	float maxscale;
	float minscale;
};
