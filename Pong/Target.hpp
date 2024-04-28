/*******************************************************************************
 * Programmer: Logan Sutton, Facundo Herrera, Cem Beyenal                      *
 * Class: CptS 122                                                             *
 * Programming Assignment: PA 9                                                *
 * Date: 4/24/2022                                                             *
 *                                                                             *
 * Description: this program is an aim trainer for online shooter games        *
 *                                                                             *
 ******************************************************************************/
#include <SFML/Graphics.hpp>

/*
* 	Represents target for player to hit
* 	Can change color and size depending on difficulty
*/
class Target : public sf::CircleShape
{
public:
	// target constructor
	Target(float newRadius, const sf::Vector2f& newPosition, const sf::Color& newColor);

	// sets the new position of the target
	void setNewPosition(const sf::Vector2f& newPosition);

	// generates a random position with constraints, returns a sf::Vector2f of the new position
	sf::Vector2f generateRandomPostition(const sf::Window& window);

	// determines wheter to have the 'hover' endabled or disabled 
	void hover(bool n);

private:
	sf::Color* originalColor;

};