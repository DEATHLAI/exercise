#include "tree.h"

BinaryTreeNode* getNext(BinaryTreeNode* pNode)
{
	if (pNode == nullptr)
		return nullptr;

	BinaryTreeNode* pNext = nullptr;
	if (pNode->m_pRight != nullptr){
		pNext = pNode->m_pRight;
		while (pNext->m_pLeft != nullptr)
			pNext = pNext->m_pLeft;
	}
	else if (pNode->m_pParent != nullptr){
		BinaryTreeNode* pCurrent = pNode;
		BinaryTreeNode* pParent = pNode->m_pParent;
		while (pParent != nullptr && pCurrent == pParent->m_pRight){
			pCurrent = pParent;
			pParent = pCurrent->m_pParent;
		}

		pNext = pParent;
	}

	return pNext;
}
