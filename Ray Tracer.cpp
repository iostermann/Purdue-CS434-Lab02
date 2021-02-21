// Ray Tracer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>

#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>

// Include parser and antlr4 runtime to use it
#include "antlr4-runtime/antlr4-runtime.h"
#include "antlr4-runtime/sceneLexer.h"
#include "antlr4-runtime/sceneParser.h"

// Library for encoding image as a png in the end
#include "lodepng.h"

#include"RTVisitor.h"



using namespace std;
using namespace antlr4;

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

	

	//Encode the image
	string imageName = "test.png";
	vector<unsigned char> image;

	for (int height = 0; height < scene.resolutionH; height++) {
		for (int width = 0; width < scene.resolutionW; width++) {
			image.push_back(height % 255);
			image.push_back(width % 255);
			image.push_back((height + width) % 255);
			image.push_back(255);
		}
	}

	unsigned error = lodepng::encode(imageName.c_str(), image, scene.resolutionW, scene.resolutionH);

	//if there's an error, display it
	if (error) cout << "encoder error " << error << ": " << lodepng_error_text(error) << endl;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
