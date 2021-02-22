// Ray Tracer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>

// Include parser and antlr4 runtime to use it
#include "antlr4-runtime/antlr4-runtime.h"
#include "antlr4-runtime/sceneLexer.h"
#include "antlr4-runtime/sceneParser.h"

// Library for encoding image as a png in the end
#include "lodepng.h"

#include "omp.h"

#include "RTVisitor.h"
#include "image.h"



using namespace std;
using namespace antlr4;


// These will have to be tweaked maybe?? Ask in class...
glm::vec3 eye = glm::vec3(0.0, 0.0, -200.0);
glm::vec3 lookAt = glm::vec3(0.0, 0.0, 0.0);
glm::vec3 up = glm::vec3(0.0, 1.0, 0.0);
float fovy = 90;

// Gramm-Schmidt
glm::vec3 l = glm::normalize(lookAt - eye);
glm::vec3 v = glm::normalize(glm::cross(l, up));
glm::vec3 u = glm::cross(u, v);
float focalLength = 1 / tan(fovy / 2);


glm::vec3 TraceRay(Ray ray, int maxDepth) {
	cout << "Tracing Ray with direction: " << to_string(ray.direction) << endl;
	glm::vec3 returned = 255.0f * ray.direction;

	return returned;
}

int main(int argc, const char* argv[])
{
	ifstream in;
	//in.open("Scenes/" + string(argv[1]));
	in.open("Scenes/cornell1.txt");

	ANTLRInputStream input(in);
	sceneLexer lexer(&input);
	CommonTokenStream tokens(&lexer);
	sceneParser parser(&tokens);

	sceneParser::SceneContext* tree = parser.scene();

	RTVisitor visitor;
	scene scene = visitor.visitScene(tree);

	scene.print();

	Image image = Image(scene.resolutionW, scene.resolutionH);

	//#pragma omp parallel for 
	for (int i = 0; i < scene.resolutionH; i++) {
		for (int j = 0; j < scene.resolutionW; j++) {
			Ray ray = image.CalculateRay(i, j);
			glm::vec3 color = TraceRay(ray, scene.maxDepth);
			image.data[i][j].setColor(color);
			//cout << "\nTracing pixel: " << i << "," << j;
		}
		cout << "Tracing row: " << i << " with thread " << omp_get_thread_num() << endl;

	}



	//Encode the image
	string imageName = "test.png";

	unsigned error = lodepng::encode(imageName.c_str(), image.flatten(), scene.resolutionW, scene.resolutionH);

	//if there's an error, display it
	if (error) cout << "encoder error " << error << ": " << lodepng_error_text(error) << endl;

}
