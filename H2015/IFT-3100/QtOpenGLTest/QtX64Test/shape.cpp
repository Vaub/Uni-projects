#include "shape.h"

const uint FLOATS_PER_VERTICES = 6;

Shape::~Shape()
{
}

void Shape::setColorf(const Colorf& color)
{
	m_color = color;
}