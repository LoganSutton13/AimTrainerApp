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
#include "RankedNode.hpp"
#include "fstream"
using std::cout;
using std::fstream;
using std::ofstream;
using std::ifstream;

/*
*	Stores scoreboard information in dynamic linked list
*	Uses RankedNode to store each score entry (up to 10)
*	Reads and writes to .csv files to store scoreboards
*	Only supports insertInOrder() for adding items to the list
*	Importing and printing remove the need for a removeItem()
*/
class List
{
public:
	List() : mpHead(nullptr) {};

	// list destructor
	~List()
	{
		RankedNode* pTemp;
		while (mpHead != nullptr)
		{
			pTemp = mpHead;
			mpHead = dynamic_cast<RankedNode*>(mpHead->getNextPtr());
			delete pTemp;
		}
	}

	// list copy constructor
	List(List& copy)
	{
		RankedNode* pMemCopy = copy.getHeadPtr(), * pMem = nullptr, * pCur = nullptr;
		if (pMemCopy != nullptr)
		{
			pMem = new RankedNode(pMemCopy->getData());
			this->mpHead = pMem;
			pMem->setNextPtr(nullptr);
			pMemCopy = dynamic_cast<RankedNode*>(pMemCopy->getNextPtr());
			while (pMemCopy != nullptr)
			{
				pCur = pMem;
				pMem = new RankedNode(pMemCopy->getData());
				pCur->setNextPtr(pMem);
				pMem->setNextPtr(nullptr);
				pMemCopy = dynamic_cast<RankedNode*>(pMemCopy->getNextPtr());
			}
		}
	}

	// sets the head pointer
	void setHeadPtr(RankedNode* newHead)
	{
		mpHead = newHead;
	}

	// returns the head pointer
	RankedNode* getHeadPtr()
	{
		return mpHead;
	}

	// inerts the data in order
	void insertInOrder(Data newData)
	{
		RankedNode* pMem = new RankedNode(newData), * pCur = mpHead, * pPrev = nullptr;
		if (pMem != nullptr)
		{
			if (mpHead == nullptr) // empty list
			{
				pMem->setRank(1);
				mpHead = pMem;
			}
			else
			{
				int rank = 1;
				while (pCur != nullptr && pMem->getData().getScore() < pCur->getData().getScore()) // finds the position to enter
				{
					pPrev = pCur;
					// if (pCur->getNextPtr)
					pCur = dynamic_cast<RankedNode*>(pCur->getNextPtr());
					/*if (pCur != nullptr)
					{
						data = pCur->getData();
					}*/
					rank++;
				}
				pMem->setRank(rank);
				if (pPrev != nullptr) // setting the 
				{
					pPrev->setNextPtr(pMem);
				}
				if (pCur != nullptr) // inserting in middle
				{
					pMem->setNextPtr(pCur); // 
				}
				if (pCur != nullptr && pPrev == nullptr) // insert at the front
				{
					mpHead = pMem; // setting 
				}
				incrementRestOfRank(pCur);
				/*else
				{
					pMem->setNextPtr(pCur);
				}*/
			}
		}
	}

	// prints the contents of the list to an outfile
	void printList(ofstream& outfile)
	{
		int i = 0;
		RankedNode* pCur = mpHead;
		while (pCur != nullptr && i < 10)
		{
			pCur->printData(outfile);
			outfile << endl;
			pCur = dynamic_cast<RankedNode*>(pCur->getNextPtr()); // check dynamic cast
			i++;
		}

	}

	// imports the contents of an infile into a list in order
	void importFile(ifstream& infile)
	{
		while (/*!infile.eof()*/infile.peek() != ifstream::traits_type::eof())
		{
			Data data;
			int hits = 0, misses = 0, score = 0, rank = 0;
			float accuracy = 0.0;
			string name = "", accuracyStr = "";
			char temp[100] = "";
			infile.getline(temp, 5, ',');
			rank = atoi(temp);
			infile.getline(temp, 20, ',');
			name = temp;
			data.setName(name); // name
			infile.getline(temp, 5, ',');
			score = atoi(temp);
			data.setScore(score); // score
			infile.getline(temp, 5, ',');
			hits = atoi(temp);
			data.setHits(hits); // hits
			infile.getline(temp, 5, ',');
			misses = atoi(temp);
			data.setMisses(misses); // misses
			infile.getline(temp, 10, '\n');
			accuracyStr = temp;
			accuracy = stof(accuracyStr);
			data.setAccuracy(accuracy); // accuracy
			insertInOrder(data);
		}
	}

	// returns a formatted string with all of the leaderboard data
	string printScoreboardData(void)
	{
		string scoreboard = "";
		RankedNode* pCur = mpHead;
		int count = 0;
		while (pCur != nullptr && count < 10)
		{
			scoreboard = scoreboard + std::to_string(pCur->getrank()) + ". " + pCur->getData().getName() + " | Score: " +
				std::to_string(pCur->getData().getScore()) + '\n';
			pCur = dynamic_cast<RankedNode*>(pCur->getNextPtr());
			count++;
		}
		return scoreboard;
	}
private:
	RankedNode* mpHead; // RankedNode inherits from ListNode

	// increments the rest of rank values
	void incrementRestOfRank(RankedNode* node)
	{
		RankedNode* pTemp = node;
		while (pTemp)
		{
			pTemp->incrementRank();
			pTemp = dynamic_cast<RankedNode*>(pTemp->getNextPtr());
		}
	}
};
