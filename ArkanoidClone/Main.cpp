#include <SFML/Graphics.hpp>
#include <vector>
#include "Ball.h";
#include "Paddle.h"
#include "Block.h"

constexpr int windowWidth = 800, windowHeight = 600;
constexpr float radius = 12.f, ballVelocity = 6.f;
constexpr float paddleWidth{ 60.f }, paddleHeight{ 20.f }, paddleVelocity{ 6.f };
constexpr float blockWidth{ 60.f }, blockHeight{ 20.f };
constexpr int blockColumns = 11, blockRows = 4;

template<class T1, class T2> bool isIntersecting(T1& first, T2& second)
{
	return first.getRightEdge() >= second.getLeftEdge() 
		&& first.getLeftEdge() <= second.getRightEdge() 
		&& first.getBottomEdge() >= second.getTopEdge() 
		&& first.getTopEdge() <= second.getBottomEdge();
}

void handleCollision(Ball& ball, Paddle& paddle)
{
	ball.velocity.y = -ballVelocity;

	if (ball.getPosition().x < paddle.getPosition().x)
	{
		ball.velocity.x = -ballVelocity;
	}
	else
	{
		ball.velocity.x = ballVelocity;
	}
}

void handleCollision(Block& block, Ball& ball)
{
	block.isDestroyed = true;

	float overlapLeft{ ball.getRightEdge() - block.getLeftEdge() };
	float overlapRight{ block.getRightEdge() - ball.getLeftEdge() };
	float overlapTop{ ball.getBottomEdge() - block.getTopEdge() };
	float overlapBottom{ block.getBottomEdge() - ball.getTopEdge() };

	bool ballFromLeft(abs(overlapLeft) < abs(overlapRight));
	bool ballFromTop(abs(overlapTop) < abs(overlapBottom));

	float minOverlapX{ ballFromLeft ? overlapLeft : overlapRight };
	float minOverlapY{ ballFromTop ? overlapTop : overlapBottom };

	if (abs(minOverlapX) < abs(minOverlapY))
		ball.velocity.x = ballFromLeft ? -ballVelocity : ballVelocity;
	else
		ball.velocity.y = ballFromTop ? -ballVelocity : ballVelocity;
}

int main()
{
	sf::RenderWindow window{ {windowWidth, windowHeight}, "Arkanoid" };
	sf::Event event;
	window.setFramerateLimit(60);

	// Bounds can be defined to limit the movement of the ball inside specific bounds 
	RectBounds bounds = { 0, 0, windowWidth, windowHeight };

	Ball ball = Ball(windowWidth / 2, windowHeight / 2, radius, ballVelocity, bounds);
	Paddle paddle = Paddle(windowWidth / 2, windowHeight - 50, paddleWidth, paddleHeight, paddleVelocity, bounds);
	std::vector<Block> blocks;

	for (int i = 0; i < blockColumns; i++)
	{
		for (int j = 0; j < blockRows; j++)
		{
			blocks.emplace_back((i + 1) * (blockWidth + 3) + 22, (j + 2) * (blockHeight + 3), blockWidth, blockHeight);
		}
	}

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
			window.close();
		}

		window.clear(sf::Color::White);

		ball.update();
		paddle.update();

		if (isIntersecting(ball, paddle)) 
			handleCollision(ball, paddle);

		for (auto& block : blocks)
		{
			if (isIntersecting(ball, block)) 
			{
				handleCollision(block, ball);
				blocks.erase(std::remove_if(blocks.begin(), blocks.end(), [](const Block& block) {
					return block.isDestroyed;
					}));
			}
		}

		for (auto& block : blocks)
		{
			window.draw(block.shape);
		}

		window.draw(ball.shape);
		window.draw(paddle.shape);
		window.display();
	}
}