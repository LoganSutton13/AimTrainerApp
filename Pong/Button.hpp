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
#include <string>
#include <fstream>
#include <iostream>


class Button
{
public:
	// constructor for button
	Button(const sf::Vector2f& newPosition, const sf::Vector2f newShapeSize, const sf::Color newColor,
		const std::string& newText, const int textSize);

	// gets the shape associated 
	sf::RectangleShape* getShape(void);

	// renders in the button
	void render(sf::RenderTarget& target);
	
	// controls the hovering properties
	void hover(bool n);

	// edits the text attribute 
	void editText(std::string& newText);
private:
	sf::Text* text;
	sf::RectangleShape* shape;
	sf::Font* font;
	sf::Color* originalColor;
};

