#pragma once

class Point
{
public:

	explicit Point(float p_x = 0, float p_y = 0, float p_z = 0)
		: x(p_x), y(p_y), z(p_z)
	{
	}

	~Point()
	{
	}

	float x;
	float y;
	float z;
};

