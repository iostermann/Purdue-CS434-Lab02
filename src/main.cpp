// Separate main file so that I can link functions in the other project withot the linker exploding
#include "Ray Tracer.h"

int main(int argc, const char* argv[]) {
	// Set up vectors needed for creating primary rays
	string imageName = "RToutput.png";

	ifstream in;
	if (argc == 1) { // Default to cornell2 and RToutput.png
		in.open("Scenes/cornell2.txt");
	}
	else if (argc == 2) { // Input scene specified
		in.open(string(argv[1]));
	}
	else if (argc >= 3) { // Input scene and output filename specified
		in.open(string(argv[1]));
		imageName = string(argv[2]);
	}


	glm::vec3 eye = glm::vec3(0.0, 0.0, -200.0);
	glm::vec3 lookAt = glm::vec3(0.0, 0.0, 0.0);
	glm::vec3 up = glm::vec3(1.0, 0.0, 0.0); // Making this 1,0,0 causes image to be correct orientation. But that's a dumb solution...
	cout << "Parsing Scene File" << endl;
	Image image = Image(parseFile(in), eye, lookAt, up);
	image.scene->print();

	TraceScene(imageName, image);
}
