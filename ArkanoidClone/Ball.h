#pragma once
#include <SFML/Graphics.hpp>
#include "RectBounds.h"

struct Ball
{
	sf::Vector2f velocity;
	sf::CircleShape shape;

	// The bounds in which the ball has to stay in
	RectBounds bounds;

	float radius;
	float ballVelocity;
	
	Ball(float x, float y, float radius, float ballVelocity, RectBounds bounds);

	void update();
	sf::Vector2f getPosition();
	float getTopEdge();
	float getBottomEdge();
	float getLeftEdge();
	float getRightEdge();
};