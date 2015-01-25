#include "triangle.h"

using namespace std;

Triangle::Triangle(const Point& summitA, const Point& summitB, const Point& summitC)
{
	m_sA = Vertex(summitA);
	m_sB = Vertex(summitB);
	m_sC = Vertex(summitC);

	this->setColorf(m_color);
}


Triangle::~Triangle()
{
}

GLfloat* Triangle::renderVertex()
{
	GLfloat* render = new GLfloat[Vertex::VERTEX_SIZE * 3];

	GLfloat* renderedA = m_sA.render();
	GLfloat* renderedB = m_sB.render();
	GLfloat* renderedC = m_sC.render();

	for (int i = 0; i < Vertex::VERTEX_SIZE; i++)
		render[i + 0] = renderedA[i];

	for (int i = 0; i < Vertex::VERTEX_SIZE; i++)
		render[i + 7] = renderedB[i];

	for (int i = 0; i < Vertex::VERTEX_SIZE; i++)
		render[i + 14] = renderedC[i];

	// Memory cleanup
	delete renderedA;
	delete renderedB;
	delete renderedC;

	return render;
}

uint Triangle::getByteSize() const
{
	return 3 * Vertex::VERTEX_SIZE * sizeof(float);
}

uint Triangle::getNumberOfVertices() const
{
	return 3;
}

void Triangle::setSummitAColor(const Colorf& color)
{
	m_sA.color = color;
}

void Triangle::setSummitBColor(const Colorf& color)
{
	m_sB.color = color;
}

void Triangle::setSummitCColor(const Colorf& color)
{
	m_sC.color = color;
}

void Triangle::setColorf(const Colorf& color)
{
	this->setSummitAColor(color);
	this->setSummitBColor(color);
	this->setSummitCColor(color);
}
