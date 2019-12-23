#pragma once
#include <SFML/Graphics.hpp>
#include "RectBounds.h"

struct Rectangle
{
	RectBounds bounds;
	sf::RectangleShape shape;
	sf::Vector2f getPosition();
	float getTopEdge();
	float getBottomEdge();
	float getLeftEdge();
	float getRightEdge();
	void setBounds(RectBounds bounds);
};