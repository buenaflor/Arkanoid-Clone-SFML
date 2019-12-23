#include <SFML/Graphics.hpp>
#include "Ball.h"

Ball::Ball(float x, float y, float radius, float ballVelocity, RectBounds bounds)
{
	shape.setFillColor(sf::Color::Black);
	shape.setPosition(x, y);
	shape.setRadius(radius);
	shape.setOrigin(radius, radius);

	this->radius = radius;
	this->ballVelocity = ballVelocity;
	this->velocity = { -ballVelocity, -ballVelocity };
	this->bounds = bounds;
}

void Ball::update()
{
	shape.move(velocity);

	if (getLeftEdge() < 0) velocity.x = ballVelocity;
	else if (getRightEdge() > bounds.width) velocity.x = -ballVelocity;

	if (getTopEdge() < 0) velocity.y = ballVelocity;
	else if (getBottomEdge() > bounds.height) velocity.y = -ballVelocity;
}

sf::Vector2f Ball::getPosition()
{
	return Ball::shape.getPosition();
}

float Ball::getTopEdge()
{
	return getPosition().y - radius;
}

float Ball::getBottomEdge()
{
	return getPosition().y + radius;
}

float Ball::getLeftEdge()
{
	return getPosition().x - radius;
}

float Ball::getRightEdge()
{
	return getPosition().x + radius;
}