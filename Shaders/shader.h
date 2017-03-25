#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <map>

#include <GL\glew.h>     
#include <GL\freeglut.h>   
#include <GL\glut.h>
#include <GL\GLU.h>

class Shader
{
public:

	Shader() : vertex_file(NULL), fragment_file(NULL), shader_id(NULL) {};
	Shader(const std::string file_1, const std::string file_2) : vertex_file(file_1), fragment_file(file_2), shader_id(0) { load_shader(); };
	~Shader() {};

	int get_shader_id();
	int get_attribute(std::string attribute_name);

	void set_files(const std::string file_1, const std::string file_2);

	void create_attribute(std::string attribute_name);

protected:

private:

	void load_shader();

	int shader_id;
	std::map<std::string,int> attribute_map;

	std::string fragment_file;
	std::string vertex_file;

	std::string read_shader(std::string file);
	int compile_shader(std::string code, int shader_type);
};