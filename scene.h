#pragma once
#include <glm/glm.hpp>
#include <vector>

using namespace std;

class Shape {
public:
	glm::vec3 ambient;
	glm::vec3 specular;
	glm::vec3 diffuse;
	bool isMirror = false;

	virtual void print();
};

class Light {
public:
	glm::vec3 position;
	glm::vec3 diffuse;
	glm::vec3 specular;

	void print();
};

class Sphere : public Shape {
public:
	glm::vec3 position;
	int radius;

	void print();
};

class Quad : public Shape {
public:
	glm::vec3 corner1;
	glm::vec3 corner2;
	glm::vec3 corner3;
	glm::vec3 corner4; // Do I need this??

	void print();
};

class scene {
public:
	float shininess;
	int antialias;
	int maxDepth;
	glm::vec3 backgroundColor;
	int resolutionH;
	int resolutionW;

	vector<Light*> lights;
	vector<Shape*> shapes;

	void print();
};


