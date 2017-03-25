#include "scene.h"

void Scene::draw()
{
	for (auto& instance_array : static_map)
	{
		for (auto& instance : instance_array.second)
		{
			instance->draw();
		}
	}
	for (auto& instance_array : non_static_map)
	{
		for (auto& instance : instance_array.second)
		{
			instance->draw();
		}
	}
}

void Scene::game_step()
{
	for (auto& instance_array : non_static_map)
	{
		for (auto& instance : instance_array.second)
		{
			instance->step();
		}
	}
}

void Scene::instance_create(std::string new_object)
{
	if (new_object == "obj_cube") 
	{ 
		Obj_cube obj_cube; 
		non_static_map["obj_cube"].push_back(&obj_cube);
	}
}

void Scene::instance_destroy(std::string new_object)
{

}

Non_static& Scene::get_non_static(std::string name)
{
	return *non_static_map[name][0];
}