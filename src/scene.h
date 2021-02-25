#pragma once
#include <glm/glm.hpp>
#include <vector>
#include "Shapes.h"
#include <list>


using namespace std;


class Light {
public:
	glm::vec3 position;
	glm::vec3 diffuse;
	glm::vec3 specular;

	void print();
};


class Scene {
public:
	float shininess;
	int antialias;
	int maxDepth;
	glm::vec3 backgroundColor;
	int resolutionH;
	int resolutionW;

	list<Light*> lights;
	vector<Shape*> shapes;

	void print();
};


