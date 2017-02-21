#include <iostream>
#include <cmath>

#include "vectormath.h"

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

int main()
{
	Vector3 v(1, 2, 3);
	Vector3 u(1, 1, 1);
	Vector3 r;
	r = v + u;
	r *= 2;
	r.Print();

	return 0;
}











