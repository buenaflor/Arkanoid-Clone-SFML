#include "RectBounds.h"
#include <SFML/Graphics.hpp>

RectBounds::RectBounds()
{
	origin = { 0, 0 };
	this->width = 800;
	this->height = 600;
}

RectBounds::RectBounds(float x, float y, float width, float height)
{
	origin = { x, y };
	this->width = width;
	this->height = height;
}