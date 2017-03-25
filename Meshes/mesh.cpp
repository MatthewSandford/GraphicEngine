#include "mesh.h"

//
void Mesh::load_mesh(std::string filename)
{
	std::ifstream filestream(filename.c_str());

	std::string line_stream;

	while (std::getline(filestream, line_stream))
	{
		std::stringstream str_stream(line_stream);
		std::string type_str;
		str_stream >> type_str;

		if (type_str == "v")
		{
			Vector3f position;
			str_stream >> position.x >> position.y >> position.z;
			positions.push_back(position);
		}
		else if (type_str == "vt")
		{
			Vector2f texture;
			str_stream >> texture.x >> texture.y;
			texcoords.push_back(texture);
		}
		else if (type_str == "vn")
		{
			Vector3f normal;
			str_stream >> normal.x >> normal.y >> normal.z;
			normals.push_back(normal);
		}
		else if (type_str == "f")
		{
			char temp;
			Face face;
			unsigned int v1, v2, v3;
			for (int i = 0; i < 3; ++i)
			{
				str_stream >> v1 >> temp >> v2 >> temp >> v3;
				face.position_index.push_back(v1 - 1);
				face.texturecoord_index.push_back(v2 - 1);
				face.normal_index.push_back(v3 - 1);
			}

			faces.push_back(face);
		}
	}

	filestream.close();

	init_buffers();
}

void Mesh::init_buffers()
{
	std::cout << "Start Init Mesh Buffers" << std::endl;

	glGenBuffers(1, &positionBuffer);
	glGenBuffers(1, &normalBuffer);
	glGenBuffers(1, &texcoordBuffer);

	std::vector<GLdouble> vertexPositionData;
	std::vector<GLdouble> vertexNormalData;
	std::vector<GLdouble> vertexTexcoordData;

	for (auto& face : faces)
	{
		for (int vertex_i = 0; vertex_i < 3; vertex_i++)
		{
			if (positions.size() > 0)
			{
				Vector3f v = positions[face.position_index[vertex_i]];
				vertexPositionData.push_back(v.x);
				vertexPositionData.push_back(v.y);
				vertexPositionData.push_back(v.z);
			}

			if (normals.size() > 0)
			{
				Vector3f n = normals[face.normal_index[vertex_i]];
				vertexNormalData.push_back(n.x);
				vertexNormalData.push_back(n.y);
				vertexNormalData.push_back(n.z);
			}

			if (texcoords.size() > 0)
			{
				Vector2f t = texcoords[face.texturecoord_index[vertex_i]];
				vertexTexcoordData.push_back(t.x);
				vertexTexcoordData.push_back(t.y);
			}
		}
	}

	if (positions.size() > 0)
	{
		glBindBuffer(GL_ARRAY_BUFFER, positionBuffer);
		glBufferData(GL_ARRAY_BUFFER, vertexPositionData.size() * sizeof(GLdouble), &vertexPositionData[0], GL_STATIC_DRAW);
	}

	if (normals.size() > 0)
	{
		glBindBuffer(GL_ARRAY_BUFFER, normalBuffer);
		glBufferData(GL_ARRAY_BUFFER, vertexNormalData.size() * sizeof(GLdouble), &vertexNormalData[0], GL_STATIC_DRAW);
	}

	if (texcoords.size() > 0)
	{
		glBindBuffer(GL_ARRAY_BUFFER, texcoordBuffer);
		glBufferData(GL_ARRAY_BUFFER, vertexTexcoordData.size() * sizeof(GLdouble), &vertexTexcoordData[0], GL_STATIC_DRAW);
	}
	std::cout << "End Init Mesh Buffers" << std::endl;

}

void Mesh::draw(GLuint vertexPositionAttribute, GLuint vertexNormalAttribute, GLuint vertexTexcordAttribute)
{
	if (positions.size() > 0)
	{
		glEnableVertexAttribArray(vertexPositionAttribute);
		glBindBuffer(GL_ARRAY_BUFFER, positionBuffer);
		glVertexAttribPointer(
			vertexPositionAttribute, 		
			3,                  			
			GL_FLOAT,        			   
			GL_FALSE,           		
			0,                  			
			(void*)0            			
		);
	}

	if (normals.size() > 0 && vertexNormalAttribute != -1)
	{
		glEnableVertexAttribArray(vertexNormalAttribute);
		glBindBuffer(GL_ARRAY_BUFFER, normalBuffer);
		glVertexAttribPointer(
			vertexNormalAttribute, 		
			3,                 		 	
			GL_FLOAT,           	
			GL_FALSE,           	
			0,                  	
			(void*)0           		
		);
	}

	if (texcoords.size() > 0 && vertexTexcordAttribute != -1)
	{
		glEnableVertexAttribArray(vertexTexcordAttribute);
		glBindBuffer(GL_ARRAY_BUFFER, texcoordBuffer);
		glVertexAttribPointer(
			vertexTexcordAttribute, 	
			2,                  		
			GL_FLOAT,           		
			GL_FALSE,          			
			0,                 			
			(void*)0           			
		);
	}

	glDrawArrays(GL_TRIANGLES, 0, faces.size() * 3);

	if (positions.size() > 0)
	{
		glDisableVertexAttribArray(vertexPositionAttribute);
	}

	if (normals.size() > 0 && vertexNormalAttribute != -1)
	{
		glDisableVertexAttribArray(vertexNormalAttribute);
	}

	if (texcoords.size() > 0 && vertexTexcordAttribute != -1)
	{
		glDisableVertexAttribArray(vertexTexcordAttribute);
	}
}

Vector3f Mesh::get_centroid()
{
	double x = 0.f;
	double y = 0.f;
	double z = 0.f;

	for (auto& position : positions)
	{
		x += position.x;
		y += position.y;
		z += position.z;
	}

	x /= positions.size();
	y /= positions.size();
	z /= positions.size();

	return	Vector3f(x, y, z);
}