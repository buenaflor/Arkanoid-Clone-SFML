#pragma once
#include <SFML/Graphics.hpp>
#include "RectBounds.h"
#include "Rectangle.h"

struct Paddle: public Rectangle
{
	sf::Vector2f velocity;
	float paddleVelocity;

	Paddle(float x, float y, float width, float height, float paddleVelocity, RectBounds bounds);

	void update();
};