#include "Rectangle.h"
#include "RectBounds.h"

void Rectangle::setBounds(RectBounds bounds)
{
	this->bounds = bounds;
}

sf::Vector2f Rectangle::getPosition()
{
	return Rectangle::shape.getPosition();
}

float Rectangle::getTopEdge()
{
	return getPosition().y - shape.getSize().y / 2.f;
}

float Rectangle::getBottomEdge()
{
	return getPosition().y + shape.getSize().y / 2.f;
}

float Rectangle::getLeftEdge()
{
	return getPosition().x - shape.getSize().x / 2.f;
}

float Rectangle::getRightEdge()
{
	return getPosition().x + shape.getSize().x / 2.f;
}