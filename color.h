#ifndef COLOR_H
#define COLOR_H

class Color
{
public:
	double r, g, b;
	Color() {r = 0; g = 0; b = 0; };
	Color(double r, double g, double b);
};

Color::Color(double r, double g, double b)
{
	this->r = r;
	this->g = g;
	this->b = b;
	return;
}

#endif