#include "image.h"

Image::Image(Scene* scene, glm::vec3 eye, glm::vec3 lookAt, glm::vec3 up) {
	this-> scene = scene;
	this->width = scene->resolutionW;
	this->height = scene->resolutionH;
	this->eye = eye;
	this->lookAt = lookAt;
	this->up = up;

	data = std::vector<std::vector<Pixel>>(height * scene->antialias, std::vector<Pixel>(width * scene->antialias, Pixel()));

	

	l = glm::normalize(lookAt - eye);
	v = glm::normalize(glm::cross(l, up));
	u = glm::cross(v, l);

	focalLength = 1 / tan(fovy / 2);
	aspectRatio = (float)width / (float)height;

	ll = eye + (focalLength * l) - (aspectRatio * v) - u;

	primaryRayHelper = 2.0f * aspectRatio * v;
}



Ray Image::CalculateRay(int i, int j){
	glm::vec3 p = ll + (primaryRayHelper * (float)i /  ((float)width * scene->antialias)) + (2.0f * u * (float)j / ((float)height * scene->antialias));
	glm::vec3 d = glm::normalize(p - eye);
	Ray ray = Ray(eye, d);
	return ray;
}

// Populates the ray's list of intersections as well as finds the first intersection
void Image::intersect(Ray* ray){
	const float EPSILON = 0.0000001;
	Shape* closest = NULL;
	float closestParam = INFINITY;
	for (vector<Shape*>::iterator it = scene->shapes.begin(); it < scene->shapes.end(); ++it ) {
		float param;
		if((*it)->findIntersection(ray, param) && param > EPSILON){
			ray->intersections.emplace(*it, param);
			if (param < closestParam) {
				closest = *it;
				closestParam = param;
			}
		}
	}
	ray->firstIntersectionParam = closestParam;
	ray->firstIntersection = closest;
}

void Image::intersect(Ray* ray, Shape* ignore){
	const float EPSILON = 0.0000001;
	Shape* closest = NULL;
	float closestParam = INFINITY;
	for (vector<Shape*>::iterator it = scene->shapes.begin(); it < scene->shapes.end(); ++it) {
		float param;
		if (*it == ignore) continue; // Shadow rays can't self intersect object
		if ((*it)->findIntersection(ray, param) && param > EPSILON) {
			ray->intersections.emplace(*it, param);
			if (param < closestParam) {
				closest = *it;
				closestParam = param;
			}
		}
	}
	ray->firstIntersectionParam = closestParam;
	ray->firstIntersection = closest;
}

list<Light*> Image::ShadowRays(Ray* ray){
	list<Light*> visibleLights;
	glm::vec3 position = ray->origin + (ray->direction * ray->firstIntersectionParam);
	for (list<Light*>::iterator it = scene->lights.begin(); it != scene->lights.end(); ++it) {
		// Check each light if it's visible
		Ray tmp = Ray(position, glm::normalize((*it)->position - position));
		float distanceToLight = glm::distance((*it)->position, position);
		intersect(&tmp, ray->firstIntersection);
		if (distanceToLight < tmp.firstIntersectionParam) {
			visibleLights.push_back(*it);
		}
	}
	return visibleLights;
}

glm::vec3 Image::Phong(Ray* ray, Light* light){
	Shape* hit = ray->firstIntersection;
	glm::vec3 normal = hit->getNormal(ray);
	glm::vec3 position = ray->origin + (ray->direction * (ray->firstIntersectionParam));
	glm::vec3 toLight = glm::normalize(light->position - position);
	glm::vec3 color(0.0f);

	// Diffuse
	color += hit->diffuse * light->diffuse * max(0.f, glm::dot(normal, toLight));

	// Specular
	color += pow(glm::dot(-ray->direction, glm::reflect(toLight, normal)), scene->shininess) * light->specular * hit->specular;

	return color;
}



glm::vec3 Image::TraceRay(Ray* ray, int maxDepth){
	const float EPSILON = 0.01f; // Kick the reflected ray out just enough so it isn't inside a collided object

	intersect(ray);
	Shape* hit = ray->firstIntersection;
	if (!hit) return scene->backgroundColor;

	// Accumulate Color
	glm::vec3 color(0.0f);
	list<Light*> contributedLights = ShadowRays(ray);
	for (list<Light*>::iterator it = contributedLights.begin(); it != contributedLights.end(); ++it) {
		color += Phong(ray, *it);
	}
	if (maxDepth <= 0) {
		color = glm::clamp(color, 0.f, 1.f);
		return color;
	}

	// Reflect and recurse if mirror
	if (hit->isMirror) {
		glm::vec3 newOrigin = ray->origin + (ray->direction * (ray->firstIntersectionParam - EPSILON));
		glm::vec3 newDirection = glm::reflect(ray->direction, hit->getNormal(ray));
		Ray* reflected = new Ray(newOrigin, newDirection);
		color += TraceRay(reflected, maxDepth - 1);
		delete reflected;
	}
	color = glm::clamp(color, 0.f, 1.f);
	return color;
}

