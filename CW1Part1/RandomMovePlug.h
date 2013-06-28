#pragma once
#include "iobjplug.h"

class CRandomMovePlug :
	public IObjPlug
{
public:
	CRandomMovePlug();
	~CRandomMovePlug();
	
	virtual void init(CGObject* g);
	virtual void update();
};
