#include <iostream>
#include <fstream>
#include <cmath>

#include "vectormath.h"
#include "color.h"

void BresenhamLine(const Vector2 start, const Vector2 end, 
				   const Color color, Color **pixelTab)
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
			pixelTab[x][y] = color;
		}
		else
		{
			pixelTab[y][x] = color;
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

int main()
{

	const int W = 300;
	const int H = 200;

	Color **pixelTab;
	pixelTab = new Color *[H];
	for (int i = 0; i < H; i++)
	{
		pixelTab[i] = new Color[W];
	}

	
	for (unsigned int y = 0; y < H; y++)
	{
		for (unsigned int x = 0; x < W; x++)
		{
			pixelTab[y][x].r = 255;
			pixelTab[y][x].g = 255;
			pixelTab[y][x].b = 255;
		}
	}

	BresenhamLine(Vector2(0, 0), Vector2(100, 50), Color(0, 0, 0), pixelTab);
	BresenhamLine(Vector2(0, 50), Vector2(100, 100), Color(100, 250, 0), pixelTab);

	std::ofstream out("out.png");
	out << "P3\n" << W << "\n" << H << "\n255\n";

	for (unsigned int y = 0; y < H; y++)
	{
		for (unsigned int x = 0; x < W; x++)
		{
			out << (int) pixelTab[y][x].r << std::endl;
			out << (int) pixelTab[y][x].g << std::endl;
			out << (int) pixelTab[y][x].b << std::endl;
		}
	}

	return 0;
}











