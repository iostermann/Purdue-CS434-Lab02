#include "scene.h"
#include <iostream>
#include <glm/gtx/string_cast.hpp>

using namespace std;

void Scene::print()
{
	cout << "Parsed Scene Description: " << endl;
	cout << "  Shininess: " << shininess << endl;
	cout << "  Anti Aliasing Level: " << antialias << endl;
	cout << "  Max recursion Depth: " << maxDepth << endl;
	cout << "  Resolution: " << resolutionW << "x" << resolutionH << endl; 
	cout << "  Background Color: " << glm::to_string(backgroundColor) << endl;

	for (auto& light : lights) {
		light->print();
	}

	for (auto& shape : shapes) {
		shape->print();
	}


}

void Light::print()
{
	cout << "  Light" << endl;
	cout << "    Position: " << glm::to_string(position) << endl;
	cout << "    Specular Color: " << glm::to_string(specular) << endl;
	cout << "    Diffuse Color: " << glm::to_string(diffuse) << endl;

}
