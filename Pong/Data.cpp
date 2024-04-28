#include "Data.hpp"

Data::Data(int& newScore, int& newHits, int& newMisses, string& newPlayerName)
{
	mScore = newScore;
	mHits = newHits;
	mMisses = newMisses;
	mName = newPlayerName;
	if (mHits == 0)
		mAccuracy = 0;
	else
		mAccuracy = ((newHits / (float)(newMisses + newHits)) * 100);
}
Data::Data()
{
	mScore = 0;
	mHits = 0;
	mMisses = 0;
	mName = "";
	mAccuracy = 0;

}

// Getters
int Data::getScore()
{
	return mScore;
}
int Data::getHits()
{
	return mHits;
}
int Data::getMisses()
{
	return mMisses;
}
string Data::getName()
{
	return mName;
}
float Data::getAccuracy()
{
	return mAccuracy;
}

// Setters
void Data::setScore(int& newScore)
{
	mScore = newScore;
}
void Data::setHits(int& newHits)
{
	mHits = newHits;
}
void Data::setMisses(int& newMisses)
{
	mMisses = newMisses;
}
void Data::setName(string& newName)
{
	mName = newName;
}
void Data::setAccuracy(float& newAccuracy)
{
	mAccuracy = newAccuracy;
}

ofstream& operator << (ofstream& lhs, Data& rhs)
{
	lhs << rhs.getName() << "," << rhs.getScore() << "," << rhs.getHits() << ","
		<< rhs.getMisses() << "," << rhs.getAccuracy();
	return lhs;
}

ostream& operator << (ostream& lhs, Data& rhs)
{
	lhs << rhs.getName() << "," << rhs.getScore() << "," << rhs.getHits() << ","
		<< rhs.getMisses() << "," << rhs.getAccuracy();
	return lhs;
}