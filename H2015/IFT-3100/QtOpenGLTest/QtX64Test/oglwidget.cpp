#include "oglwidget.h"

#include <iostream>
#include <fstream>

#include <time.h>
#include <chrono>
#include <thread>

using namespace std;

const uint NUM_FLOATS_PER_VERTICES = 6;

float rng(int min = -1, int max = 1)
{
	return min + (rand() / (double)(RAND_MAX + 1) * (max - min + 1));
}

OGLWidget::~OGLWidget()
{
	while (!m_shapesToDraw.empty())
	{
		Shape* shape = m_shapesToDraw.back();
		m_shapesToDraw.pop_back();

		delete shape;
	}
}

void OGLWidget::initializeGL()
{
	initializeOpenGLFunctions(); // very important if we want to use raw OpenGL
	this->installShaders();

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	srand(time(NULL));

	Colorf colorP(0, 0.5f, 1);
	Colorf colorS(0, 1, 1);

	/*Triangle* t = new Triangle(Point(-0.25f,0, -1),
		Point(0.25f,0, -1),
		Point(0,0.5f, -1));

	t->setColorf(colorP);
	t->setSummitAColor(colorS);
	t->setSummitBColor(colorS);

	m_shapesToDraw.push_back(t);

	t = new Triangle(Point(-0.5f, -0.5f, -1),
		Point(0,-0.5f, -1),
		Point(-0.25f,0, -1));

	t->setColorf(colorP);
	t->setSummitCColor(colorS);

	m_shapesToDraw.push_back(t);

	t = new Triangle(Point(0,-0.5f, -1),
		Point(0.5f,-0.5f, -1),
		Point(0.25f,0, -1));

	t->setColorf(colorP);
	t->setSummitCColor(colorS);

	m_shapesToDraw.push_back(t);*/

	for (int i = 0; i < 10000; i++)
	{
		float transparency = 0.1f;

		Triangle* t = new Triangle(Point(rng(), rng(), rng()),
								   Point(rng(), rng(), rng()),
								   Point(rng(), rng(), rng()));

		t->setSummitAColor(Colorf(rng(), rng(), rng(), rng()));
		t->setSummitBColor(Colorf(rng(), rng(), rng(), rng()));
		t->setSummitCColor(Colorf(rng(), rng(), rng(), rng()));

		m_shapesToDraw.push_back(t);
	}

	this->renderTriangle();
}

void OGLWidget::resizeGL(int w, int h)
{
	glViewport(0, 0, w, h);
}

void OGLWidget::paintGL()
{
	QSize imageSize = this->size();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	this->renderTriangle();
}

void OGLWidget::renderTriangle()
{
	uint allocateByte = 0;
	for (int i = 0; i < m_shapesToDraw.size(); i++)
		allocateByte += m_shapesToDraw[i]->getByteSize();

	GLuint bufferId;
	glGenBuffers(1, &bufferId);
	glBindBuffer(GL_ARRAY_BUFFER, bufferId);
	glBufferData(GL_ARRAY_BUFFER, allocateByte, NULL, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * Vertex::VERTEX_SIZE, 0);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(float) * Vertex::VERTEX_SIZE, (void*)(sizeof(float) * 3));

	int numberOfVertices = 0;
	for (int i = 0; i < m_shapesToDraw.size(); i++)
	{
		Shape* shape = m_shapesToDraw[i];

		GLfloat* vertexArray = shape->renderVertex();
		glBufferSubData(GL_ARRAY_BUFFER, i * shape->getByteSize(), shape->getByteSize(), vertexArray);

		delete vertexArray;

		numberOfVertices += shape->getNumberOfVertices();
	}

	glDrawArrays(GL_TRIANGLES, 0, numberOfVertices);

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
}

void OGLWidget::installShaders()
{
	GLuint vertexShaderId = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);

	const GLchar* adapter[1];
	string vertexCode = readShaderCode("VertexShader.glsl");
	string fragmentCode = readShaderCode("FragmentShader.glsl");

	adapter[0] = vertexCode.c_str();
	glShaderSource(vertexShaderId, 1, adapter, 0);

	adapter[0] = fragmentCode.c_str();
	glShaderSource(fragmentShaderId, 1, adapter, 0);

	glCompileShader(vertexShaderId);
	glCompileShader(fragmentShaderId);
	
	GLuint programId = glCreateProgram();
	glAttachShader(programId, vertexShaderId);
	glAttachShader(programId, fragmentShaderId);
	glLinkProgram(programId);

	glUseProgram(programId);
}

string OGLWidget::readShaderCode(const char* fileName)
{
	ifstream input(fileName);
	if (!input.good())
		exit;

	return std::string(std::istreambuf_iterator<char>(input), std::istreambuf_iterator<char>());
}

void OGLWidget::saveImage()
{
	QImage test = this->grabFramebuffer();
	test.save("hello.png", "PNG");
}
