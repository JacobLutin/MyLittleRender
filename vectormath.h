#ifndef VECTORMATH_H
#define VECTORMATH_H

#include <iostream>
#include <cmath>

class Vector3
{
public:
	float x;
	float y;
	float z;
	Vector3() { x = y = z = 0; };
	Vector3(float x, float y, float z);
	Vector3 operator+(Vector3 const &v);
	Vector3 operator-(Vector3 const &v);
	bool operator==(Vector3 const &v);
	float operator*(Vector3 const &v);
	void operator*=(const float n);
	float LengthSquared();
	float Length();
	void Print();
	// ~Vector3();
};

class Vector2
{
public:
	float x;
	float y;
	Vector2() { x = y = 0; };
	Vector2(float x, float y);
	Vector2 operator+(Vector2 const &v);
	Vector2 operator-(Vector2 const &v);
	bool operator==(Vector2 const &v);
	float operator*(Vector2 const &v);
	void operator*=(const float n);
	float LengthSquared();
	float Length();
	void Print();
	// ~Vector2();
};

#endif