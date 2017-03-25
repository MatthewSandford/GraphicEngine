#pragma once

#include "instance.h"
#include "texture.h"

class Non_static : public Instance
{
public:

	Non_static() : Instance() {};
	Non_static(const double new_x, const double new_y, const double new_z) : Instance(new_x, new_y, new_z) {};
	~Non_static() {};

	virtual void step() = 0;
	virtual void draw() = 0;

protected:

private:

};