struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
};

void addToTail(ListNode** pHead, int value)
{
	ListNode* pNew = new ListNode();
	pNew->m_pNext = nullptr;
	pNew->m_nValue = value;

	if (*pHead == nullptr){
		*pHead = pNew;
	}
	else{
		ListNode* pNode = *pHead;
		while (pNode->m_pNext != nullptr)
			pNode = pNode->m_pNext;

		pNode->m_pNext = pNew;
	}
}

void RemoveNode(ListNode** pHead, int value)
{
	if (pHead == nullptr || *pHead == nullptr)
		return;
	
	ListNode* pToBeDeleted = nullptr;
	if ((*pHead)->m_nValue == value){
		pToBeDeleted = *pHead;
		*pHead = (*pHead)->m_pNext;
	}
	else{
		ListNode* pNode = *pHead;
		while (pNode->m_pNext != nullptr){
			if (pNode->m_pNext->m_nValue == value){
				pToBeDeleted = pNode->m_pNext;
				pNode->m_pNext = pToBeDeleted->m_pNext;
			}
			else
				pNode = pNode->m_pNext;
		}
	}

	if (pToBeDeleted != nullptr)
	{
		delete pToBeDeleted;
		pToBeDeleted = nullptr;
	}
}

