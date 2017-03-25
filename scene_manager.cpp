#include "scene_manager.h"

std::map<std::string, Scene>& Scene_manager::get_scene_map()
{
	return scene_map;
}

void Scene_manager::set_scene(std::string new_scene)
{
	scene = new_scene;
}

void Scene_manager::draw_scene()
{
	scene_map[scene].draw();
}

void Scene_manager::scene_step()
{
	scene_map[scene].game_step();
}

Scene& Scene_manager::get_scene(std::string scene_name)
{
	return scene_map[scene_name];
}

void Scene_manager::add_scene(std::string scene_name, Scene new_scene)
{
	scene_map[scene_name] = new_scene;
}

void Scene_manager::add_scene(std::string scene_name)
{
	Scene new_scene;
	scene_map[scene_name] = new_scene;
}