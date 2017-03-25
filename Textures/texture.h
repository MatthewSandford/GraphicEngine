#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <assert.h>

#include <GL\glew.h>     
#include <GL\freeglut.h>   
#include <GL\glut.h>
#include <GL\GLU.h>

class Texture
{
public:

	Texture() : texture(0) {};
	Texture(std::string file_name) : texture(0) { load_texture(file_name); };
	~Texture() {};

	void load_texture(std::string file_name);

protected:

private:

	GLuint texture;

	static int Texture::read_int(std::ifstream &file);
	static short Texture::read_short(std::ifstream &file);
	static int Texture::to_int(const char* bytes);
	static short Texture::to_short(const char* bytes);
};

