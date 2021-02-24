#include "image.h"

Image::Image(Scene* s){
	scene = s;
	width = scene->resolutionW;
	height = scene->resolutionH;

	data = std::vector<std::vector<Pixel>>(height, std::vector<Pixel>(width, Pixel()));

	// Set up vectors needed for creating primary rays
	eye = glm::vec3(0.0, 0.0, -200.0);
	lookAt = glm::vec3(0.0, 0.0, 0.0);
	up = glm::vec3(1.0, 0.0, 0.0); // Making this 1,0,0 causes image to be correct orientation. But that's a dumb solution...

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

vector<Light*> Image::ShadowRays(Ray* ray){
	vector<Light*> visibleLights;
	glm::vec3 position = ray->origin + (ray->direction * ray->firstIntersectionParam);
	for (vector<Light*>::iterator it = scene->lights.begin(); it < scene->lights.end(); ++it) {
		// Check each light if it's visible
		// Construct new ray to do it
		Ray tmp = Ray(position, glm::normalize((*it)->position - position));
		float distanceToLight = glm::distance((*it)->position, position);
		//Shape* ignoreMe = ray->firstIntersection;
		intersect(&tmp, ray->firstIntersection);
		//intersect(&tmp);
		if (distanceToLight < tmp.firstIntersectionParam) {
			visibleLights.push_back(*it);
		}
	}

	return visibleLights;

}

glm::vec3 Image::Phong(Ray* ray, Light* light){
	Shape* hit = ray->firstIntersection;
	glm::vec3 normal = hit->getNormal(ray);
	glm::vec3 position = ray->origin + (ray->direction * ray->firstIntersectionParam);
	glm::vec3 toLight = glm::normalize(light->position - position);
	glm::vec3 color(0.0f);

	// Diffuse
	color += hit->diffuse * light->diffuse * max(0.f, glm::dot(normal, toLight));

	// Specular
	color += pow(glm::dot(-ray->direction, glm::reflect(toLight, normal)), scene->shininess) * light->specular * hit->specular;
	
	
	return color;
}



glm::vec3 Image::TraceRay(Ray* ray, int maxDepth){
	intersect(ray);
	Shape* hit = ray->firstIntersection;
	// Calculate shadow rays and do color things
	glm::vec3 color(0.0f);
	if (!hit) return scene->backgroundColor;
	vector<Light*> contributedLights = ShadowRays(ray);
	for (vector<Light*>::iterator it = contributedLights.begin(); it < contributedLights.end(); ++it) {
		color += Phong(ray, *it);

	}
	if (maxDepth <= 0) {
		color = glm::clamp(color, 0.f, 1.f);
		return color;
	}
	// Reflect and recurse if mirror
	glm::vec3 newOrigin = ray->origin + (ray->direction * ray->firstIntersectionParam);
	glm::vec3 newDirection = glm::reflect(ray->direction, hit->getNormal(ray)); // This might be screwing things up
	Ray* reflected = new Ray(newOrigin, newDirection);
	if (hit->isMirror) {
		color += TraceRay(reflected, maxDepth - 1);
	}
	color = glm::clamp(color, 0.f, 1.f);

	return color;
}

