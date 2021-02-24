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
	virtual bool findIntersection(Ray* ray, float& param);
	virtual glm::vec3 getNormal(Ray* ray);
};

class Sphere : public Shape {
public:
	glm::vec3 position;
	int radius;
	int radiusSquared;

	void print();
	bool findIntersection(Ray* ray, float& param);
	glm::vec3 getNormal(Ray* ray);
};

// Quads are two triangles T123 and T243
class Quad : public Shape {
public:
	glm::vec3 corner1;
	glm::vec3 corner2;
	glm::vec3 corner3;
	glm::vec3 corner4; 

	void print();
	bool findIntersection(Ray* ray, float& param);
	glm::vec3 getNormal(Ray* ray);

};
