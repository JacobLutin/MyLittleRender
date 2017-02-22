#include <iostream>
#include <fstream>
#include <cmath>

#include "vectormath.h"
#include "color.h"
#include "image.h"

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

int main()
{
	Image image(Vector2(96, 64), "out.png");

	BresenhamLine(Vector2(0, 0), Vector2(96, 48), Color(255, 255, 255), image);
	BresenhamLine(Vector2(20, 20), Vector2(0, 31), Color(100, 250, 0), image);

	image.Render();

	return 0;
}











