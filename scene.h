#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

#include "entity.h"
#include "static.h"
#include "non_static.h"
#include "obj_cube.h"
#include "camera.h"

#include <GL\glew.h>     
#include <GL\freeglut.h>   
#include <GL\glut.h>
#include <GL\GLU.h>

class Scene
{
public:

	Scene() {};
	~Scene() {};

	void draw();
	void game_step();

	void instance_create(std::string new_object);
	void instance_destroy(std::string new_object);

	Non_static& get_non_static(std::string name);

	Camera camera;

protected:

private:

	std::map<std::string,std::vector<Static*>> static_map;
	std::map<std::string, std::vector<Non_static*>> non_static_map;
};


