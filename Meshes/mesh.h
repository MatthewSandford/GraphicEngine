#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

#include <GL\glew.h>     
#include <GL\freeglut.h>   
#include <GL\glut.h>
#include <GL\GLU.h>

#include "vector2f.h"
#include "vector3f.h"

class Mesh
{
public:

	Mesh() : positionBuffer(0), normalBuffer(0), texcoordBuffer(0) {};
	~Mesh() {};

	void load_mesh(std::string filename);

	void draw(GLuint vertexPositionAttribute, GLuint vertexNormalAttribute = -1, GLuint vertexTexcordAttribute = -1);

	Vector3f get_centroid();

private:

	void init_buffers();

	struct Face
	{
		std::vector<unsigned int> position_index;
		std::vector<unsigned int> normal_index;
		std::vector<unsigned int> texturecoord_index;
	};

	std::vector<Vector3f> positions;
	std::vector<Vector3f> normals;
	std::vector<Vector2f> texcoords;
	std::vector<Face> faces;

private:

	GLuint positionBuffer, normalBuffer, texcoordBuffer;

};