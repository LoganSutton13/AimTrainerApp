#include "ListNode.hpp"

ListNode::ListNode(Data &newData)
{
	mpData = new Data;
	*mpData = newData;
	mpNext = nullptr;
}

ListNode::~ListNode()
{
	// inside list node destructir
}

void ListNode::setNextPtr(ListNode* newNext)
{
	mpNext = newNext;
}

ListNode* ListNode::getNextPtr()
{
	return mpNext;
}

void ListNode::setData(Data &newData)
{

	*mpData = newData;
}

Data ListNode::getData()
{
	return *mpData;
}