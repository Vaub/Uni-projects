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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <oglwidget.h>

QT_BEGIN_NAMESPACE

class Ui_QtX64TestClass
{
public:
    QAction *actionSave;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    OGLWidget *openGLWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *saveImage_button;
    QPushButton *generateShape_Button;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *QtX64TestClass)
    {
        if (QtX64TestClass->objectName().isEmpty())
            QtX64TestClass->setObjectName(QStringLiteral("QtX64TestClass"));
        QtX64TestClass->resize(600, 400);
        actionSave = new QAction(QtX64TestClass);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        widget = new QWidget(QtX64TestClass);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setEnabled(false);
        widget->setLayoutDirection(Qt::LeftToRight);
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(9, 9, 9, 9);
        openGLWidget = new OGLWidget(widget);
        openGLWidget->setObjectName(QStringLiteral("openGLWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(openGLWidget->sizePolicy().hasHeightForWidth());
        openGLWidget->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(openGLWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        saveImage_button = new QPushButton(widget);
        saveImage_button->setObjectName(QStringLiteral("saveImage_button"));
        saveImage_button->setEnabled(false);

        horizontalLayout->addWidget(saveImage_button);

        generateShape_Button = new QPushButton(widget);
        generateShape_Button->setObjectName(QStringLiteral("generateShape_Button"));

        horizontalLayout->addWidget(generateShape_Button);


        verticalLayout_2->addLayout(horizontalLayout);

        QtX64TestClass->setCentralWidget(widget);
        menuBar = new QMenuBar(QtX64TestClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        QtX64TestClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtX64TestClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QtX64TestClass->addToolBar(Qt::TopToolBarArea, mainToolBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionSave);

        retranslateUi(QtX64TestClass);

        QMetaObject::connectSlotsByName(QtX64TestClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtX64TestClass)
    {
        QtX64TestClass->setWindowTitle(QApplication::translate("QtX64TestClass", "QtX64Test", 0));
        actionSave->setText(QApplication::translate("QtX64TestClass", "Save", 0));
        actionSave->setShortcut(QApplication::translate("QtX64TestClass", "Ctrl+S", 0));
        saveImage_button->setText(QApplication::translate("QtX64TestClass", "Save", 0));
        generateShape_Button->setText(QApplication::translate("QtX64TestClass", "Generate", 0));
        menuFile->setTitle(QApplication::translate("QtX64TestClass", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class QtX64TestClass: public Ui_QtX64TestClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTX64TEST_H
