#include "tree.h"
#include <stdexcept>

BinaryTreeNode* ConstructCore(int* startPreOrder, int* endPreOrder,
							  int* startInOrder, int* endInOrder)
{
	int rootValue = startPreOrder[0];
	BinaryTreeNode* root = new BinaryTreeNode();
	root->m_nValue = rootValue;
	root->m_pLeft = root->m_pRight = nullptr;

	if (startPreOrder == endPreOrder){
		if (startInOrder == endInOrder && *startPreOrder == *startInOrder)
			return root;
		else
			throw std::logic_error("Invalid input.");
	}

	int* rootInOrder = startInOrder;
	while (rootInOrder <= endInOrder && *rootInOrder != rootValue)
		++rootInOrder;
	if (rootInOrder == endInOrder && *rootInOrder != rootValue)
		throw std::logic_error("Invalid input");

	int leftLength = rootInOrder - startInOrder;
	int* leftPreOrderstart = startPreOrder + 1;
	int* leftPreOrderEnd = startPreOrder + leftLength;
	if (leftLength > 0)
		root->m_pLeft = ConstructCore(leftPreOrderstart, leftPreOrderEnd,
									  startInOrder, rootInOrder - 1);

	if (leftLength < endPreOrder - startPreOrder)
		root->m_pRight = ConstructCore(leftPreOrderEnd + 1, endPreOrder,
									   rootInOrder + 1, endInOrder);

	return root;
}

BinaryTreeNode* Construct(int* preOrder, int* inOrder, int length)
{
	if (preOrder == nullptr || inOrder == nullptr || length <= 0)
		return nullptr;

	return ConstructCore(preOrder, preOrder + length - 1,
						 inOrder, inOrder + length - 1);
}

int main()
{
	int preOrder[8] = {1,2,4,7,3,5,6,8};
	int inOrder[8] = {4,7,2,1,5,3,8,7};

	Construct(preOrder, inOrder, 8);

	return 0;
}
