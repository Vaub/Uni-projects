#pragma once

#include "shape.h"

#include "vertex.h"
#include "point.h"

class Triangle : public Shape
{
public:
	Triangle(const Point& summitA, 
			 const Point& summitB, 
			 const Point& summitC);

	~Triangle();

	virtual GLfloat* renderVertex();

	virtual uint getByteSize() const;
	virtual uint getNumberOfVertices() const;

	void setSummitAColor(const Colorf& color);
	void setSummitBColor(const Colorf& color);
	void setSummitCColor(const Colorf& color);

	virtual void setColorf(const Colorf& color);

protected:
	Vertex m_sA;
	Vertex m_sB;
	Vertex m_sC;
};

