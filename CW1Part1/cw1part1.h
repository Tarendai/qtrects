#ifndef CW1PART1_H
#define CW1PART1_H

#include "glew/glew.h"
#include <qgl.h>
#include <set>
#include "GObject.h"

class QTimer;

class CW1Part1 : public QGLWidget
{
	Q_OBJECT
public:
	CW1Part1( int timerInterval=0, QWidget *parent=0, char *name=0 );
	~CW1Part1();

	void addObject(CGObject* o);
	void removeObject(CGObject* o);

	GLuint getProgram(){ return p; }
protected:
	virtual void initializeGL();
	virtual void resizeGL( int width, int height );
	virtual void paintGL();
	virtual void paintOverlayGL();

	virtual void keyPressEvent( QKeyEvent *e );

	virtual void timeOut();

	
  
	
protected slots:
	virtual void timeOutSlot();

private:
	QTimer *m_timer;
	std::set<CGObject*> objects;
	std::set<CGObject*> garbage;

	GLuint v,f,g,g2,p;
};

#endif // CW1PART1_H
