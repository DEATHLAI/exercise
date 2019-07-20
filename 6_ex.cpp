#include"list.h"
#include<stack>
#include<iostream>

void PrintListReversingly_iteratively(ListNode* pHead)
{
	std::stack<ListNode*> nodes;

	ListNode* pNode = pHead;
	while (pNode != nullptr){
		nodes.push(pNode);
		pNode = pNode->m_pNext;
	}

	while (!nodes.empty()){
		pNode = nodes.top();
		std::cout << pNode->m_nValue << std::endl;
		nodes.pop();
	}
}

void PrintListReversingly_Recursively(ListNode* pHead)
{
	if (pHead != nullptr){
		if (pHead->m_pNext != nullptr)
			PrintListReversingly_Recursively(pHead->m_pNext);
		std::cout << pHead->m_nValue << std::endl;
	}
}

int main()
{
	ListNode** pHead = new ListNode*;
	addToTail(pHead, 1);
	addToTail(pHead, 2);
	addToTail(pHead, 3);
	addToTail(pHead, 4);
	addToTail(pHead, 5);
	PrintListReversingly_iteratively(*pHead);
	PrintListReversingly_Recursively(*pHead);

	return 0;
}
