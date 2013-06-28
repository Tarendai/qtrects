#pragma once
#include "iobjplug.h"

class CW1Part1;
class CPlayerDeathPlug :
	public IObjPlug
{
public:
	CPlayerDeathPlug(CW1Part1* w);
	virtual ~CPlayerDeathPlug();
	
	virtual void init(CGObject* g);
	virtual void update();
	virtual void dispose();
protected:
	CW1Part1* w;
	CGObject* g;
	float detriment;
};
