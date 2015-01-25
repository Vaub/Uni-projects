#pragma once

#include "point.h"
#include "colorf.h"

class Vertex
{
public:
	static const uint VERTEX_SIZE = 7;

	explicit Vertex(float x = 0, 
		   float y = 0, 
		   float z = 0, 
		   const Colorf& color = Colorf())
		: x(x), y(y), z(z), color(color)
	{
	}

	Vertex(const Point& point, const Colorf& color = Colorf())
		: x(point.x), y(point.y), z(point.z), color(color)
	{
	}

	~Vertex()
	{
	}

	GLfloat* render()
	{
		GLfloat* rendered = new GLfloat[VERTEX_SIZE];

		rendered[0] = x;
		rendered[1] = y;
		rendered[2] = z;

		rendered[3] = color.red();
		rendered[4] = color.green();
		rendered[5] = color.blue();
		rendered[6] = color.alpha();

		return rendered;
	}

	float x, y, z;
	Colorf color;
};

