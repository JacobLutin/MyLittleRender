#include <iostream>
#include <cmath>

#include "vectormath.h"

Vector3::Vector3(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

float Vector3::LengthSquared()
{
	return x * x + y * y + z * z;
}

float Vector3::Length()
{
	return sqrt(LengthSquared());
}

void Vector3::Print()
{
	std::cout << "Vector3 = " << x << " " << y << " " << z << std::endl;
	return;
}

Vector3 Vector3::operator+(Vector3 const &v)
{
	return Vector3(x + v.x, y + v.y, z + v.z);
}

Vector3 Vector3::operator-(Vector3 const &v)
{
	return Vector3(x - v.x, y - v.y, z - v.z);
}

float Vector3::operator*(Vector3 const &v)
{
	return x * v.x + y * v.y + z * v.z;
}

bool Vector3::operator==(Vector3 const &v)
{
	return x == v.x && y == v.y && z == v.z;
}

void Vector3::operator*=(const float n)
{
	x = x * n;
	y = y * n;
	z = z * n;
	return;
}


Vector2::Vector2(float x, float y)
{
	this->x = x;
	this->y = y;
}

float Vector2::LengthSquared()
{
	return x * x + y * y;
}

float Vector2::Length()
{
	return sqrt(LengthSquared());
}

void Vector2::Print()
{
	std::cout << "Vector2 = " << x << " " << y << std::endl;
	return;
}

Vector2 Vector2::operator+(Vector2 const &v)
{
	return Vector2(x + v.x, y + v.y);
}

Vector2 Vector2::operator-(Vector2 const &v)
{
	return Vector2(x - v.x, y - v.y);
}

float Vector2::operator*(Vector2 const &v)
{
	return x * v.x + y * v.y;
}

bool Vector2::operator==(Vector2 const &v)
{
	return x == v.x && y == v.y;
}

void Vector2::operator*=(const float n)
{
	x = x * n;
	y = y * n;
	return;
}