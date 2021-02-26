#pragma once
#include <vector>
#include <string>
#include <glm/glm.hpp>

// Include parser and antlr4 runtime to use it
#include "antlr4-runtime/antlr4-runtime.h"
#include "antlr4-runtime/sceneLexer.h"
#include "antlr4-runtime/sceneParser.h"

#include "lodepng.h" // Library for encoding image as a png in the end
#include "omp.h"
#include "RTVisitor.h"
#include "image.h"

std::vector<unsigned char> flatten(std::vector<std::vector<Pixel>> data);

void TraceScene(string imageName, Image image);

Scene* parseFile(ifstream& in);