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

bool Shape::findIntersection(Ray* ray, float& param){
	return false; // Don't intersect parsing errors
}

glm::vec3 Shape::getNormal(Ray* ray){
	return glm::vec3(0.0);
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
	cout << "      Corner 4: " << glm::to_string(corner4) << endl;
	cout << "    Ambient Color: " << glm::to_string(ambient) << endl;
	cout << "    Specular Color: " << glm::to_string(specular) << endl;
	cout << "    Diffuse Color: " << glm::to_string(diffuse) << endl;

}

bool Quad::findIntersection(Ray* ray, float& param){
	// Quads are two triangles 123 and 243. Intersect one or the other
	if (findIntersectionTriangle(ray, param, corner1, corner2, corner3)) {
		return true;
	}
	else if (findIntersectionTriangle(ray, param, corner2, corner4, corner3)) {
		return true;
	}
	return false;
}

bool Quad::findIntersectionTriangle(Ray* ray, float& param, glm::vec3 corner1, glm::vec3 corner2, glm::vec3 corner3){
	// Moller-Trumbore intersection Aalgo
	const float EPSILON = 0.000001f;
	glm::vec3 direction = ray->direction;
	glm::vec3 side1 = corner2 - corner1;
	glm::vec3 side2 = corner3 - corner1;
	glm::vec3 pvec = glm::cross(direction, side2);
	float det = glm::dot(side1, pvec);
	if (abs(det) < EPSILON) return false;
	float invDet = 1 / det;
	glm::vec3 tvec = ray->origin - corner1;
	float u = glm::dot(tvec, pvec) * invDet;
	if (u < 0 || u > 1) return false;
	glm::vec3 qvec = glm::cross(tvec, side1);
	float v = glm::dot(direction, qvec) * invDet;
	if (v < 0 || u + v > 1) return false;
	param = glm::dot(side2, qvec) * invDet;
	return true;
}


glm::vec3 Quad::getNormal(Ray* ray){
	// Return normal of 1st triangle
	// If second triangle normal is differnt, that's on you for making a broken quad
	return glm::normalize(glm::cross(corner3 - corner1, corner2-corner1));
}

bool Sphere::findIntersection(Ray* ray, float& param) {
	const float EPSILON = 0.0000001f;
	glm::vec3 originLessCenter = ray->origin - position;
	float halfB = glm::dot(ray->direction, originLessCenter);
	float discriminant = pow(halfB, 2) - (pow(glm::length(originLessCenter), 2) - radiusSquared);

	if (discriminant < -EPSILON) return false; // No intersections
	else if (discriminant <= EPSILON) { // One Intersection
		param = -halfB;
		return true;
	}
	else if (discriminant > EPSILON) { // Two Intersections
		// Optimize by delaying square root till after comparison. Ask about it
		float d1 = -halfB + sqrt(discriminant);
		float d2 = -halfB - sqrt(discriminant);
		if (d1 > 0 && d2 > 0) {
			param = (d1 < d2) ? d1 : d2;
			return true;
		}
		else if (d1 > 0) {
			param = d1;
			return true;
		}
		else if (d2 > 0) {
			param = d2;
			return true;
		}
		else return false; // Maybe move this case sooner as well
	}

	return false; // Just to make the compiler happy

}

glm::vec3 Sphere::getNormal(Ray* ray){
	glm::vec3 intersection = ray->origin + (ray->direction * ray->firstIntersectionParam);
	return glm::normalize(intersection - position);
}


