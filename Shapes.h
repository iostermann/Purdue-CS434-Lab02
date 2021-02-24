#pragma once
#include <glm/glm.hpp>
#include "Ray.h"

class Ray;

class Shape {
public:
	glm::vec3 ambient;
	glm::vec3 specular;
	glm::vec3 diffuse;
	bool isMirror = false;

	virtual void print();
	virtual float findIntersection(Ray* ray);
};

class Sphere : public Shape {
public:
	glm::vec3 position;
	int radius;
	int radiusSquared;

	void print();
	float findIntersection(Ray* ray);
};

class Quad : public Shape {
public:
	glm::vec3 corner1;
	glm::vec3 corner2;
	glm::vec3 corner3;
	glm::vec3 corner4; // Do I need this??

	void print();
	float findIntersection(Ray* ray);
};
