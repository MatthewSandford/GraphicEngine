#include "shader.h"

int Shader::get_shader_id()
{
	return shader_id;
}

int Shader::get_attribute(std::string attribute_name)
{
	return attribute_map[attribute_name];
}

void Shader::set_files(const std::string file_1, const std::string file_2)
{
	vertex_file = file_1;
	fragment_file = file_2;

	load_shader();
}

std::string Shader::read_shader(std::string file)
{
	std::string file_code;

	std::ifstream shader_file(file.c_str(), std::ios::in);

	if (shader_file.is_open())
	{
		std::string Line = "";

		while (getline(shader_file, Line))
		{
			file_code += "\n" + Line;
		}

		shader_file.close();
	}
	else 
	{
		std::cerr << "Cannot open " << file << "Please check input!" << std::endl;
		return NULL;
	}

	return file_code;
}

int Shader::compile_shader(std::string code, int shader_type)
{
	char const * shader_pointer = code.c_str();

	int shader(glCreateShader(shader_type));

	glShaderSource(shader, 1, &shader_pointer, NULL);
	glCompileShader(shader);

	return shader;
}

void Shader::load_shader()
{
	std::string vertex_code(read_shader(vertex_file));
	std::string fragment_code(read_shader(fragment_file));

	int vertex_id(compile_shader(vertex_code, GL_VERTEX_SHADER));
	int fragment_id(compile_shader(fragment_code, GL_FRAGMENT_SHADER));

	shader_id = glCreateProgram();
	glAttachShader(shader_id, vertex_id);
	glAttachShader(shader_id, fragment_id);
	glLinkProgram(shader_id);

	glDeleteShader(vertex_id);
	glDeleteShader(fragment_id);

	std::cout << "Shader Program Compiled using files: " << vertex_file << " " << fragment_file << std::endl;
}

void Shader::create_attribute(std::string attribute_name)
{
	attribute_map[attribute_name] = glGetAttribLocation(shader_id, attribute_name.c_str());
}