#pragma once

#include <string>
#include <iostream>
#include "vector3f.h"

# define M_PI 3.14159265358979323846

class Matrix4x4
{

public:

	Matrix4x4::Matrix4x4() { toIdentity(); };

	Matrix4x4(
		double v00, double v10, double v20, double v30,
		double v01, double v11, double v21, double v31,
		double v02, double v12, double v22, double v32,
		double v03, double v13, double v23, double v33);

	Matrix4x4::~Matrix4x4() {};

	void toIdentity();

	void set(Matrix4x4 matrix);

	double * getPtr();

	static Matrix4x4 multiply(Matrix4x4 & lhs, Matrix4x4 & rhs);

	Matrix4x4 inverse();

	Matrix4x4 transpose();

	double determinant();

	Matrix4x4 operator*(Matrix4x4 rhs);

	Matrix4x4 operator/(double scale);
	void print(std::string message = "");

	void translate(double x, double y, double z);

	void rotate(double angle, double x, double y, double z);

	void scale(double x, double y, double z);

	void ortho(double left, double right, double bottom, double top, double zNear, double zFar);

	void perspective(double fovy, double aspect, double near, double far);

	void lookAt(Vector3f eye, Vector3f center, Vector3f up);

protected:

private:

	double val[4][4];

};