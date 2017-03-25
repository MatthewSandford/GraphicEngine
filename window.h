#pragma once

#include <iostream>
#include <map>

#include "scene.h"

#include <GL\glew.h>     
#include <GL\freeglut.h>   
#include <GL\glut.h>
#include <GL\GLU.h>

void game();
void draw();

class Window
{
public:

	Window() {};
	~Window() {};

	int get_width() const;
	int get_height() const;

	void setup(int argc, char** argv);
	void start();

	void set_width(const int new_width);
	void set_height(const int new_height);
	void set_size(const int new_width, const int new_height);
	void set_name(std::string name);

	static void reshape(const int new_width, const int new_height);
	static void keyboard(unsigned char key, int x, int y);
	static void mouse(int button, int state, int x, int y);
	static void motion(int x, int y);
	static void display();

protected:

private:

	std::string window_name;
	int width, height;

};