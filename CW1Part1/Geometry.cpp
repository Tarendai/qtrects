#include "Geometry.h"
#include "cw1part1.h"


CGeometry::CGeometry(){
	time = 0;
	gscale = 1;
	grotation = 25.0f;
	geometry = new GLfloat[10];
	geometry[0] = -5;
	geometry[1] = -5;
	geometry[2] = -5;
	geometry[3] = 5;
	geometry[4] = 5;
	geometry[5] = 5;
	geometry[6] = 5;
	geometry[7] = -5;
	geometry[8] = -5;
	geometry[9] = -5;

	setColour(1,1,1);
}

CGeometry::CGeometry(CW1Part1* w){
	time = 0;
	this->w = w;
	gscale = 1;
	grotation = 25.0f;
	geometry = new GLfloat[10];
	geometry[0] = -5;
	geometry[1] = -5;
	geometry[2] = -5;
	geometry[3] = 5;
	geometry[4] = 5;
	geometry[5] = 5;
	geometry[6] = 5;
	geometry[7] = -5;
	geometry[8] = -5;
	geometry[9] = -5;

	setColour(1,1,1);

}

CGeometry::CGeometry(CW1Part1* w, GLfloat* f){
	time = 0;
	this->w = w;
	gscale = 1;
	grotation = 25.0f;
	geometry = f;
	setColour(1,1,1);

}

CGeometry::~CGeometry(){
	//
	delete[] geometry;
}

void CGeometry::paintGL(){
	paintatGL(200,200);
}

void CGeometry::paintatGL(GLfloat x, GLfloat z){
	//
	glPushMatrix();
	{
		time++;
		GLint location = glGetUniformLocation(w->getProgram(), "time");
		glUniform1f(location, time);
		location = glGetUniformLocation(w->getProgram(), "useTexture");
		glUniform1f(location, 0);
		glTranslatef(x,z,0);
		glRotatef(grotation,0,0,1);
		glScalef(gscale,gscale,gscale);
		
		glLineWidth(3.0f);
		
		glEnableClientState(GL_VERTEX_ARRAY);
		
		glVertexPointer(2, GL_FLOAT, 0, geometry);
		
		glColor4f(r,g,b,0.4f);
		
		glDrawArrays(GL_QUADS, 0, 4);

		glColor4f(r,g,b,1.0f);
		glDrawArrays(GL_LINE_LOOP, 0, 4);

		glDisableClientState(GL_VERTEX_ARRAY);
		glUniform1f(location, 1);

	}
	glPopMatrix();
}

bool CGeometry::alive(){
	//
	return gscale > 0.0f;
}

void CGeometry::rotate(GLfloat degrees){
	//
	this->grotation = degrees;
}

GLfloat CGeometry::scale(){
	return this->gscale;
}

void CGeometry::setScale(GLfloat scale){
	this->gscale = scale;
}

void CGeometry::setColour(GLfloat r, GLfloat g, GLfloat b){
	//
	this->r = r;
	this->g = g;
	this->b = b;
}