#include "Block.h"
#include <SFML/Graphics.hpp>

Block::Block(float x, float y, float width, float height)
{
	shape.setFillColor(sf::Color::Magenta);
	shape.setSize({ width, height });
	shape.setPosition(x, y);
	shape.setOrigin(width / 2, height / 2);
}