#include "instance.h"

//Accessors


Vector3f Instance::get_position() const
{
	return{x,y,z};
}

Vector3f Instance::get_rotation() const
{
	return rotation;
}

//Mutators

void Instance::set_position(const double new_x, const double new_y, const double new_z)
{
	x = new_x;
	y = new_y;
	z = new_z;
}

void Instance::set_rotation(const double rotate_x, const double rotate_y, const double rotate_z)
{
	rotation.x = rotate_x;
	rotation.y = rotate_y;
	rotation.z = rotate_z;
}

void Instance::rotate(const double rotate_x, const double rotate_y, const double rotate_z)
{
	rotation.x += rotate_x;
	rotation.y += rotate_y;
	rotation.z += rotate_z;
}