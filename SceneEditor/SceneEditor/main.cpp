#include "sceneeditor.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	SceneEditor w;
	w.show();
	return a.exec();
}
