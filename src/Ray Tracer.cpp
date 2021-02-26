// Ray Tracer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Ray Tracer.h"
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>


using namespace std;
using namespace antlr4;

std::vector<unsigned char> flatten(std::vector<std::vector<Pixel>> data) {
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

void TraceScene(string imageName, Image image) {
	cout << "Tracing rays through supersampled image: " << imageName << endl;
	// Trace through all the pixels are supersampled resolution
	#pragma omp parallel for 
	for (int i = 0; i < image.scene->resolutionH * image.scene->antialias; i++) {
		for (int j = 0; j < image.scene->resolutionW * image.scene->antialias; j++) {
			Ray ray = image.CalculateRay(i, j);
			glm::vec3 color = image.TraceRay(&ray, image.scene->maxDepth);
			image.data[i][j].setColor(color * 255.f);
		}
		//cout << "Tracing row: " << i << " with thread " << omp_get_thread_num() << endl;
	}

	cout << "Downsampling into final resolution" << endl;
	// Average the supersampled values
	std::vector<std::vector<Pixel>> final(image.height, std::vector<Pixel>(image.width, Pixel()));
	#pragma omp parallel for
	for (int i = 0; i < image.scene->resolutionH * image.scene->antialias; i += image.scene->antialias) {
		for (int j = 0; j < image.scene->resolutionW * image.scene->antialias; j += image.scene->antialias) {
			glm::vec4 color(0.0f);
			for (int x = 0; x < image.scene->antialias; x++) {
				for (int y = 0; y < image.scene->antialias; y++) {
					color += image.data[i + x][j + y].getColor();
				}
			}
			color /= (image.scene->antialias * image.scene->antialias);
			final[i / image.scene->antialias][j / image.scene->antialias].setColor(color);
		}
	}

	cout << "Exporting "  << imageName << endl;
	//Encode the image
	vector<unsigned char> png;
	lodepng::State state;
	//state.encoder.zlibsettings.btype = 0; // disable compression for possible speed advantage???
	unsigned error = lodepng::encode(png, flatten(final), image.scene->resolutionW, image.scene->resolutionH, state);
	if (!error) lodepng::save_file(png, imageName);
	if (error) cout << "encoder error " << error << ": " << lodepng_error_text(error) << endl;
}

Scene* parseFile(ifstream& in) {
	// ANTLR boilerplate
	ANTLRInputStream input(in);
	sceneLexer lexer(&input);
	CommonTokenStream tokens(&lexer);
	sceneParser parser(&tokens);

	sceneParser::SceneContext* tree = parser.scene();

	RTVisitor visitor;
	return (Scene*)visitor.visitScene(tree);
}


// Moved to main.cpp because the windows linker is an evil black box
//int main(int argc, const char* argv[]){
//	// Set up vectors needed for creating primary rays
//	string imageName = "RToutput.png";
//
//	ifstream in;
//	if (argc == 1) { // Default to cornell2 and RToutput.png
//		in.open("Scenes/cornell2.txt");
//	}
//	else if (argc == 2) { // Input scene specified
//		in.open(string(argv[1]));
//	}
//	else if (argc >= 3) { // Input scene and output filename specified
//		in.open(string(argv[1]));
//		imageName = string(argv[2]);
//	}
//
//
//	glm::vec3 eye = glm::vec3(0.0, 0.0, -200.0);
//	glm::vec3 lookAt = glm::vec3(0.0, 0.0, 0.0);
//	glm::vec3 up = glm::vec3(1.0, 0.0, 0.0); // Making this 1,0,0 causes image to be correct orientation. But that's a dumb solution...
//	cout << "Parsing Scene File" << endl;
//	Image image = Image(parseFile(in), eye, lookAt, up);
//	image.scene->print();
//
//	TraceScene(imageName,  image);
//}
