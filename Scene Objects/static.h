#pragma once

#include "instance.h"
#include "texture.h"

class Static : public Instance
{
public:

	Static() : Instance() {};
	Static(const double new_x, const double new_y, const double new_z) : Instance(new_x, new_y, new_z) {};
	~Static() {};

protected:

private:

};
