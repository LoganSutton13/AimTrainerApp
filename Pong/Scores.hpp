/*******************************************************************************
 * Programmer: Logan Sutton, Facundo Herrera, Cem Beyenal                      *
 * Class: CptS 122                                                             *
 * Programming Assignment: PA 9                                                *
 * Date: 4/24/2022                                                             *
 *                                                                             *
 * Description: this program is an aim trainer for online shooter games        *
 *                                                                             *
 ******************************************************************************/
#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include <fstream>
#include <string>

/*
* 	Displays score to screen during a match
*/
class Score : public sf::Text
{
public:
	// constructor for the score object
	Score(int newTextSize, sf::Vector2f newPosition);

	// increments the score by a given amount
	void incrementScore(int scoreAmnt);

	// returns the score
	int getScore(void);

	// sets the score
	void setScore(int newScore);
private:
	int mScore;
	sf::Font* font;
};
