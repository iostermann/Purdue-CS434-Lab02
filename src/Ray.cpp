#include "Ray.h"

Ray::Ray(glm::vec3 o, glm::vec3 d) {
	origin = o;
	direction = glm::normalize(d);
	firstIntersection = NULL;

}

