#include "Target.hpp"

Target::Target(float newRadius, const sf::Vector2f& newPosition, const sf::Color& newColor) :
	sf::CircleShape(newRadius)
{
	this->setPosition(newPosition);
	this->setOrigin((newRadius / 2), (newRadius / 2));
	this->setFillColor(newColor);
	originalColor = new sf::Color(newColor);
}

sf::Vector2f Target::generateRandomPostition(const sf::Window& window)
{
	float xCord, yCord;
	do
	{
		xCord = rand() % (window.getSize().x - (int)(0.2 * window.getSize().x)) + (int)(0.1 * window.getSize().x);
		yCord = rand() % (window.getSize().y - (int)(0.2 * window.getSize().y)) + (int)(0.1 * window.getSize().y);
	} while (xCord > window.getSize().x - 0.15 * window.getSize().x ||
		xCord < 0.15 * window.getSize().x || yCord > window.getSize().y - 0.15 * window.getSize().y ||
		xCord < 0.15 * window.getSize().y);
	return sf::Vector2f(xCord, yCord);
}

void Target::hover(bool n)
{
	if (n)
	{
		this->setOutlineThickness(2);
		this->setOutlineColor(sf::Color::White);
	}
	else
	{
		this->setOutlineThickness(0);
		this->setOutlineColor(*originalColor);
	}
}

void Target::setNewPosition(const sf::Vector2f& newPosition)
{
	this->setPosition(newPosition);
}
