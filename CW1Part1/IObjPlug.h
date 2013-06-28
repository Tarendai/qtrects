#pragma once

#include <QKeyEvent>

class CGObject;

class IObjPlug {
public:
	virtual void init(CGObject* g)=0;
	virtual void update()=0;

	virtual void keyPressEvent( QKeyEvent *e ){}

	virtual void collide(){}
	virtual void collide(CGObject* g){}

	virtual void dispose(){}
};
