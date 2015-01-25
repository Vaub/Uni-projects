/********************************************************************************
** Form generated from reading UI file 'qtx64test.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTX64TEST_H
#define UI_QTX64TEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "oglwidget.h"

QT_BEGIN_NAMESPACE

class Ui_QtX64TestClass
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    OGLWidget *openGLWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *QtX64TestClass)
    {
        if (QtX64TestClass->objectName().isEmpty())
            QtX64TestClass->setObjectName(QStringLiteral("QtX64TestClass"));
        QtX64TestClass->resize(600, 400);
        widget = new QWidget(QtX64TestClass);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setEnabled(false);
        widget->setLayoutDirection(Qt::LeftToRight);
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        openGLWidget = new OGLWidget(widget);
        openGLWidget->setObjectName(QStringLiteral("openGLWidget"));

        verticalLayout_2->addWidget(openGLWidget);

        QtX64TestClass->setCentralWidget(widget);
        menuBar = new QMenuBar(QtX64TestClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        QtX64TestClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtX64TestClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QtX64TestClass->addToolBar(Qt::TopToolBarArea, mainToolBar);

        retranslateUi(QtX64TestClass);

        QMetaObject::connectSlotsByName(QtX64TestClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtX64TestClass)
    {
        QtX64TestClass->setWindowTitle(QApplication::translate("QtX64TestClass", "QtX64Test", 0));
    } // retranslateUi

};

namespace Ui {
    class QtX64TestClass: public Ui_QtX64TestClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTX64TEST_H
