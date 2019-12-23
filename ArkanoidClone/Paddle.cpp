#include "Paddle.h"
#include "RectBounds.h"
#include <SFML/Graphics.hpp>

Paddle::Paddle(float x, float y, float width, float height, float paddleVelocity, RectBounds bounds)
{
	shape.setFillColor(sf::Color::Black);
	shape.setPosition(x, y);
	shape.setSize({ width, height });
	shape.setOrigin(width / 2, height / 2);

	this->paddleVelocity = paddleVelocity;
	this->velocity = { 0, 0 };
	this->setBounds(bounds);
}

void Paddle::update()
{
	shape.move(velocity);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && getLeftEdge() > 0) velocity.x = -paddleVelocity;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && getRightEdge() < bounds.width) velocity.x = paddleVelocity;
	else velocity.x = 0;
}
