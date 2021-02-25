#pragma once
#include <vector>
#include <list>
#include <map>
#include <glm/glm.hpp>
#define _USE_MATH_DEFINES
#include <math.h>
#include "scene.h"
#include "Ray.h"

class Shape;

class Pixel
{
public:
	unsigned char r;
	unsigned char g;
	unsigned char b;
	unsigned char a;
	Pixel(glm::vec3 color) { r = color.x; g = color.y; b = color.z; a = 1; };
	Pixel(glm::vec4 color) { r = color.x; g = color.y; b = color.z; a = color.z; };
	Pixel(unsigned char r, unsigned char g, unsigned char b, unsigned char a) { this->r = r; this->g = g; this->b = b; this->a = a; };
	Pixel() { r = 255; g = 255; b = 1; a = 255; };

	void setColor(glm::vec3 color) { r = color.x; g = color.y; b = color.z; a = 255; };
	void setColor(glm::vec4 color) { r = color.x; g = color.y; b = color.z; a = color.w; };
	glm::vec4 getColor() { return glm::vec4(r, g, b, a); }
};


class Image
{
public:
	Scene* scene;

	int width;
	int height;

	glm::vec3 eye;
	glm::vec3 lookAt;
	glm::vec3 up;
	const float fovy = M_PI / 2.0f;

	// Gramm-Schmidt and vectors needed for primary ray calculation
	glm::vec3 l;
	glm::vec3 v;
	glm::vec3 u;
	glm::vec3 ll;
	float focalLength;	
	float aspectRatio;
	glm::vec3 primaryRayHelper; // Precomputed for speeeed

	std::vector<std::vector<Pixel>> data;
	Image(Scene* scene);

	Ray CalculateRay(int i, int j);
	glm::vec3 TraceRay(Ray* ray, int maxDepth);
	void intersect(Ray* ray);
	void intersect(Ray* ray, Shape* ignore);
	list<Light*> ShadowRays(Ray* ray);
	glm::vec3 Phong(Ray* ray, Light* light);


};



