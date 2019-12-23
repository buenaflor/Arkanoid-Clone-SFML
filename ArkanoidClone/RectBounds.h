#pragma once
#include <SFML/Graphics.hpp>

struct RectBounds
{
	sf::Vector2f origin;
	float width;
	float height;

	RectBounds(float x, float y, float width, float height);

	// Default constructor
	RectBounds();
};