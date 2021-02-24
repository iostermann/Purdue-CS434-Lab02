#pragma once
#include <glm/glm.hpp>
#include <map>

class Shape;

class Ray
{
public:
	glm::vec3 origin;
	glm::vec3 direction;
	std::map<Shape*, float> intersections; // Map might be a not great DS to use
	Shape* firstIntersection; // Populated when intersections is

	Ray(glm::vec3 o, glm::vec3 d);



};