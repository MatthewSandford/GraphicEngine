#include "tile.h"

Texture Tile::get_texture() const
{
	return texture;
}

void Tile::set_texture(const Texture new_texture)
{
	texture = new_texture;
}

void Tile::draw()
{

}