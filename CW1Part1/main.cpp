#include "cw1part1.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a( argc, argv );
	
	CW1Part1 *w = new CW1Part1(1);
	//w->show();
	a.setActiveWindow(w);//setMainWidget( w );
	w->show();
	return a.exec();
}
