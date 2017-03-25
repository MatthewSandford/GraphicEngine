#pragma once

#include "vector3f.h"

class Camera
{
public:

	Camera() {};
	~Camera() {};

	void set_pan_tilt_radius(float new_pan, float new_tilt, float new_radius);
	void set_focus(Vector3f new_focus);

	float get_pan();
	float get_tilt();
	float get_radius();

protected:

private:

	Vector3f focus;

	float pan;
	float tilt;
	float radius;

};