#ifndef QTX64TEST_H
#define QTX64TEST_H

#include <QtWidgets/QMainWindow>
#include "ui_qtx64test.h"

class QtX64Test : public QMainWindow
{
	Q_OBJECT

public:
	QtX64Test(QWidget *parent = 0);
	~QtX64Test();

private:
	Ui::QtX64TestClass ui;
};

#endif // QTX64TEST_H
