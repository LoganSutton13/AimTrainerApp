#include "Button.hpp"

Button::Button(const sf::Vector2f& newPosition, const sf::Vector2f newShapeSize, const sf::Color newColor,
	const std::string& newText, const int textSize)
{
	// stores the font in memory, sf::Font is stupid and if it destructed while a sf::Text object is 
	// instantiated, the sf::Text object no longer knows what to do with itself :(
	font = new sf::Font;
	font->loadFromFile("ARIAL.TTF");

	originalColor = new sf::Color(newColor);

	text = new sf::Text(newText, *font, textSize);
	this->text->setStyle(sf::Text::Bold);
	this->text->setFillColor(sf::Color::White);
	this->text->setOrigin(text->getLocalBounds().width / 2, text->getLocalBounds().height / 2);
	this->text->setPosition(sf::Vector2f(newPosition.x, newPosition.y - 5));


	shape = new sf::RectangleShape(newShapeSize);
	this->shape->setFillColor(*originalColor);
	this->shape->setOrigin(shape->getLocalBounds().width / 2, shape->getLocalBounds().height / 2);
	this->shape->setPosition(newPosition);
	this->shape->setOutlineColor(*originalColor);
	this->shape->setOutlineThickness(6);


	//this->text->setPosition(shape->getOrigin().x, shape->getOrigin().y);
}

void Button::render(sf::RenderTarget& target)
{
	target.draw(*shape);
	target.draw(*text);
}

void Button::hover(bool n)
{
	if (n)
	{
		//this->shape->setFillColor(sf::Color(80808));
		this->shape->setOutlineColor(sf::Color::Yellow);
	}
	else
	{
		this->shape->setFillColor(*originalColor);
		this->shape->setOutlineColor(*originalColor);
	}
}

sf::RectangleShape* Button::getShape(void)
{
	return shape;
}

void Button::editText(std::string& newText)
{
	text->setString(newText);
	this->text->setOrigin(text->getLocalBounds().width / 2, text->getLocalBounds().height / 2);
}