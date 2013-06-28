#pragma once
#include "geometry.h"
#include "IObjPlug.h"
#include <set>

class CW1Part1;
class CGObject :
	public CGeometry
{
public:
	CGObject(CW1Part1* w);
	CGObject(CW1Part1* w, GLfloat* f);
	virtual ~CGObject();

	virtual void paintGL();

	void collide();
	void collide(CGObject* g);
	bool collision(CGObject* g);

	virtual void update();

	void add(IObjPlug* p);
	void remove(IObjPlug* p);
	
	void stun();

	float X();
	float Y();

	

	void setPos(float x ,float y);

	float velocityX();
	float velocityY();
	void setVelocity(float x, float y);
	
	virtual void keyPressEvent( QKeyEvent *e );
	
	bool customColour();
	void useCustomColour();
	void setCustomColour(float cr, float cg, float cb);
	void setCustomColour(bool custom);

	virtual void setScale(GLfloat scale);

protected:
	std::set<IObjPlug*> plugs;

	float x;
	float y;

	float x_velocity;
	float y_velocity;

	float radius();

	int gstun;

	bool customcolour;

	float cr, cg,cb;

	float base_radius;
	float cradius;
};
