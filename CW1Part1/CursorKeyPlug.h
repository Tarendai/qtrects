#pragma once
#include "iobjplug.h"

class CCursorKeyPlug :
	public IObjPlug
{
public:
	CCursorKeyPlug();
	~CCursorKeyPlug();
	
	virtual void init(CGObject* g);
	virtual void update();
	virtual void keyPressEvent( QKeyEvent *e );

protected:
	CGObject* g;
};
