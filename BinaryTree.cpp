// BinaryTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

struct Node
{
	int m_iData;
	Node *m_ptrLeft = nullptr;
	Node *m_ptrRight = nullptr;

	Node(int iValue) : m_iData(iValue) {}
};

class BTree
{
public:
	Node *m_ptrHead = nullptr;
	void Insert(const int iValue, Node *ptrNode = nullptr);
	void PrintInOrder(Node* ptrNode);
	void PrintPreOrder(Node* ptrNode);
	void PrintPostOrder(Node* ptrNode);
};

//Inorder(Left, Root, Right)
void BTree::PrintInOrder(Node* ptrNode)
{
	if (nullptr == ptrNode)
		return;

	//It depends on where 'cout' statement is. We always print root node. Hence execution revolves around where cout statement is.
	PrintInOrder(ptrNode->m_ptrLeft);
	std::cout << "-> " << ptrNode->m_iData << std::endl;
	PrintInOrder(ptrNode->m_ptrRight);
}

//Preorder(Root, Left, Right)
void BTree::PrintPreOrder(Node* ptrNode)
{
	if (nullptr == ptrNode)
		return;

	//It depends on where 'cout' statement is. We always print root node. Hence execution revolves around where cout statement is.
	std::cout << "-> " << ptrNode->m_iData << std::endl;
	PrintPreOrder(ptrNode->m_ptrLeft);
	PrintPreOrder(ptrNode->m_ptrRight);
}

//Postorder(Left, Right, Root)
void BTree::PrintPostOrder(Node* ptrNode)
{
	if (nullptr == ptrNode)
		return;

	//It depends on where 'cout' statement is. We always print root node. Hence execution revolves around where cout statement is.
	PrintPostOrder(ptrNode->m_ptrLeft);
	PrintPostOrder(ptrNode->m_ptrRight);
	std::cout << "-> " << ptrNode->m_iData << std::endl;
}

void BTree::Insert(const int iValue, Node *ptrNode)
{
	if (nullptr == m_ptrHead)
	{
		m_ptrHead = new Node(iValue);
	}
	else
	{
		if (nullptr == ptrNode)
			ptrNode = m_ptrHead;

		if (iValue > ptrNode->m_iData)
		{
			if (!ptrNode->m_ptrRight)
				ptrNode->m_ptrRight = new Node(iValue);
			else
				Insert(iValue, ptrNode->m_ptrRight);
		}
		else if(iValue < ptrNode->m_iData)
		{
			if (!ptrNode->m_ptrLeft)
				ptrNode->m_ptrLeft = new Node(iValue);
			else
				Insert(iValue, ptrNode->m_ptrLeft);
		}
	}
}

int main()
{
	int iSize = 0;
    std::cout << "Enter number of elements in graph - \n";
	std::cin >> iSize;
	BTree objTree;
	for (int i = 0; i < iSize; i++)
	{
		int iValue = 0;
		std::cin >> iValue;
		objTree.Insert(iValue);
	}
	std::cout << "-------------In-Order----------------------\n";
	objTree.PrintInOrder(objTree.m_ptrHead);
	std::cout << "-------------Pre-Order---------------------\n";
	objTree.PrintPreOrder(objTree.m_ptrHead);
	std::cout << "-------------Post-Order--------------------\n";
	objTree.PrintPostOrder(objTree.m_ptrHead);
	std::cout << "-------------------------------------------\n";
}
