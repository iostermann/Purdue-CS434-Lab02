#include "image.h"

Image::Image(Scene* s){
	scene = s;
	width = scene->resolutionW;
	height = scene->resolutionH;

	data = std::vector<std::vector<Pixel>>(height, std::vector<Pixel>(width, Pixel()));

	// Set up vectors needed for creating primary rays
	eye = glm::vec3(0.0, 0.0, -200.0);
	lookAt = glm::vec3(0.0, 0.0, 0.0);
	up = glm::vec3(0.0, 1.0, 0.0); // Making this 1,0,0 causes image to be correct orientation. But that's a dumb solution...

	l = glm::normalize(lookAt - eye);
	v = glm::normalize(glm::cross(l, up));
	u = glm::cross(v, l);

	focalLength = 1 / tan(fovy / 2);
	aspectRatio = (float)width / (float)height;

	ll = eye + (focalLength * l) - (aspectRatio * v) - u;

	primaryRayHelper = 2.0f * aspectRatio * v;
}

Image::~Image(){

}

std::vector<unsigned char> Image::flatten()
{
	std::vector<unsigned char> flattened;
	for (auto& row : data) {
		for (auto& pixel : row) {
			flattened.push_back(pixel.r);
			flattened.push_back(pixel.g);
			flattened.push_back(pixel.b);
			flattened.push_back(pixel.a);

		}
	}

	return flattened;
}

Ray Image::CalculateRay(int i, int j){
	//glm::vec3 p = ll + (2.0f * aspectRatio * v * (float)i / (float)width) + (2.0f * u * (float)j / (float) height);
	glm::vec3 p = ll + (primaryRayHelper * (float)i /  (float)width) + (2.0f * u * (float)j / (float)height);
	glm::vec3 d = glm::normalize(p - eye);

	Ray ray = Ray(eye, d);

	return ray;
}

// Populates the ray's list of intersections as well as finds the first intersection
void Image::intersect(Ray* ray){
	Shape* closest = NULL;
	float closestParam = INFINITY;
	for (vector<Shape*>::iterator it = scene->shapes.begin(); it < scene->shapes.end(); ++it ) {
		float param = (*it)->findIntersection(ray);
		if (param) {
			ray->intersections.emplace(*it, param);
			if (param < closestParam) {
				closest = *it;
				closestParam = param;
			}
		}
	}
	ray->firstIntersection = closest;
}

glm::vec3 Image::TraceRay(Ray* ray, int maxDepth){
	intersect(ray);
	Shape* hit = ray->firstIntersection;
	// Calculate shadow rays and do color things
	glm::vec3 color(0.0f);
	if (!hit) {
		return scene->backgroundColor;
	}
	color = glm::vec3(255.0f, 255.0f, 0.0f);

	// Reflect and recurse if mirror

	return color;
}

