#include "image.h"

Image::Image(int w, int h){
	width = w;
	height = h;
	data = std::vector<std::vector<Pixel>>(height, std::vector<Pixel>(width, Pixel()));
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

Ray::Ray(glm::vec3 o, glm::vec3 d)
{
	origin = o;
	direction = glm::normalize(d);

}
