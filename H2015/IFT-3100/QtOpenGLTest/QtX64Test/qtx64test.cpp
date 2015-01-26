#include "qtx64test.h"

QtX64Test::QtX64Test(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	QObject::connect(ui.actionSave, SIGNAL(triggered()), this, SLOT(savingImage()));
}

QtX64Test::~QtX64Test()
{

}

void QtX64Test::savingImage()
{
	ui.openGLWidget->saveImage();
}
