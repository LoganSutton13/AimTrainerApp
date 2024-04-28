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

#include "ListNode.hpp"

/*
*	Derived class from ListNode
*	Adds mRank field to represent position in scoreboard
*	Used by List class for storing scoreboards
*	Implements pure virtual function printData
*/
class RankedNode : public ListNode
{
public:
	// ranked node destructor
	~RankedNode() {};

	// ranked node constructor
	RankedNode(Data data, int rank = -1);

	// sets the rank
	void setRank(int rank);

	// prints the data
	void printData(ofstream& outfile);

	// increments the rank of the node
	void incrementRank();

	// returns the rank
	int getrank();
private:
	int mRank;
};