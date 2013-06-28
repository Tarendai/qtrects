#include "GObject.h"
#include <math.h>
#include "cw1part1.h"

//float InvSqrt(float x){
//   float xhalf = 0.5f * x;
//   int i = *(int*)&x; // store floating-point bits in integer
//   i = 0x5f3759d5 - (i >> 1); // initial guess for Newton's method
//   x = *(float*)&i; // convert new bits into float
//   x = x*(1.5f - xhalf*x*x); // One round of Newton's method
//   return x;
//}
float InvSqrt (float x)
{
    float xhalf = 0.5f*x;
    int i = *(int*)&x;
    i = 0x5f3759df - (i>>1);
    x = *(float*)&i;
    return x*(1.5f - xhalf*x*x);
}

CGObject::CGObject(CW1Part1* w){
	x = y = 0;
	x_velocity = y_velocity = 0;
	gstun = 0;
	this->w = w;
	customcolour = false;

	base_radius = -1;
}

CGObject::CGObject(CW1Part1* w, GLfloat* f){
	this->w = w;
	customcolour = false;

	base_radius = -1;
}

CGObject::~CGObject(){
	if(!plugs.empty()){
		while(!plugs.empty()){
			IObjPlug* p = *plugs.begin();
			this->remove(p);
		}
	}
}


void CGObject::paintGL(){
	//
	paintatGL(x,y);
}

void CGObject::collide(CGObject* g){
	//counter--;
	if(!plugs.empty()){
		std::set<IObjPlug*>::iterator i;
		for(i = plugs.begin(); i != plugs.end(); ++i){
			//
			IObjPlug* p = (*i);
			p->collide(g);
		}
	}
}

void CGObject::collide(){
	//counter--;
	if(!plugs.empty()){
		std::set<IObjPlug*>::iterator i;
		for(i = plugs.begin(); i != plugs.end(); ++i){
			//
			IObjPlug* p = (*i);
			p->collide();
		}
	}
}
bool CGObject::collision(CGObject* g){
	//
	float v = ((x-g->X())*(x-g->X())) + ((g->Y()-y)*(g->Y()-y));
	float d = 1/InvSqrt(v);
	if(d < g->radius() + radius()){
		return true;
	}
	
	return false;
}

void CGObject::update(){
	if(gscale <= 0){
		// death!
		w->removeObject(this);
		return;
	}

	if(gstun>0){
		gstun--;
	} else{
		if(!plugs.empty()){
			std::set<IObjPlug*>::iterator i;
			for(i = plugs.begin(); i != plugs.end(); ++i){
				//
				IObjPlug* p = (*i);
				p->update();
			}
		}
	}

	float r = radius();
	if(X()+r > 300){
		collide();
	}

	if(X()-r < -300){
		collide();
	}

	if(Y()+r > 190){
		collide();
	}

	if(Y()-r < -190){
		collide();
	}
	setPos(x+x_velocity,y+y_velocity);
}

void CGObject::add(IObjPlug* p){
	plugs.insert(p);
	p->init(this);
}

void CGObject::remove(IObjPlug* p){
	//
	p->dispose();
	plugs.erase(p);
	delete p;
}

void CGObject::stun(){
	gstun += 5;
}

float CGObject::X(){
	return x;
}

float CGObject::Y(){
	return y;
}

void CGObject::setPos(float x ,float y){
	if(x > 300){
		x = 299;
		x_velocity *= -1;
	}
	if(x < -300){
		x = -299;
		x_velocity *= -1;
	}
	if(y > 190){
		y = 189;
		y_velocity *= -1;
	}
	if(y < -190){
		y = -189;
		y_velocity *= -1;
	}
	this->x = x;
	this->y = y;
}

float CGObject::velocityX(){
	return x_velocity;
}

float CGObject::velocityY(){
	return y_velocity;
}

void CGObject::setVelocity(float x, float y){
	y_velocity = y;
	x_velocity = x;
}

void CGObject::keyPressEvent( QKeyEvent *e ){
	if(!plugs.empty()){
		std::set<IObjPlug*>::iterator i;
		for(i = plugs.begin(); i != plugs.end(); ++i){
			//
			IObjPlug* p = (*i);
			p->keyPressEvent(e);
		}
	}
}

bool CGObject::customColour(){
	return customcolour;
}

void CGObject::useCustomColour(){
	setColour(cr,cg,cb);
}

void CGObject::setCustomColour(float cr, float cg, float cb){
	this->cr = cr;
	this->cg = cg;
	this->cb = cb;
}

void CGObject::setCustomColour(bool custom){
	customcolour = custom;
}

float CGObject::radius(){
	//
	if(base_radius == -1){
		base_radius = 0;
		for(int i = 0; i<4; i+=2){
			float x = geometry[i];
			x *= gscale;
			float y = geometry[i+1];
			y *= gscale;
			float r = 1/InvSqrt(((x-0)*(x-0)) + ((0-y)*(0-y)));
			if( r < 0){
				r *= -1;
			}
			if(r > base_radius){
				base_radius = r;
			}
		}
		cradius = base_radius * gscale;
	}
	
	return cradius;
}

void CGObject::setScale(GLfloat scale){
	this->gscale = scale;
	cradius = base_radius * gscale;
}
