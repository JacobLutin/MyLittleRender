#include <iostream>
#include <cmath>


class Vector
{
public:
	float x;
	float y;
	float z;
	Vector() { x = y = z = 0; };
	Vector(float x, float y, float z);
	Vector operator+(Vector const &v);
	Vector operator-(Vector const &v);
	bool operator==(Vector const &v);
	float operator*(Vector const &v);
	void operator*=(const float n);
	float LengthSquared();
	float Length();
	void Print();
	// ~Vector();
};

Vector::Vector(float x, float y, float z)
{
	std::cout << "vector instance\n";
	this->x = x;
	this->y = y;
	this->z = z;
}

float Vector::LengthSquared()
{
	return x * x + y * y + z * z;
}

float Vector::Length()
{
	return sqrt(LengthSquared());
}

void Vector::Print()
{
	std::cout << "vector = " << x << " " << y << " " << z << std::endl;
	return;
}

Vector Vector::operator+(Vector const &v)
{
	return Vector(x + v.x, y + v.y, z + v.z);
}

Vector Vector::operator-(Vector const &v)
{
	return Vector(x - v.x, y - v.y, z - v.z);
}

float Vector::operator*(Vector const &v)
{
	return x * v.x + y * v.y + z * v.z;
}

bool Vector::operator==(Vector const &v)
{
	return x == v.x && y == v.y && z == v.z;
}

void Vector::operator*=(const float n)
{
	x = x * n;
	y = y * n;
	z = z * n;
	return;
}

class Color
{
public:
	double r, g, b;
	Color() {r = 0; g = 0; b = 0};
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
	Vector v(1, 2, 3);
	Vector u(1, 1, 1);
	Vector r;
	r = v + u;
	r *= 2;
	r.Print();

	return 0;
}











