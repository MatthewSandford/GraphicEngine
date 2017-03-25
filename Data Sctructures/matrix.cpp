#include "matrix.h"

Matrix4x4::Matrix4x4(
	double v00, double v10, double v20, double v30,
	double v01, double v11, double v21, double v31,
	double v02, double v12, double v22, double v32,
	double v03, double v13, double v23, double v33)
{
	val[0][0] = v00;	val[1][0] = v10;	val[2][0] = v20;	val[3][0] = v30;
	val[0][1] = v01;	val[1][1] = v11;	val[2][1] = v21;	val[3][1] = v31;
	val[0][2] = v02;	val[1][2] = v12;	val[2][2] = v22;	val[3][2] = v32;
	val[0][3] = v03;	val[1][3] = v13;	val[2][3] = v23;	val[3][3] = v33;
}

void Matrix4x4::toIdentity()
{
	val[0][0] = 1.0;	val[1][0] = 0.0;	val[2][0] = 0.0;	val[3][0] = 0.0;
	val[0][1] = 0.0;	val[1][1] = 1.0;	val[2][1] = 0.0;	val[3][1] = 0.0;
	val[0][2] = 0.0;	val[1][2] = 0.0;	val[2][2] = 1.0;	val[3][2] = 0.0;
	val[0][3] = 0.0;	val[1][3] = 0.0;	val[2][3] = 0.0;	val[3][3] = 1.0;
}

void Matrix4x4::print(std::string message)
{
	if (!message.empty())
	{
		std::cout << message << "\n";
	}

	for (int row = 0; row < 4; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			std::cout << this->val[col][row] << "\t";
		}
		std::cout << "\n";
	}
	std::cout << std::endl;
}

void Matrix4x4::set(Matrix4x4 matrix)
{
	val[0][0] = matrix.val[0][0];	val[1][0] = matrix.val[1][0];	val[2][0] = matrix.val[2][0];	val[3][0] = matrix.val[3][0];
	val[0][1] = matrix.val[0][1];	val[1][1] = matrix.val[1][1];	val[2][1] = matrix.val[2][1];	val[3][1] = matrix.val[3][1];
	val[0][2] = matrix.val[0][2];	val[1][2] = matrix.val[1][2];	val[2][2] = matrix.val[2][2];	val[3][2] = matrix.val[3][2];
	val[0][3] = matrix.val[0][3];	val[1][3] = matrix.val[1][3];	val[2][3] = matrix.val[2][3];	val[3][3] = matrix.val[3][3];
}

Matrix4x4 Matrix4x4::multiply(Matrix4x4 & lhs, Matrix4x4 & rhs)
{
	Matrix4x4 out;
	for (int row = 0; row < 4; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			out.val[col][row] =
				lhs.val[0][row] * rhs.val[col][0] +
				lhs.val[1][row] * rhs.val[col][1] +
				lhs.val[2][row] * rhs.val[col][2] +
				lhs.val[3][row] * rhs.val[col][3];
		}
	}
	return out;
}

double * Matrix4x4::getPtr()
{
	return &val[0][0];
}

Matrix4x4 Matrix4x4::operator*(Matrix4x4 rhs)
{
	return Matrix4x4::multiply((*this), rhs);
}

Matrix4x4  Matrix4x4::operator/(double scale)
{
	Matrix4x4 out;

	for (int row = 0; row < 4; row++)
		for (int col = 0; col < 4; col++)
			out.val[col][row] = this->val[col][row] / scale;

	return out;
}

void Matrix4x4::scale(double x, double y, double z)
{
	//Create Scale Matrix
	Matrix4x4 scaleMatrix;

	//TODO IMPLEMENT SCALE FUNCTION






	//Set this matrix as results of this multiplied by scale matrix     	
	set(Matrix4x4::multiply(*this, scaleMatrix));
}

//! Translate Function
void Matrix4x4::translate(double x, double y, double z)
{
	//Create Translate Function
	Matrix4x4 translate;

	//TODO IMPLEMENT TRANSLATE FUNCTION





	//Set this matrix as results of this multiplied by t     	
	set(Matrix4x4::multiply(*this, translate));
}

void Matrix4x4::rotate(double angle, double x, double y, double z)
{
	double length = sqrt(x*x + y*y + z*z);
	x /= length;
	y /= length;
	z /= length;

	double rads = angle * (2.f * M_PI) / 360.f;

	double c = cos(rads);
	double s = sin(rads);

	Matrix4x4 rotateMatrix;
	rotateMatrix.val[0][0] = x*x*(1 - c) + c;	rotateMatrix.val[1][0] = x*y*(1 - c) - z*s;		rotateMatrix.val[2][0] = x*z*(1 - c) + y*s;		rotateMatrix.val[3][0] = 0;
	rotateMatrix.val[0][1] = y*x*(1 - c) + z*s;	rotateMatrix.val[1][1] = y*y*(1 - c) + c;		rotateMatrix.val[2][1] = y*z*(1 - c) - x*s;		rotateMatrix.val[3][1] = 0;
	rotateMatrix.val[0][2] = x*z*(1 - c) - y*s;	rotateMatrix.val[1][2] = y*z*(1 - c) + x*s;		rotateMatrix.val[2][2] = z*z*(1 - c) + c;		rotateMatrix.val[3][2] = 0;
	rotateMatrix.val[0][3] = 0;				rotateMatrix.val[1][3] = 0;					rotateMatrix.val[2][3] = 0;					rotateMatrix.val[3][3] = 1;
  	
	set(Matrix4x4::multiply(*this, rotateMatrix));
}

void Matrix4x4::ortho(double left, double right, double bottom, double top, double zNear, double zFar)
{
	this->val[0][0] = 2.f / (right - left);
	this->val[1][0] = 0.0;
	this->val[2][0] = 0.0;
	this->val[3][0] = -(right + left) / (right - left);

	this->val[0][1] = 0.0;
	this->val[1][1] = 2.f / (top - bottom);
	this->val[2][1] = 0.0;
	this->val[3][1] = -(top + bottom) / (top - bottom);

	this->val[0][2] = 0.0;
	this->val[1][2] = 0.0;
	this->val[2][2] = -2.f / (zFar - zNear);
	this->val[3][2] = -(zFar + zNear) / (zFar - zNear);

	this->val[0][3] = 0.0;
	this->val[1][3] = 0.0;
	this->val[2][3] = 0.0;
	this->val[3][3] = 1.0;
}

void Matrix4x4::perspective(double fovy, double aspect, double zNear, double zFar)
{
	double rad = fovy * (2.f * M_PI) / 360.f;
	double range = tan(rad / 2) * zNear;
	double left = -range * aspect;
	double right = range * aspect;
	double bottom = -range;
	double top = range;

	this->val[0][0] = (2.f * zNear) / (right - left);
	this->val[1][0] = 0.0;
	this->val[2][0] = (right + left) / (right - left);
	this->val[3][0] = 0.0;

	this->val[0][1] = 0.0;
	this->val[1][1] = (2.f * zNear) / (top - bottom);
	this->val[2][1] = (top + bottom) / (top - bottom);
	this->val[3][1] = 0.0;

	this->val[0][2] = 0.0;
	this->val[1][2] = 0.0;
	this->val[2][2] = -(zFar + zNear) / (zFar - zNear);
	this->val[3][2] = -(2.f * zFar * zNear) / (zFar - zNear);

	this->val[0][3] = 0.0;
	this->val[1][3] = 0.0;
	this->val[2][3] = -1;
	this->val[3][3] = 0.0;
}

void Matrix4x4::lookAt(Vector3f eye, Vector3f center, Vector3f up)
{
	Vector3f f = Vector3f::normalise(center - eye);
	Vector3f u = Vector3f::normalise(up);
	Vector3f s = Vector3f::normalise(Vector3f::cross(f, u));
	u = Vector3f::cross(s, f);

	this->val[0][0] = s.x;
	this->val[1][0] = s.y;
	this->val[2][0] = s.z;
	this->val[3][0] = -Vector3f::dot(s, eye);

	this->val[0][1] = u.x;
	this->val[1][1] = u.y;
	this->val[2][1] = u.z;
	this->val[3][1] = -Vector3f::dot(u, eye);

	this->val[0][2] = -f.x;
	this->val[1][2] = -f.y;
	this->val[2][2] = -f.z;
	this->val[3][2] = Vector3f::dot(f, eye);

	this->val[0][3] = 0.0;
	this->val[1][3] = 0.0;
	this->val[2][3] = 0.0;
	this->val[3][3] = 1.0;
}

Matrix4x4 Matrix4x4::transpose()
{
	Matrix4x4 out;

	out.val[0][0] = this->val[0][0];    out.val[1][0] = this->val[0][1];    out.val[2][0] = this->val[0][2];    out.val[3][0] = this->val[0][3];
	out.val[0][1] = this->val[1][0];    out.val[1][1] = this->val[1][1];    out.val[2][1] = this->val[1][2];    out.val[3][1] = this->val[1][3];
	out.val[0][2] = this->val[2][0];    out.val[1][2] = this->val[2][1];    out.val[2][2] = this->val[2][2];    out.val[3][2] = this->val[2][3];
	out.val[0][3] = this->val[3][0];    out.val[1][3] = this->val[3][1];    out.val[2][3] = this->val[3][2];    out.val[3][3] = this->val[3][3];

	return out;
}

double Matrix4x4::determinant()
{
	return
		this->val[0][0] * this->val[1][1] * this->val[2][2] * this->val[3][3] + this->val[0][0] * this->val[2][1] * this->val[3][2] * this->val[1][3] + this->val[0][0] * this->val[3][1] * this->val[1][2] * this->val[2][3] +
		this->val[1][0] * this->val[0][1] * this->val[3][2] * this->val[2][3] + this->val[1][0] * this->val[2][1] * this->val[0][2] * this->val[3][3] + this->val[1][0] * this->val[3][1] * this->val[2][2] * this->val[0][3] +
		this->val[2][0] * this->val[0][1] * this->val[1][2] * this->val[3][3] + this->val[2][0] * this->val[1][1] * this->val[3][2] * this->val[0][3] + this->val[2][0] * this->val[3][1] * this->val[0][2] * this->val[1][3] +
		this->val[3][0] * this->val[0][1] * this->val[2][2] * this->val[1][3] + this->val[3][0] * this->val[1][1] * this->val[0][2] * this->val[2][3] + this->val[3][0] * this->val[2][1] * this->val[1][2] * this->val[0][3] -
		this->val[0][0] * this->val[1][1] * this->val[3][2] * this->val[2][3] - this->val[0][0] * this->val[2][1] * this->val[1][2] * this->val[3][3] - this->val[0][0] * this->val[3][1] * this->val[2][2] * this->val[1][3] -
		this->val[1][0] * this->val[0][1] * this->val[2][2] * this->val[3][3] - this->val[1][0] * this->val[2][1] * this->val[3][2] * this->val[0][3] - this->val[1][0] * this->val[3][1] * this->val[0][2] * this->val[2][3] -
		this->val[2][0] * this->val[0][1] * this->val[3][2] * this->val[1][3] - this->val[2][0] * this->val[1][1] * this->val[0][2] * this->val[3][3] - this->val[2][0] * this->val[3][1] * this->val[1][2] * this->val[0][3] -
		this->val[3][0] * this->val[0][1] * this->val[1][2] * this->val[2][3] - this->val[3][0] * this->val[1][1] * this->val[2][2] * this->val[0][3] - this->val[3][0] * this->val[2][1] * this->val[0][2] * this->val[1][3];
}

Matrix4x4 Matrix4x4::inverse()
{
#define M(col,row) this->val[col-1][row-1]
#define M3(r1,c1,r2,c2,r3,c3)M(c1,r1)*M(c2,r2)*M(c3,r3)

	Matrix4x4 a;
	a.val[0][0] = M3(2, 2, 3, 3, 4, 4) + M3(2, 3, 3, 4, 4, 2) + M3(2, 4, 3, 2, 4, 3) - M3(2, 2, 3, 4, 4, 3) - M3(2, 3, 3, 2, 4, 4) - M3(2, 4, 3, 3, 4, 2);
	a.val[1][0] = M3(1, 2, 3, 4, 4, 3) + M3(1, 3, 3, 2, 4, 4) + M3(1, 4, 3, 3, 4, 2) - M3(1, 2, 3, 3, 4, 4) - M3(1, 3, 3, 4, 4, 2) - M3(1, 4, 3, 2, 4, 3);
	a.val[2][0] = M3(1, 2, 2, 3, 4, 4) + M3(1, 3, 2, 4, 4, 2) + M3(1, 4, 2, 2, 4, 3) - M3(1, 2, 2, 4, 4, 3) - M3(1, 3, 2, 2, 4, 4) - M3(1, 4, 2, 3, 4, 2);
	a.val[3][0] = M3(1, 2, 2, 4, 3, 3) + M3(1, 3, 2, 2, 3, 4) + M3(1, 4, 2, 3, 3, 2) - M3(1, 2, 2, 3, 3, 4) - M3(1, 3, 2, 4, 3, 2) - M3(1, 4, 2, 2, 3, 3);

	a.val[0][1] = M3(2, 1, 3, 4, 4, 3) + M3(2, 3, 3, 1, 4, 4) + M3(2, 4, 3, 3, 4, 1) - M3(2, 1, 3, 3, 4, 4) - M3(2, 3, 3, 4, 4, 1) - M3(2, 4, 3, 1, 4, 3);
	a.val[1][1] = M3(1, 1, 3, 3, 4, 4) + M3(1, 3, 3, 4, 4, 1) + M3(1, 4, 3, 1, 4, 3) - M3(1, 1, 3, 4, 4, 3) - M3(1, 3, 3, 1, 4, 4) - M3(1, 4, 3, 3, 4, 1);
	a.val[2][1] = M3(1, 1, 2, 4, 4, 3) + M3(1, 3, 2, 1, 4, 4) + M3(1, 4, 2, 3, 4, 1) - M3(1, 1, 2, 3, 4, 4) - M3(1, 3, 2, 4, 4, 1) - M3(1, 4, 2, 1, 4, 3);
	a.val[3][1] = M3(1, 1, 2, 3, 3, 4) + M3(1, 3, 2, 4, 3, 1) + M3(1, 4, 2, 1, 3, 3) - M3(1, 1, 2, 4, 3, 3) - M3(1, 3, 2, 1, 3, 4) - M3(1, 4, 2, 3, 3, 1);

	a.val[0][2] = M3(2, 1, 3, 2, 4, 4) + M3(2, 2, 3, 4, 4, 1) + M3(2, 4, 3, 1, 4, 2) - M3(2, 1, 3, 4, 4, 2) - M3(2, 2, 3, 1, 4, 4) - M3(2, 4, 3, 2, 4, 1);
	a.val[1][2] = M3(1, 1, 3, 4, 4, 2) + M3(1, 2, 3, 1, 4, 4) + M3(1, 4, 3, 2, 4, 1) - M3(1, 1, 3, 2, 4, 4) - M3(1, 2, 3, 4, 4, 1) - M3(1, 4, 3, 1, 4, 2);
	a.val[2][2] = M3(1, 1, 2, 2, 4, 4) + M3(1, 2, 2, 4, 4, 1) + M3(1, 4, 2, 1, 4, 2) - M3(1, 1, 2, 4, 4, 2) - M3(1, 2, 2, 1, 4, 4) - M3(1, 4, 2, 2, 4, 1);
	a.val[3][2] = M3(1, 1, 2, 4, 3, 2) + M3(1, 2, 2, 1, 3, 4) + M3(1, 4, 2, 2, 3, 1) - M3(1, 1, 2, 2, 3, 4) - M3(1, 2, 2, 4, 3, 1) - M3(1, 4, 2, 1, 3, 2);

	a.val[0][3] = M3(2, 1, 3, 3, 4, 2) + M3(2, 2, 3, 1, 4, 3) + M3(2, 3, 3, 2, 4, 1) - M3(2, 1, 3, 2, 4, 3) - M3(2, 2, 3, 3, 4, 1) - M3(2, 3, 3, 1, 4, 2);
	a.val[1][3] = M3(1, 1, 3, 2, 4, 3) + M3(1, 2, 3, 3, 4, 1) + M3(1, 3, 3, 1, 4, 2) - M3(1, 1, 3, 3, 4, 2) - M3(1, 2, 3, 1, 4, 3) - M3(1, 3, 3, 2, 4, 1);
	a.val[2][3] = M3(1, 1, 2, 3, 4, 2) + M3(1, 2, 2, 1, 4, 3) + M3(1, 3, 2, 2, 4, 1) - M3(1, 1, 2, 2, 4, 3) - M3(1, 2, 2, 3, 4, 1) - M3(1, 3, 2, 1, 4, 2);
	a.val[3][3] = M3(1, 1, 2, 2, 3, 3) + M3(1, 2, 2, 3, 3, 1) + M3(1, 3, 2, 1, 3, 2) - M3(1, 1, 2, 3, 3, 2) - M3(1, 2, 2, 1, 3, 3) - M3(1, 3, 2, 2, 3, 1);

#undef M
#undef M3

	return a / this->determinant();
}

