#pragma once
#include <vector>
#include <glm/glm.hpp>

class Pixel
{
public:
	unsigned char r;
	unsigned char g;
	unsigned char b;
	unsigned char a;
	Pixel(glm::vec3 color) { r = color.x; g = color.y; b = color.z; a = 255; };
	Pixel(glm::vec4 color) { r = color.x; g = color.y; b = color.z; a = color.z; };
	Pixel(unsigned char r, unsigned char g, unsigned char b, unsigned char a) { this->r = r; this->g = g; this->b = b; this->a = a; };
	Pixel() { r = 255; g = 255; b = 255; a = 255; };

	void setColor(glm::vec3 color) { r = color.x; g = color.y; b = color.z; a = 255; };
	void setColor(glm::vec4 color) { r = color.x; g = color.y; b = color.z; a = color.z; };
};

class Image
{
public:
	int width;
	int height;

	std::vector<std::vector<Pixel>> data;
	Image(int w, int h);
	~Image();

	std::vector<unsigned char> flatten();
};

class Ray
{
public:
	glm::vec3 origin;
	glm::vec3 direction;
	Ray(glm::vec3 o, glm::vec3 d);

};



