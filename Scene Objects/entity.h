#pragma once

#include "non_static.h"
#include "mesh.h"
#include "texture.h"

class Entity : public Non_static
{
public:

	Entity() : Non_static() {};
	Entity(const double new_x, const double new_y, const double new_z) : Non_static(new_x, new_y, new_z) {};
	~Entity() {};

	void draw();
	
	Texture texture;
	Mesh mesh;

protected:

private:

};

