#include "camera.h"

void Camera::set_pan_tilt_radius(float new_pan, float new_tilt, float new_radius)
{
	pan = new_pan;
	tilt = new_tilt;
	radius = new_radius;
}

void Camera::set_focus(Vector3f new_focus)
{
	focus = new_focus;
}

float Camera::get_pan()
{
	return pan;
}

float Camera::get_tilt()
{
	return tilt;
}

float Camera::get_radius()
{
	return radius;
}