#include "qtx64test.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QtX64Test w;
	w.show();
	return a.exec();
}
