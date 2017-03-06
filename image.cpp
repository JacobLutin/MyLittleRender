#include "image.h"

Image::Image()
{
	size = Vector2(640, 480); 
	filename = "out.png";
	InitPixelMatrix();
}

Image::Image(const Vector2 size, const std::string filename)
{
	this->size = size;
	this->filename = filename;
	InitPixelMatrix();
}

void Image::InitOutFileStream()
{
	out.open(filename);
	return;
}

void Image::InitPixelMatrix()
{
	pixelMatrix = new Color *[(int) size.y];
	for (unsigned int i = 0; i < size.y; i++)
	{
		pixelMatrix[i] = new Color[(int) size.x];
	}

	for (unsigned int y = 0; y < size.y; y++)
	{
		for (unsigned int x = 0; x < size.x; x++)
		{
			pixelMatrix[y][x].r = 0;
			pixelMatrix[y][x].g = 0;
			pixelMatrix[y][x].b = 0;
		}
	}

	return;
}

int Image::Render()
{
	InitOutFileStream();
	
	if (!out)
	{
		return -1;
	}

	out << "P3\n" << size.x << "\n" << size.y << "\n255\n";

	for (unsigned int y = 0; y < size.y; y++)
	{
		for (unsigned int x = 0; x < size.x; x++)
		{
			out << (int) pixelMatrix[y][x].r << std::endl;
			out << (int) pixelMatrix[y][x].g << std::endl;
			out << (int) pixelMatrix[y][x].b << std::endl;
		}
	} 

	return 0;
}

void Image::setPixel(const int x, const int y, const Color color)
{
	pixelMatrix[y][x] = color;
	return;
}

Vector2 Image::getSize()
{
	return size;
}

void BresenhamLine(const Vector2 start, const Vector2 end, 
				   const Color color, Image &image)
{
	int x0 = (int) start.x;
	int x1 = (int) end.x; 
	int y0 = (int) start.y;
	int y1 = (int) end.y;

	bool steep = false;

	if (std::abs(x1 - x0) < std::abs(y1 - y0))
	{
		std::swap(x0, y0);
		std::swap(x1, y1);
		steep = true;
	}

	if (x0 > x1)
	{
		std::swap (x0, x1);
		std::swap (y0, y1);
	}

	int dy = y1 - y0;
	int dx = x1 - x0;
	float derror = std::abs(dy / float(dx));
	float error = 0;
	int y = y0;

	for (int x = 0; x <= x1; x++)
	{
		if (steep)
		{
			image.setPixel(y, x, color);
		}
		else
		{
			image.setPixel(x, y, color);
		}
		
		error += derror;

		if (error > 0.5)
		{
			y += (y1 > y0 ? 1 : -1);
			error -= 1;
		}
	} 

	return;
}