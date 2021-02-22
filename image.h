#pragma once
#include <vector>
#include <glm/glm.hpp>

#define _USE_MATH_DEFINES
#include <math.h>


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

class Ray
{
public:
	glm::vec3 origin;
	glm::vec3 direction;
	Ray(glm::vec3 o, glm::vec3 d);

};

class Image
{
public:
	int width;
	int height;
	float aspectRatio;


	glm::vec3 eye;
	glm::vec3 lookAt;
	glm::vec3 up;
	const float fovy = M_PI / 2.0;

	// Gramm-Schmidt
	glm::vec3 l;
	glm::vec3 v;
	glm::vec3 u;
	float focalLength;
	glm::vec3 ll;

	glm::vec3 primaryRayHelper;


	std::vector<std::vector<Pixel>> data;
	Image(int w, int h);
	~Image();

	std::vector<unsigned char> flatten();
	Ray CalculateRay(int i, int j);
};



