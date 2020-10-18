#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

struct SnakeSegment
{
	SnakeSegment(int x, int y) : position(x, y) {};
	sf::Vector2i position;
};

using SnakeContainer = std::vector<SnakeSegment>;

enum class Direction { None, Up, Down, Left, Right };

class Snake {

public:
	Snake();
	Snake(int InitBlockSize);
	~Snake();

	// Helper methods.
	void setDirection(Direction dir);
	Direction getDirection();
	int getSpeed();
	sf::Vector2i getPosition();
	int getLives();
	int getScore();
	void increaseScore();
	bool hasLost();
	void setLose(); // Handle losing here.
	void toggleLost();
	void extend(); // Grow the snake.
	void reset(); // Reset to starting position.
	void move(); // Movement method.
	void tick(); // Update method.
	void cut(int segments); // Method for cutting snake.
	void renderSnake(sf::RenderWindow& window);
private:
	void checkCollision(); // Checking for collisions.
	SnakeContainer snakeBody; // Segment vector.
	int blockSize; // Size of the graphics.
	Direction currentDir; // Current direction.
	int snakeSpeed; // Speed of the snake.
	int lifeLines; // Lives.
	int totalScore; // Score.
	bool lostState; // Losing state.
	sf::RectangleShape snakeBodyRect; // Shape used in rendering.
};