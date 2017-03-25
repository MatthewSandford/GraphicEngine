#pragma once

#include "entity.h"
#include "vector3f.h"

class obj_cube : public Entity
{
public:

	obj_cube() : Entity() { mesh.load_mesh("cube.obj"); texture.load_texture("crate.bmp"); };
	obj_cube(const double new_x, const double new_y, const double new_z) : Entity(new_x, new_y, new_z) { mesh.load_mesh("cube.obj"); texture.load_texture("crate.bmp"); };
	~obj_cube() {};

	void step();

protected:

private:

};

