#pragma once

#include <iostream>
#include <map>

#include "scene.h"

class Scene_manager
{
public:

	Scene_manager() {};
	~Scene_manager() {};

	std::map<std::string, Scene>& get_scene_map();

	void set_scene(std::string new_scene);
	Scene& get_scene(std::string scene_name);

	void draw_scene();
	void scene_step();

	void add_scene(std::string scene_name);
	void add_scene(std::string scene_name, Scene new_scene);

private:

	std::string scene;
	std::map<std::string, Scene> scene_map;

}; 
