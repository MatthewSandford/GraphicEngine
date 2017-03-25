#pragma once

#include <vector>
#include "vector3f.h"

class Instance
{
public:

	Instance() : x(0), y(0), z(0), rotation({ 0,0,0 }) {};
	Instance(const double new_x, const double new_y, const double new_z) : x(new_x), y(new_y), z(new_z), rotation({ 0,0,0 }) {};
	~Instance() {};

	//Accessors

	Vector3f get_position() const;
	Vector3f get_rotation() const;

	//Mutators

	void set_position(const double new_x, const double new_y, const double new_z);
	void set_rotation(const double rotate_x, const double rotate_y, const double rotate_z);
	void rotate(const double rotate_x, const double rotate_y, const double rotate_z);

	virtual void draw() = 0;

	double x, y, z;

protected:

	Vector3f rotation;

private:

};