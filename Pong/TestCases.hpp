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
#include "List.hpp"
#include "Button.hpp"
#include "Target.hpp"
#include "Scores.hpp"

/*
* 	Tests functionality of program
*	All tests are run before the game starts
*	Results of test are displayed to the console
*/
class Test
{
public:
	// tests the insert in order of a list
	void testInsertInOrder();
	// tests printing to a dummy csv file
	void testPrintCSV();
	// tests incrementing the score
	void testIncrementScore();
	// tests generating a random position for the target
	void testGenerateRandomPosition();
	// testing importing from a file
	void testImport();
private:

};