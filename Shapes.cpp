#include "Shapes.h"
#include <iostream>
#include <glm/gtx/string_cast.hpp>


using namespace std;

void Shape::print()
{
	cout << "  Shape" << endl;
	cout << "    Ambient Color: " << glm::to_string(ambient) << endl;
	cout << "    Specular Color: " << glm::to_string(specular) << endl;
	cout << "    Diffuse Color: " << glm::to_string(diffuse) << endl;
}

float Shape::findIntersection(Ray* ray){
	return NULL; // Don't intersect parsing errors
}

void Sphere::print()
{
	cout << "  Sphere" << endl;
	cout << "    Position: " << glm::to_string(position) << endl;
	cout << "    Radius: " << radius << endl;
	cout << "    Ambient Color: " << glm::to_string(ambient) << endl;
	cout << "    Specular Color: " << glm::to_string(specular) << endl;
	cout << "    Diffuse Color: " << glm::to_string(diffuse) << endl;

}

void Quad::print()
{
	cout << "  Quad" << endl;
	cout << "    Corners: " << endl;
	cout << "      Corner 1: " << glm::to_string(corner1) << endl;
	cout << "      Corner 2: " << glm::to_string(corner2) << endl;
	cout << "      Corner 3: " << glm::to_string(corner3) << endl;
	cout << "    Ambient Color: " << glm::to_string(ambient) << endl;
	cout << "    Specular Color: " << glm::to_string(specular) << endl;
	cout << "    Diffuse Color: " << glm::to_string(diffuse) << endl;

}

float Quad::findIntersection(Ray* ray)
{
	return NULL; //There are no quads right now
}

float Sphere::findIntersection(Ray* ray) {
	const float EPSILON = 0.0000001f;
	float a;
	float c;
	glm::vec3 originLessCenter = ray->origin - position;
	float halfB = glm::dot(ray->direction, originLessCenter);
	float discriminant = pow(halfB, 2) - (pow(glm::length(originLessCenter), 2) - radiusSquared);

	if (discriminant < -EPSILON) return NULL; // No intersections
	else if (discriminant <= EPSILON) return -halfB; // One Intersection
	else if (discriminant > EPSILON) { // Two Intersections
		// Optimize by delaying square root till after comparison. Ask about it
		float d1 = -halfB + sqrt(discriminant);
		float d2 = -halfB - sqrt(discriminant);
		if (d1 > 0 && d2 > 0) {
			return (d1 < d2) ? d1 : d2;
		}
		else if (d1 > 0) {
			return d1;
		}
		else if (d2 > 0) {
			return d2;
		}
		else return NULL; // Maybe move this case sooner as well
	}

	return NULL; // Just to make the compiler happy

}


