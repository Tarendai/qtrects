#pragma once

#include "glew/glew.h"
#include <qgl.h>

class CW1Part1;

class CGeometry {
public:
	CGeometry();
	CGeometry(CW1Part1* w);
	CGeometry(CW1Part1* w, GLfloat* f);
	virtual ~CGeometry();

	virtual void paintGL();
	virtual void paintatGL(GLfloat x, GLfloat z);

	

	bool alive();

	void rotate(GLfloat degrees);
	GLfloat scale();
	virtual void setScale(GLfloat gscale);

	void setColour(GLfloat r, GLfloat g, GLfloat b);

protected:
	GLfloat* geometry;

	GLfloat grotation;
	GLfloat gscale;

	GLfloat r;
	GLfloat g;
	GLfloat b;

	GLfloat time;
	CW1Part1* w;

};
