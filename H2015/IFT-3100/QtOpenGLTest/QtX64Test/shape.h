#pragma once

#include <vector>

#include <QtOpenGL>

#include "colorf.h"

class Shape
{
public:
	Shape() : m_color(Colorf(1.0, 1.0, 1.0)) { }
	~Shape();

	virtual GLfloat* renderVertex() = 0;

	virtual void setColorf(const Colorf& color);

	virtual uint getByteSize() const = 0;
	virtual uint getNumberOfVertices() const = 0;

protected:
	Colorf m_color;
};

