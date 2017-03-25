#pragma once

#include "static.h"
#include "texture.h"

class Tile: public Static
{
public:

	Tile() : Static() {};
	Tile(const double new_x, const double new_y, const double new_z) : Static(new_x, new_y, new_z) {};
	~Tile() {};

	Texture get_texture() const;

	void set_texture(const Texture new_texture);

	void draw();

	Texture texture;

protected:

private:

}; 
