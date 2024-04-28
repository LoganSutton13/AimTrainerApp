#include "RankedNode.hpp"

RankedNode::RankedNode(Data data, int rank) : ListNode(data)
{
	mRank = rank;
};

void RankedNode::setRank(int rank)
{
	mRank = rank;
}

void RankedNode::printData(ofstream& outfile)
{
	outfile << mRank << "," << getData();
}

void RankedNode::incrementRank()
{
	mRank++;
}

int RankedNode::getrank()
{
	return mRank;
}