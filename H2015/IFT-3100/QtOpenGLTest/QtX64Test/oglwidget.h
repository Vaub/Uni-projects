#pragma once

#include <QOpenGLWidget>
#include <QtOpenGL>

#include <vector>

#include "shape.h"
#include "triangle.h"

class OGLWidget :
	public QOpenGLWidget, protected QOpenGLFunctions
{
public:
	OGLWidget(QWidget* parent) : QOpenGLWidget(parent) { }
	~OGLWidget();

	void saveImage();

protected:
	void initializeGL();
	void resizeGL(int w, int h);
	void paintGL();

private:

	void installShaders();
	std::string readShaderCode(const char* fileName);

	void createTriangleInOGL(Triangle& triangle);
	void renderTriangle();

	std::vector<Shape*> m_shapesToDraw;
};

