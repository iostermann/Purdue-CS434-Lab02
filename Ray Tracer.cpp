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
	//Scene scene = visitor.visitScene(tree);
	Image image = Image((Scene*)visitor.visitScene(tree));
	image.scene->print();


	#pragma omp parallel for 
	for (int i = 0; i < image.scene->resolutionH * image.scene->antialias; i++) {
		for (int j = 0; j < image.scene->resolutionW * image.scene->antialias; j++) {
			Ray ray = image.CalculateRay(i, j); 
			glm::vec3 color = image.TraceRay(&ray, image.scene->maxDepth);
			image.data[i][j].setColor(color * 255.f);
			//cout << "\nTracing pixel: " << i << "," << j;
		}
		//cout << "Tracing row: " << i << " with thread " << omp_get_thread_num() << endl;

	}

	// Average the supersampled values
	std::vector<std::vector<Pixel>> final(image.height, std::vector<Pixel>(image.width, Pixel()));
	#pragma omp parallel for
	for (int i = 0; i < image.scene->resolutionH * image.scene->antialias; i+= image.scene->antialias) {
		for (int j = 0; j < image.scene->resolutionW * image.scene->antialias; j+= image.scene->antialias) {
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

	
	//Encode the image
	string imageName = "test.png";
	std::vector<unsigned char> png;
	lodepng::State state;
	//state.encoder.zlibsettings.btype = 0; // disable compression for possible speed advantage???
	unsigned error = lodepng::encode(png, flatten(final), image.scene->resolutionW, image.scene->resolutionH, state);
	if (!error) lodepng::save_file(png, imageName);
	if (error) cout << "encoder error " << error << ": " << lodepng_error_text(error) << endl;

}
