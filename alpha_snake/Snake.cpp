#include "Snake.h"

Snake::Snake()
{
}

Snake::Snake(int InitBlockSize)
{
	blockSize = InitBlockSize;
	snakeBodyRect.setSize(sf::Vector2f(blockSize - 1, blockSize - 1));
	reset();
}

Snake::~Snake()
{
}

void Snake::reset()
{
	snakeBody.clear();
	snakeBody.push_back(SnakeSegment(5, 7));
	snakeBody.push_back(SnakeSegment(5, 6));
	snakeBody.push_back(SnakeSegment(5, 5));
	setDirection(Direction::None); // Start off still.
	snakeSpeed = 2;
	lifeLines = 3;
	totalScore = 0;
	lostState = false;
}

void Snake::move()
{
	for (int i = snakeBody.size() - 1; i > 0; --i) {
		snakeBody[i].position = snakeBody[i - 1].position;
	}
	if (currentDir == Direction::Left) {
		--snakeBody[0].position.x;
	}
	else if (currentDir == Direction::Right) {
		++snakeBody[0].position.x;
	}
	else if (currentDir == Direction::Up) {
		--snakeBody[0].position.y;
	}
	else if (currentDir == Direction::Down) {
		++snakeBody[0].position.y;
	}
}

void Snake::tick()
{
	if (snakeBody.empty()) { return; }
	if (currentDir == Direction::None) { return; }
	move();
	checkCollision();
}

void Snake::cut(int segments)
{
	for (int i = 0; i < segments; ++i) {
		snakeBody.pop_back();
	}
	--lifeLines;
	if (!lifeLines) { setLose(); return; }
}

void Snake::renderSnake(sf::RenderWindow& window)
{
	if (snakeBody.empty()) { return; }
	auto head = snakeBody.begin();
	snakeBodyRect.setFillColor(sf::Color::Yellow);
	snakeBodyRect.setPosition(head->position.x * blockSize,
		head->position.y * blockSize);
	window.draw(snakeBodyRect);
	snakeBodyRect.setFillColor(sf::Color::Green);
	for (auto itr = snakeBody.begin() + 1;
		itr != snakeBody.end(); ++itr)
	{
		snakeBodyRect.setPosition(itr->position.x * blockSize,
			itr->position.y * blockSize);
		window.draw(snakeBodyRect);
	}
}

void Snake::checkCollision()
{
	if (snakeBody.size() < 5) { return; }
	SnakeSegment& head = snakeBody.front();
	for (auto itr = snakeBody.begin() + 1;
		itr != snakeBody.end(); ++itr)
	{
		if (itr->position == head.position) {
			int segments = snakeBody.end() - itr;
			cut(segments);
			break;
		}
	}
}


void Snake::setDirection(Direction dir)
{
	currentDir = dir;
}

Direction Snake::getDirection()
{
	return currentDir;
}

int Snake::getSpeed()
{
	return snakeSpeed;
}

sf::Vector2i Snake::getPosition()
{
	if (!snakeBody.empty()) {
		return snakeBody.front().position;
	}
	return sf::Vector2i(1, 1);
}

int Snake::getLives()
{
	return lifeLines;
}

int Snake::getScore()
{
	return totalScore;
}

void Snake::increaseScore()
{
	totalScore += 1;
}

bool Snake::hasLost()
{
	return lostState;
}

void Snake::setLose()
{
	lostState = true;
}

void Snake::toggleLost()
{
	lostState = !lostState;
}

void Snake::extend()
{
	if (snakeBody.empty()) { return; }
	SnakeSegment& tail_head =
		snakeBody[snakeBody.size() - 1];
	if (snakeBody.size() > 1) {
		SnakeSegment& tail_bone =
			snakeBody[snakeBody.size() - 2];
		if (tail_head.position.x == tail_bone.position.x) {
			if (tail_head.position.y > tail_bone.position.y) {
				snakeBody.push_back(SnakeSegment(
					tail_head.position.x, tail_head.position.y + 1));
			}
			else {
				snakeBody.push_back(SnakeSegment(
					tail_head.position.x, tail_head.position.y - 1));
			}
		}
		else if (tail_head.position.y == tail_bone.position.y) {
			if (tail_head.position.x > tail_bone.position.x) {
				snakeBody.push_back(SnakeSegment(
					tail_head.position.x + 1, tail_head.position.y));
			}
			else {
				snakeBody.push_back(SnakeSegment(
					tail_head.position.x - 1, tail_head.position.y));
			}
		}
	}
	else {
		if (currentDir == Direction::Up) {
			snakeBody.push_back(SnakeSegment(
				tail_head.position.x, tail_head.position.y + 1));
		}
		else if (currentDir == Direction::Down) {
			snakeBody.push_back(SnakeSegment(
				tail_head.position.x, tail_head.position.y - 1));
		}
		else if (currentDir == Direction::Left) {
			snakeBody.push_back(SnakeSegment(
				tail_head.position.x + 1, tail_head.position.y));
		}
		else if (currentDir == Direction::Right) {
			snakeBody.push_back(SnakeSegment(
				tail_head.position.x - 1, tail_head.position.y));
		}
	}
}


