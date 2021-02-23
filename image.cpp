#include "image.h"

Image::Image(int w, int h){
	width = w;
	height = h;
	data = std::vector<std::vector<Pixel>>(height, std::vector<Pixel>(width, Pixel()));

	// Set up vectors needed for creating primary rays
	eye = glm::vec3(0.0, 0.0, -200.0);
	lookAt = glm::vec3(0.0, 0.0, 0.0);
	up = glm::vec3(0.0, 1.0, 0.0);

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

// Populates the ray's list of intersections as well as mi intersection
void Image::intersect(Ray* ray){

}

glm::vec3 Image::TraceRay(Ray* ray, int maxDepth){
	intersect(ray);
	Shape* hit = ray->firstIntersection;
	// Calculate shadow rays and do color things

	// Reflect and recurse if mirror

	glm::vec3 color(abs(ray->direction.x), abs(ray->direction.y), abs(ray->direction.z));
	return color * 255.f;
}

Ray::Ray(glm::vec3 o, glm::vec3 d){
	origin = o;
	direction = glm::normalize(d);
	firstIntersection = NULL;

}

