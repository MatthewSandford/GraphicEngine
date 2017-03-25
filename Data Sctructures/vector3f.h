#pragma once

#include <math.h>

class Vector3f
{
public:

	Vector3f() : x(0), y(0), z(0) {};
	Vector3f(double x, double y, double z) : x(x), y(y), z(z) {};
	~Vector3f() {};

	Vector3f operator-(Vector3f other);
	Vector3f operator+(Vector3f other);
	Vector3f operator/(double other);
	Vector3f operator*(double other);

	static Vector3f cross(Vector3f vector_1, Vector3f v2);
	static double dot(Vector3f vector_1, Vector3f v2);
	static Vector3f normalise(Vector3f vector);

	double length();

	double x, y, z;

protected:

private:

};
