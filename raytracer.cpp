#include <iostream>
#include <fstream>
#include <cmath>

#include "vectormath.h"
#include "color.h"
#include "image.h"

int main()
{
	Image image(Vector2(96, 64), "out.png");

	BresenhamLine(Vector2(0, 0), Vector2(96, 48), Color(255, 255, 255), image);
	BresenhamLine(Vector2(20, 20), Vector2(0, 31), Color(100, 250, 0), image);

	image.Render();

	return 0;
}











