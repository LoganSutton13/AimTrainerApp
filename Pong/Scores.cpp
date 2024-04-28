#include "Scores.hpp"

Score::Score(int newTextSize, sf::Vector2f newPosition)
{
	mScore = 0;
	font = new sf::Font;
	font->loadFromFile("ARIAL.TTF");
	this->setFont(*font);
	this->setCharacterSize(newTextSize);
	this->setFillColor(sf::Color::White);
	this->setPosition(newPosition);
	this->setStyle(sf::Text::Bold);
	this->setString("Score: 0");
}

void Score::incrementScore(int scoreAmnt)
{
	mScore += scoreAmnt;
	if (mScore < 0) mScore = 0;
	this->setString("Score: " + std::to_string(mScore));
}

int Score::getScore(void)
{
	return mScore;
}

void Score::setScore(int newScore)
{
	mScore = newScore;
	this->setString("Score: " + std::to_string(mScore));
}