#pragma once
class Colorf
{
public:

	explicit Colorf(float red = 0, float green = 0, float blue = 0, float alpha = 1)
	{
		this->setRed(red);
		this->setGreen(green);
		this->setBlue(blue);
		this->setAlpha(alpha);
	}

	~Colorf()
	{
	}

	float red() const { return m_red; }
	float green() const { return m_green; }
	float blue() const { return m_blue; }
	float alpha() const { return m_alpha; }

	void setRed(float red)
	{
		m_red = (red >= 0 || red <= 1) ? red : 0;
	}

	void setGreen(float green)
	{
		m_green = (green >= 0 || green <= 1) ? green : 0;
	}

	void setBlue(float blue)
	{
		m_blue = (blue >= 0 || blue <= 1) ? blue : 0;
	}

	void setAlpha(float alpha)
	{
		m_alpha = (alpha >= 0 || alpha <= 1) ? alpha : 1;
	}

private:
	float m_red;
	float m_green;
	float m_blue;
	float m_alpha;
};

