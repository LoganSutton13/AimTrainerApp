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
#include "Data.hpp"

/*
*	Base node class for nodes in List
*	Supports basic node opperations for getting/setting fields
*	Has pure virtual function printData (implemented in derived classes)
*/
class ListNode
{
public:
	// list node constructor
	ListNode(Data &newData);

	// destructor
	~ListNode();

	// sets the next pointer
	void setNextPtr(ListNode* newNext);

	// gets the next pointer
	ListNode* getNextPtr();

	// sets the data in the node
	void setData(Data &newData);

	// returns the data
	Data getData();

	// pure virtual function for printing the data to the outfile
	virtual void printData(ofstream& outfile) = 0; // pure virtual
private:
	Data* mpData;
	ListNode* mpNext;
};