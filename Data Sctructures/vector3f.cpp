#include "vector3f.h"

Vector3f Vector3f::operator-(Vector3f other)
{
	Vector3f result;

	result.x = this->x - other.x;
	result.y = this->y - other.y;
	result.z = this->z - other.z;

	return result;
}

Vector3f Vector3f::operator+(Vector3f other)
{
	Vector3f result;

	result.x = this->x + other.x;
	result.y = this->y + other.y;
	result.z = this->z + other.z;

	return result;
}

Vector3f  Vector3f::operator/(double other)
{
	Vector3f result;

	result.x = this->x / other;
	result.y = this->y / other;
	result.z = this->z / other;

	return result;
}

Vector3f  Vector3f::operator*(double other)
{
	Vector3f result;

	result.x = this->x * other;
	result.y = this->y * other;
	result.z = this->z * other;

	return result;
}

double Vector3f::length()
{
	return sqrt(x*x + y*y + z*z);
}

Vector3f Vector3f::normalise(Vector3f vector)
{
	return vector / vector.length();
}

Vector3f Vector3f::cross(Vector3f vector_1, Vector3f vector_2)
{
	Vector3f result;

	result.x = vector_1.y * vector_2.z - vector_2.y* vector_1.z;
	result.y = vector_1.z * vector_2.x - vector_2.z* vector_1.x;
	result.z = vector_1.x * vector_2.y - vector_2.x* vector_1.y;

	return result;
}

double Vector3f::dot(Vector3f vector_1, Vector3f vector_2)
{
	return vector_1.x * vector_2.x + vector_1.y * vector_2.y + vector_1.z * vector_2.z;
}