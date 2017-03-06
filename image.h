#ifndef IMAGE_H
#define IMAGE_H

#include <fstream>
#include <string>

#include "vectormath.h"
#include "color.h"

class Image
{
private:
	Vector2 size;
	std::ofstream out;
	std::string filename;
	Color **pixelMatrix;
	void InitPixelMatrix();
	void InitOutFileStream();
public:
	Image();
	Image(const Vector2 size, const std::string filename);
	int Render();
	void setPixel(const int x, const int y, const Color color);
	Vector2 getSize();
};

void BresenhamLine(const Vector2 start, const Vector2 end, 
				   const Color color, Image &image);

#endif