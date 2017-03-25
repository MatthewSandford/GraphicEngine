#include <iostream>
#include <vector>

#include "instance.h"
#include "tile.h"
#include "entity.h"
#include "mesh.h"
#include "texture.h"
#include "shader.h"
#include "window.h"
#include "camera.h"
#include "scene_manager.h"

Scene_manager scene_manager;

void draw()
{
	scene_manager.draw_scene();
}

void game()
{
	scene_manager.scene_step();
}

int main(int argc, char** argv)
{
	Window window;
	window.set_size(192, 108);
	window.setup(argc, argv);

	Scene new_scene;
	new_scene.instance_create("obj_cube");
	new_scene.camera.set_pan_tilt_radius(0.0f, 0.0f, 2.0f);
	new_scene.camera.set_focus(new_scene.get_non_static("obj_cube").get_position());

	scene_manager.add_scene("room_1",new_scene);

	Shader shader("vert_shader.txt", "frag_shader.txt");
	shader.create_attribute("vertex_position");

	window.start();
}