#include "texture.h"

void Texture::load_texture(std::string file_name)
{
	std::ifstream file(file_name, std::ifstream::binary);

	char buffer[2];
	file.read(buffer, 2);

	assert(buffer[0] == 'B' && buffer[1] == 'M' || !"Not a bitmap file");

	file.ignore(8);

	int data_start = read_int(file);

	int header_size = read_int(file);
	int width;
	int height;

	switch (header_size)
	{
		case 40:

			width = read_int(file);
			height = read_int(file);
			file.ignore(2);
			assert(read_short(file) == 24 || !"Image is not 24 bits per pixel");
			assert(read_short(file) == 0 || !"Image is compressed");

		break;

		case 12:

			width = read_short(file);
			height = read_short(file);
			file.ignore(2);
			assert(read_short(file) == 24 || !"Image is not 24 bits per pixel");
			
		break;
		
		case 64:

			assert(!"Can't load OS/2 V2 bitmaps");

		break;

		case 108:

			assert(!"Can't load Windows V4 bitmaps");

		break;

		case 124:

			assert(!"Can't load Windows V5 bitmaps");

		break;

		default:

			assert(!"Unknown bitmap format");
	}

	int bytes = ((width * 3 + 3) / 4) * 4 - (width * 3 % 4);
	int size = bytes * height;
	char* pixels = new char[size];

	file.seekg(data_start, std::ios_base::beg);
	file.read(pixels, size);

	char* pixel_data = new char[width * height * 3];

	for (int y = 0; y < height; y++) 
	{
		for (int x = 0; x < width; x++) 
		{
			for (int c = 0; c < 3; c++)
			{
				pixel_data[3 * (width * y + x) + c] = pixels[bytes * y + 3 * x + (2 - c)];
			}
		}
	}

	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, pixel_data);

	std::cout << "Loaded " << file_name << " into Texture " << texture << " with size " << width << "x" << height << std::endl;
}

int Texture::read_int(std::ifstream &file) 
{
	char buffer[4];
	file.read(buffer, 4);
	return to_int(buffer);
}

short Texture::read_short(std::ifstream &file) 
{
	char buffer[2];
	file.read(buffer, 2);
	return to_short(buffer);
}

int Texture::to_int(const char* bytes) 
{
	return (int)(((unsigned char)bytes[3] << 24) | ((unsigned char)bytes[2] << 16) | ((unsigned char)bytes[1] << 8) | (unsigned char)bytes[0]);
}

short Texture::to_short(const char* bytes) 
{
	return (short)(((unsigned char)bytes[1] << 8) | (unsigned char)bytes[0]);
}