#pragma once
#include <SFML/Graphics.hpp>
#include "Rectangle.h"

struct Block: public Rectangle
{
	bool isDestroyed = false;

	Block(float x, float y, float width, float height);
};