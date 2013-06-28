#include "cw1part1.h"

#include "RotatorPlug.h"
#include "PulsatorPlug.h"
#include "CursorKeyPlug.h"
#include "DragPlug.h"
#include "RandomSpawnPosPlug.h"
#include "BouncePlug.h"
#include "ShrinkPlug.h"
#include "GrowthPlug.h"
#include "ConsumerPlug.h"
#include "PlayerDeathPlug.h"

#include <qapplication.h>
#include <qtimer.h>
#include <qfile.h>
#include <qtextstream.h>
#include <string>

#include <QKeyEvent>
#include <cstdlib>
#include <ctime>


CW1Part1::CW1Part1( int timerInterval, QWidget *parent, char *name ){
	srand((unsigned)time(0));

	if( timerInterval == 0 ){
		m_timer = 0;
	} else {
		m_timer = new QTimer( this );
		connect( m_timer, SIGNAL(timeout()), this, SLOT(timeOutSlot()) );
		m_timer->start( timerInterval );
	}
}

CW1Part1::~CW1Part1(){
	// cleanup shaders
	glDetachShader(p, v);
	glDetachShader(p, f);

	glDeleteShader(v);
	glDeleteShader(f);
	glDeleteProgram(p);
}

void CW1Part1::addObject(CGObject* o){
	//
	objects.insert(o);
}

void CW1Part1::removeObject(CGObject* o){
	garbage.insert(o);
}

//protected:
void printShaderInfoLog(GLuint obj)
{
    int infologLength = 0;
    int charsWritten  = 0;
    char *infoLog;

	glGetShaderiv(obj, GL_INFO_LOG_LENGTH,&infologLength);

    if (infologLength > 0)
    {
        infoLog = (char *)malloc(infologLength);
        glGetShaderInfoLog(obj, infologLength, &charsWritten, infoLog);
		printf("%s\n",infoLog);
        free(infoLog);
    }
}

void printProgramInfoLog(GLuint obj)
{
    int infologLength = 0;
    int charsWritten  = 0;
    char *infoLog;

	glGetProgramiv(obj, GL_INFO_LOG_LENGTH,&infologLength);

    if (infologLength > 0)
    {
        infoLog = (char *)malloc(infologLength);
        glGetProgramInfoLog(obj, infologLength, &charsWritten, infoLog);
		printf("%s\n",infoLog);
        free(infoLog);
    }
}

std::string loadFile(const char* filename){
	QFile myFile(filename); // Create a file handle for the file named "testFile"
	QString f;
	
	if (!myFile.open(QIODevice::OpenModeFlag::ReadOnly)) // Open the file
	{
		return "";
	}

	QTextStream stream( &myFile ); // Set the stream to read from myFile
	f = stream.readAll();

	std::string s = f.toStdString();
	return s;
}

void CW1Part1::initializeGL(){

	GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		/* Problem: glewInit failed, something is seriously wrong. */
		fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
	}
	fprintf(stdout, "Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));
	glClearColor(0.05f, 0.05f, 0.2f, 0.0f);

	glEnable (GL_LINE_SMOOTH);
	glEnable (GL_BLEND);
	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glHint (GL_LINE_SMOOTH_HINT, GL_NICEST);
	glDisable(GL_DEPTH_TEST);

	CGObject* c = new CGObject(this);
	c->add(new CRotatorPlug());
	c->add(new CConsumerPlug());
	c->add(new CCursorKeyPlug());
	c->add(new CDragPlug(0.04f));
	c->add(new CPlayerDeathPlug(this));
	c->add(new CBouncePlug());
	this->objects.insert(c);

	std::string vs = loadFile("box.vert");
	std::string fs = loadFile("box.frag");
	std::string gs;
	const char * vv = vs.c_str();
	const char * ff = fs.c_str();
	const char * gg;

	if(GL_EXT_geometry_shader4){
		gs = loadFile("box.geom");
		gg = gs.c_str();
	}
	
	v = glCreateShader(GL_VERTEX_SHADER);
	f = glCreateShader(GL_FRAGMENT_SHADER);

	if(GL_EXT_geometry_shader4){
		g = glCreateShader(GL_GEOMETRY_SHADER_EXT);
	}

	glShaderSource(v, 1, &vv,NULL);
	glShaderSource(f, 1, &ff,NULL);
	if(GL_EXT_geometry_shader4){
		glShaderSource(g, 1, &gg,NULL);
	}

	glCompileShader(v);
	glCompileShader(f);
	printShaderInfoLog(v);
	printShaderInfoLog(f);

	if(GL_EXT_geometry_shader4){
		glCompileShader(g);
		printShaderInfoLog(g);
	}

	p = glCreateProgram();
	glAttachShader(p,f);
	glAttachShader(p,v);
	/*if(GL_EXT_geometry_shader4){
		glAttachShader(p,g);

		glProgramParameteriEXT(p,GL_GEOMETRY_INPUT_TYPE_EXT,GL_QUADS);
		glProgramParameteriEXT(p,GL_GEOMETRY_OUTPUT_TYPE_EXT,GL_QUADS);

		int temp;
		glGetIntegerv(GL_MAX_GEOMETRY_OUTPUT_VERTICES_EXT,&temp);
		glProgramParameteriEXT(p,GL_GEOMETRY_VERTICES_OUT_EXT,temp);
	}*/

	glLinkProgram(p);
	printProgramInfoLog(p);
	glUseProgram(p);

}

void CW1Part1::resizeGL( int width, int height ){
	height = height?height:1;

	glViewport( 0, 0, (GLint)width, (GLint)height );

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,500.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void CW1Part1::paintGL(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glColor4f(1,1,1,1);
	renderText(30,50,"Box", QFont("arial",16));
	glColor4f(1,1,1,0.5f);

	
	renderText(35,70,"Tom J Nowell, Coursework 1 Part 1", QFont("arial",10));
	QString s;
	s = s.setNum(objects.size());
	s.append(" objects");
	renderText(35,85,s, QFont("arial",10));

	glTranslatef(0,0.0f,-499.0f);
	if(!objects.empty()){
		std::set<CGObject*>::iterator i;
		for(i = objects.begin();i != objects.end(); ++i){
			//
			CGObject* g = (*i);
			if(g->alive()){
				g->paintGL();
			}
		}
	}
	
}

void CW1Part1::paintOverlayGL(){
	//
	glColor4f(1,1,1,1);
	this->renderText(50,50,"hallo");
}

void CW1Part1::keyPressEvent( QKeyEvent *e ){
	switch( e->key() ) {
		case Qt::Key_Escape: {
			close();
			break;
		}
		case Qt::Key_H: {
			for(int i = 0; i <4; i++){
				CGObject* c = new CGObject(this);
				c->add(new CRotatorPlug());
				c->add(new CShrinkPlug());
				c->add(new CPulsatorPlug());
				c->add(new CDragPlug(0.015f));
				c->add(new CBouncePlug());
				this->objects.insert(c);
			}
			break;
		}
		case Qt::Key_J: {
			for(int i = 0; i <4; i++){
				CGObject* c = new CGObject(this);
				c->add(new CRotatorPlug());
				c->add(new CShrinkPlug());
				c->add(new CPulsatorPlug());
				c->add(new CRandomSpawnPosPlug());
				c->add(new CDragPlug(0.015f));
				c->add(new CBouncePlug());
				this->objects.insert(c);
			}
			break;
		}
		case Qt::Key_K: {
			for(int i = 0; i <4; i++){
				CGObject* c = new CGObject(this);
				c->add(new CRotatorPlug());
				c->add(new CShrinkPlug());
				c->add(new CGrowthPlug());
				c->add(new CRandomSpawnPosPlug());
				c->add(new CDragPlug(0.015f));
				c->add(new CBouncePlug());
				this->objects.insert(c);
			}
			break;
		}
		case Qt::Key_L: {
			for(int i = 0; i <4; i++){
				CGObject* c = new CGObject(this);
				c->add(new CRotatorPlug());
				c->add(new CConsumerPlug());
				c->add(new CRandomSpawnPosPlug());
				c->add(new CDragPlug(0.0005f));
				c->add(new CBouncePlug());
				this->objects.insert(c);
			}
			break;
		}
						

	}
	if(!objects.empty()){
		std::set<CGObject*>::iterator i;
		for(i = objects.begin();i != objects.end(); ++i){
			//
			CGObject* g = (*i);
			if(g->alive()){
				g->keyPressEvent(e);
			}
		}
	}
}

void CW1Part1::timeOut(){
	if(!garbage.empty()){
		std::set<CGObject*>::iterator i;
		for(i = garbage.begin();i != garbage.end(); ++i){
			//
			CGObject* g = (*i);
			delete g;
			objects.erase(g);
		}
		garbage.erase(garbage.begin(),garbage.end());
		garbage.clear();
	}
	if(!objects.empty()){
		std::set<CGObject*>::iterator i;
		for(i = objects.begin();i != objects.end(); ++i){
			//
			CGObject* g = (*i);
			if(g->alive()){
				g->update();
			} else {
				this->removeObject(g);
			}
		}
	}
	if(!objects.empty()){
		objects.size();
		std::set<CGObject*>::iterator i;
		for(i = objects.begin();i != objects.end(); ++i){
			CGObject* g = (*i);
			if(g->alive()){
				std::set<CGObject*>::iterator j = objects.find(g);
				if(j == objects.end()){
					continue;
				}
				j++;
				if(j == objects.end()){
					continue;
				}
				bool collide = false;
				for(;j != objects.end(); ++j){
					CGObject* g2 = (*j);
					if(g2 == g){
						continue;
					}
					if(g2->collision(g)){
						g->collide(g2);
						g2->collide(g);
						collide = true;
						break;
					}
				}
				if(collide){
					g->setColour(1,0,0);
				} else {
					if(!g->customColour()){
						g->setColour(1,1,1);
					} else{
						g->useCustomColour();
					}
				}
				g->update();
			}
		}
	}
	this->repaint();
}

void CW1Part1::timeOutSlot(){
	//
	timeOut();
}
