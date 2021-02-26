// Movie Maker.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Ray Tracer.h"
#include <glm/gtx/transform.hpp>
#include <glm/gtx/rotate_vector.hpp>

const string usage = \
"Welcome to my Ray Traced movie maker, please use the following input format:\n"
"\t \'.\\Movie Maker.exe numFrames \'\n"
"Using default scene Scenes\\movieBase.txt"
"Warning: default values will render 600 frames";

using namespace std;
using namespace antlr4;

int main(int argc, const char* argv[]){
	string inSceneFilename = "Scenes/movieBase.txt";
	string outFrameFilename = "Frames/MovieFrame";
	string outMovieFilename = "RTMovie";
	int numframes = 600;
	if (argc == 1) { // Default to cornell2 and RToutput.png
		cout << usage << endl;
	}
	if (argc == 2) {
		numframes = atoi(argv[1]);
	}
	else if (argc == 4) {
		inSceneFilename = argv[1];
		outFrameFilename = argv[2];
		outMovieFilename = argv[3];
	}

	ifstream in;
	in.open(inSceneFilename);

	glm::vec3 eye = glm::vec3(0.0, 0.0, -200.0);
	glm::vec3 lookAt = glm::vec3(0.0, 0.0, 0.0);
	glm::vec3 up = glm::vec3(1.0, 0.0, 0.0); // Making this 1,0,0 causes image to be correct orientation. But that's a dumb solution...
	cout << "Parsing Scene File" << endl;
	Scene* scene = parseFile(in);


	for (int i = 0; i < numframes; i++) {		
		string numberStr = to_string(i);
		string tmpFileName = outFrameFilename + numberStr + ".png";
		Image image = Image(scene, eye, lookAt, up);
		// Rotate all the spheres around the origin
		for (auto& shape : image.scene->shapes) {
			shape->rotate(0.01f);
		}
		TraceScene(tmpFileName, image);
	}

	// Stitch them together
	string command = ".\\ffmpeg.exe -r 60 -f image2 -s 800x800 -i Frames\\MovieFrame%d.png -vcodec libx264 -crf 1 -pix_fmt yuv420p RTMovie.mp4";
	system(command.c_str());


}

