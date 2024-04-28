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
#include <iostream>
#include <string>
#include <fstream>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::fstream;
using std::ostream;
using std::ofstream;

/*
* 	Stores stats about a round played
* 	Stats are: score, hits, misses, name
*	Supports basic getters/setters
*	Used by List to record each match
*/
class Data
{
public:
	Data(int& newScore, int& newHits, int& newMisses, string& newPlayerName);
	Data();

	// Getters
	int getScore();
	int getHits();
	int getMisses();
	string getName();
	float getAccuracy();

	// Setters
	void setScore(int& newScore);
	void setHits(int& newHits);
	void setMisses(int& newMisses);
	void setName(string& newName);
	void setAccuracy(float& newAccuracy);
private:
	int mScore;
	int mHits;
	int mMisses;
	string mName;
	float mAccuracy;
};

ofstream& operator << (ofstream& lhs, Data& rhs);
ostream& operator << (ostream& lhs, Data& rhs);